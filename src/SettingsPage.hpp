#ifndef SETTINGSPAGE_H
#define SETTINGSPAGE_H

#include <gtkmm.h>

class SettingsPage : public Gtk::Box {
public:
    SettingsPage();

private:
	void updateSettings();
	void loadSettings();
		
private:
    Gtk::Label m_label;
    Gtk::Grid m_mainLayoutGrid;

	Gtk::Label m_samplingIntervalLabel;
	Glib::RefPtr<Gtk::Adjustment> m_adjustment;
	Gtk::Scale m_scale;
};

#endif
