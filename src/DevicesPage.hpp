#ifndef DEVICESPAGE_H
#define DEVICESPAGE_H

#include <vector>
#include <memory>
#include <gtkmm.h>

class DevicesPage : public Gtk::Box {
public:
    DevicesPage();

private:
	void setDevice(int i);

private:
    Gtk::Label m_label;
    Gtk::Grid m_mainLayoutGrid;
	Gtk::Grid m_deviceTable;
	std::vector<std::shared_ptr<Gtk::Label>> m_labels;
	std::vector<std::shared_ptr<Gtk::RadioButton>> m_radioButtons;
	Gtk::RadioButtonGroup m_buttonGroup;
	
};

#endif
