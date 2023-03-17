#include <iostream>
#include "MeasurementPage.hpp"
#include "GlobalSettings.hpp"

MeasurementPage::MeasurementPage()
    : m_inputDevice(GlobalSettings::inputDevice),
      m_channelLabels(32),
      m_readings(32),
      m_nextPageButton("⏵"),
      m_previousPageButton("⏴"),
      m_pageNumberLabel("1/2")
{
    m_label.set_markup("<span font=\"25\">Measurements</span>");
    m_label.set_margin_bottom(20);
    m_mainLayoutGrid.insert_column(0);
    m_mainLayoutGrid.insert_row(0);
    m_mainLayoutGrid.insert_row(0);
    
    m_mainLayoutGrid.attach(m_label,0,0);
    m_mainLayoutGrid.attach(m_readingsGrid,0,1);
    m_mainLayoutGrid.attach(m_pageSwitchingGrid,0,2);
    m_mainLayoutGrid.attach(m_dialGrid,1,1);
    
    m_pageSwitchingGrid.insert_column(0);
    m_pageSwitchingGrid.insert_column(0);
    m_pageSwitchingGrid.insert_column(0);
    
    m_pageSwitchingGrid.attach(m_previousPageButton,0,0);
    m_pageSwitchingGrid.attach(m_pageNumberLabel,1,0);
    m_pageSwitchingGrid.attach(m_nextPageButton,2,0);

    m_pageNumberLabel.set_margin_left(10);
    m_pageNumberLabel.set_margin_right(10);
    
    m_dialGrid.insert_column(0);
    m_dialGrid.insert_row(0);
    m_dialGrid.insert_row(0);

    m_dialGrid.attach(m_dial,0,1);
    
    add(m_mainLayoutGrid);
    
    m_readingsGrid.insert_column(0);
    m_readingsGrid.insert_column(0);

    
    for(int i = 0; i < 32; i++)
    {
        m_readingsGrid.insert_row(0);
    }

    int channelLabelMargins{10};

    int index{0};
    for (auto& label : m_channelLabels)
    {
        label.set_text("Channel " + std::to_string(index));
        label.set_halign(Gtk::Align::ALIGN_END);
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
        reading.set_halign(Gtk::Align::ALIGN_START);
        m_readingsGrid.attach(reading,1,index++);
        reading.set_margin_left(channelLabelMargins);
        reading.set_margin_right(channelLabelMargins);
        //reading.set_margin_top(channelLabelMargins);
        //reading.set_margin_bottom(channelLabelMargins);
    }
    
    
    m_label.show();
    m_mainLayoutGrid.show();
    m_readingsGrid.show();
    m_dialGrid.show();
    m_dial.show();
    m_pageSwitchingGrid.show();
    m_nextPageButton.show();
    m_previousPageButton.show();
    m_pageNumberLabel.show();

    // start taking readings when measurements page is visible
    signal_show().connect(sigc::mem_fun(*this, &MeasurementPage::startMeasurement));

    // stop updating measurement when this page is hidden
    signal_hide().connect(sigc::mem_fun(*this, &MeasurementPage::stopMeasurement));
}


bool MeasurementPage::updateReadings()
{
    int numberOfChannels = m_inputDevice->numberOfChannels();
    double readings[numberOfChannels];

    m_inputDevice->readAllChannels();

    for (int i = 0; i < numberOfChannels; i++)
    {
        readings[i] = m_inputDevice->getChannelReading(i);
    }

    for (int i = 0; i < numberOfChannels; i++)
    {
        m_readings[i].set_markup("<span font=\"12\"><b>"+std::to_string(static_cast<int>(readings[i]))+"</b></span>");
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
    m_inputDevice = GlobalSettings::inputDevice;
    std::string err;
    bool result = m_inputDevice->connect(err);
    if (!result) std::cout << err << std::endl;
    
    int channelsToShow = m_inputDevice->numberOfChannels();
    channelsToShow = channelsToShow>16 ? 16 : channelsToShow;
    for(int i=0;i<channelsToShow;i++)
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
    
