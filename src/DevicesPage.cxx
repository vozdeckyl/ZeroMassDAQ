#include "DevicesPage.hpp"
#include "GlobalSettings.hpp"

#include <functional>

DevicesPage::DevicesPage()
{
    m_label.set_markup("<span font=\"25\">Devices</span>");
    m_label.set_margin_bottom(20);
	
	m_mainLayoutGrid.insert_row(0);
	m_mainLayoutGrid.insert_row(0);
	
	m_deviceTable.insert_column(0);
	m_deviceTable.insert_column(0);
	
	m_deviceTable.set_row_spacing(10);
	m_deviceTable.set_column_spacing(10);
	
	int index{0};
	for(auto device : GlobalSettings::inputDevices)
	{
		m_deviceTable.insert_row(index);
		
		m_labels.push_back(std::shared_ptr<Gtk::Label>(new Gtk::Label(device->deviceName())));
		m_labels.back()->show();
		m_labels.back()->set_halign(Gtk::Align::ALIGN_START);
		m_deviceTable.attach(*(m_labels.back()),1,index);
		
		m_radioButtons.push_back(std::shared_ptr<Gtk::RadioButton>(new Gtk::RadioButton));
		m_radioButtons.back()->show();
		m_radioButtons.back()->set_size_request(30,30);
		m_radioButtons.back()->set_group(m_buttonGroup);
		m_radioButtons.back()->signal_pressed().connect(std::bind(&DevicesPage::setDevice,this,index));
		m_deviceTable.attach(*(m_radioButtons.back()),0,index);
		index++;
	}
	
	m_mainLayoutGrid.attach(m_label,0,0);
	m_mainLayoutGrid.attach(m_deviceTable,0,1);
	
	
	add(m_mainLayoutGrid);
	
	m_deviceTable.show();
	m_mainLayoutGrid.show();
	m_label.show();
}

void DevicesPage::setDevice(int i)
{
	GlobalSettings::inputDevice->disconnect();
	GlobalSettings::inputDevice = GlobalSettings::inputDevices[i];
	std::string err;
	GlobalSettings::inputDevice->connect(err);
	if(err.size()!=0)
	{
		Gtk::MessageDialog dialog("Error connecting device");
		dialog.set_secondary_text(err + "\n\n Did you make sure the device is connected properly?");
		dialog.run();
	}
}
