#include <iostream>
#include "MeasurementPage.hpp"
#include "GlobalSettings.hpp"

MeasurementPage::MeasurementPage(int noOfChannels) :
    m_channelLabels(noOfChannels),
    m_readings(noOfChannels),
    m_inputDevice(GlobalSettings::inputDevice)
{
    //m_inputDevice = GlobalSettings::inputDevice;
    m_label.set_markup("<span font=\"25\">Measurements</span>");
    m_label.set_margin_bottom(20);
    m_mainLayoutGrid.insert_column(0);
    m_mainLayoutGrid.insert_row(0);

    m_mainLayoutGrid.attach(m_label,0,0);
    m_mainLayoutGrid.attach(m_readingsGrid,0,1);
    m_mainLayoutGrid.attach(m_dial,1,1);
    
    add(m_mainLayoutGrid);
    
    m_readingsGrid.insert_column(0);
    m_readingsGrid.insert_column(0);

    for(int i = 0; i < noOfChannels; i++)
    {
        m_readingsGrid.insert_row(0);
    }

    int channelLabelMargins{10};

    int index{0};
    for (auto& label : m_channelLabels)
    {
	label.set_text("Channel " + std::to_string(index));
        m_readingsGrid.attach(label,0,index++);
	label.set_margin_left(channelLabelMargins);
	label.set_margin_right(channelLabelMargins);
        //label.set_margin_top(channelLabelMargins);
        //label.set_margin_bottom(channelLabelMargins);
    }

    index = 0;
    for (auto& reading : m_readings)
    {
	reading.set_markup("<span font=\"12\"><b>N/A</b></span>");
        m_readingsGrid.attach(reading,1,index++);
	reading.set_margin_left(channelLabelMargins);
        reading.set_margin_right(channelLabelMargins);
        //reading.set_margin_top(channelLabelMargins);
        //reading.set_margin_bottom(channelLabelMargins);
    }


    m_label.show();
    m_mainLayoutGrid.show();
    m_readingsGrid.show();
    m_dial.show();

    // start taking readings when measurements page is visible
    signal_show().connect(sigc::mem_fun(*this, &MeasurementPage::startMeasurement));

    // stop updating measurement when this page is hidden
    signal_hide().connect(sigc::mem_fun(*this, &MeasurementPage::stopMeasurement));
}


bool MeasurementPage::updateReadings()
{
	int numberOfChannels = m_inputDevice->numberOfChannels();
	double readings[numberOfChannels];

	for (int i = 0; i < numberOfChannels; i++)
	{
		readings[i] = m_inputDevice->readChannel(i);
	}

	
    for (int i = 0; i < numberOfChannels; i++)
    {
        m_readings[i].set_markup("<span font=\"12\"><b>"+std::to_string(readings[i])+"</b></span>");
    }
	
	if(GlobalSettings::dialChannel == -1)
	{
		double sum{0.0};
		for (int i = 0; i < numberOfChannels; i++)
		{
			sum += readings[i];
		}
		m_dial.setReading(sum);
	}
	else
	{
		m_dial.setReading(readings[GlobalSettings::dialChannel]);
	}
	
	
    return true;
}

void MeasurementPage::startMeasurement()
{
  std::string err;
  bool result = m_inputDevice->connect(err);
  if (!result) std::cout << err << std::endl;

    for(int i=0;i<m_inputDevice->numberOfChannels();i++)
    {
	m_readings[i].show();
	m_channelLabels[i].show();
    }

    updateReadings();
    m_conn = Glib::signal_timeout().connect(sigc::mem_fun(*this,&MeasurementPage::updateReadings),GlobalSettings::samplingInterval_ms);
}

void MeasurementPage::stopMeasurement()
{
    for(int i=0;i<m_inputDevice->numberOfChannels();i++)
    {
	m_readings[i].hide();
	m_channelLabels[i].hide();
    }
    m_conn.disconnect();
}
