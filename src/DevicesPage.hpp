#ifndef DEVICESPAGE_H
#define DEVICESPAGE_H

#include <gtkmm.h>

class DevicesPage : public Gtk::Box {
public:
    DevicesPage();

private:
    Gtk::Label m_label;
    Gtk::Grid m_mainLayoutGrid;
};

#endif
