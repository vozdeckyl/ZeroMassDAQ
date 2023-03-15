#include "DeviceInfoDialog.hpp"

DeviceInfoDialog::DeviceInfoDialog(std::shared_ptr<IInputDevice> device)
	: Gtk::Dialog("Device Info"),
	  m_okButton("OK"),
	  m_deviceName("Device Name:", Gtk::Align::ALIGN_END, Gtk::Align::ALIGN_START),
	  m_deviceName_value(device->deviceName(), Gtk::Align::ALIGN_START, Gtk::Align::ALIGN_START),
	  m_numberOfChannels("Number of channels:", Gtk::Align::ALIGN_END, Gtk::Align::ALIGN_START),
	  m_numberOfChannels_value(std::to_string(device->numberOfChannels()), Gtk::Align::ALIGN_START, Gtk::Align::ALIGN_START),
	  m_interfaceDescription("Interface:", Gtk::Align::ALIGN_END, Gtk::Align::ALIGN_START),
	  m_interfaceDescription_value(device->interfaceDescription(), Gtk::Align::ALIGN_START, Gtk::Align::ALIGN_START),
	  m_deviceDescription("Device Description:", Gtk::Align::ALIGN_END, Gtk::Align::ALIGN_START),
	  m_deviceDescription_value(device->deviceDescription(), Gtk::Align::ALIGN_START, Gtk::Align::ALIGN_START)
{
	set_type_hint(Gdk::WindowTypeHint::WINDOW_TYPE_HINT_TOOLBAR); //WINDOW_TYPE_HINT_TOOLBAR
	set_icon_from_file("icons/info.png");
	
	m_mainGrid.insert_column(0);
	m_mainGrid.insert_column(0);
	
	m_mainGrid.insert_row(0);
	m_mainGrid.insert_row(0);
	
	m_mainGrid.attach(m_deviceName, 0, 0);
	m_mainGrid.attach(m_deviceName_value, 1, 0);
	
	m_mainGrid.attach(m_numberOfChannels, 0, 1);
	m_mainGrid.attach(m_numberOfChannels_value, 1, 1);
	
	m_mainGrid.attach(m_interfaceDescription, 0, 2);
	m_mainGrid.attach(m_interfaceDescription_value, 1, 2);
	
	m_mainGrid.attach(m_deviceDescription, 0, 3);
	m_mainGrid.attach(m_deviceDescription_value, 1, 3);

	m_deviceDescription_value.set_max_width_chars(30);
	m_deviceDescription_value.set_line_wrap(true);
	
	m_mainGrid.set_margin_left(10);
	m_mainGrid.set_margin_right(10);
	m_mainGrid.set_margin_top(10);
	m_mainGrid.set_margin_bottom(10);
	m_mainGrid.set_row_spacing(10);
	m_mainGrid.set_column_spacing(20);
	
	get_content_area()->add(m_mainGrid);
	m_mainGrid.show();
	
	m_deviceName.show();
	m_deviceName_value.show();
	m_numberOfChannels.show();
	m_numberOfChannels_value.show();
	m_interfaceDescription.show();
	m_interfaceDescription_value.show();
	m_deviceDescription.show();
    m_deviceDescription_value.show();
	
	m_okButton.signal_clicked().connect(sigc::mem_fun(*this, &Gtk::Window::close));
	get_action_area()->add(m_okButton);
	m_okButton.show();
	
	show();
	present();
}
