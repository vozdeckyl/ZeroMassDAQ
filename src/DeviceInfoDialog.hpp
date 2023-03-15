#ifndef DEVICEINFODIALOG_H
#define DEVICEINFODIALOG_H

#include <gtkmm.h>
#include "IInputDevice.hpp"

class DeviceInfoDialog : public Gtk::Dialog
{
public:
	DeviceInfoDialog(std::shared_ptr<IInputDevice> device);

private:
	Gtk::Grid m_mainGrid;
	Gtk::Label m_deviceName;
	Gtk::Label m_deviceName_value;
	Gtk::Label m_numberOfChannels;
	Gtk::Label m_numberOfChannels_value;
	Gtk::Button m_okButton;
};

#endif
