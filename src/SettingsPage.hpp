#ifndef SETTINGSPAGE_H
#define SETTINGSPAGE_H

#include <gtkmm.h>

class SettingsPage : public Gtk::Box {
public:
    SettingsPage();
	
private:
    Gtk::Label m_label;
    Gtk::Grid m_mainLayoutGrid;
	Glib::RefPtr<Gtk::Adjustment> m_adjustment;
	Gtk::Scale m_scale;
};

#endif
