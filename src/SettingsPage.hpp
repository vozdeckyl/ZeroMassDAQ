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
	Glib::RefPtr<Gtk::Adjustment> m_samplingIntervalAdjustment;
	Gtk::Scale m_samplingIntervalScale;


	Gtk::Label m_dialChannelLabel;
	Gtk::ScrolledWindow m_ScrolledWindow;
	Gtk::TreeView m_dialChannelView;
	//Glib::RefPtr<Gtk::TreeModel> m_dialChannelModel;

	class DialModelColumns : public Gtk::TreeModelColumnRecord
	{
	public:	
	    DialModelColumns()
		{
			add(m_colText);
			add(m_colNumber);
		}
		
		Gtk::TreeModelColumn<Glib::ustring> m_colText;
		Gtk::TreeModelColumn<int> m_colNumber;
	};

    DialModelColumns m_Columns;

	Glib::RefPtr<Gtk::ListStore> m_refListStore;
};

#endif
