#include "SettingsPage.hpp"
#include "GlobalSettings.hpp"

SettingsPage::SettingsPage() :
    m_samplingIntervalAdjustment(Gtk::Adjustment::create(500, 500, 10000, 10, 10, 0))
{
    m_label.set_markup("<span font=\"25\">Settings</span>");
    m_label.set_margin_bottom(20);

	m_samplingIntervalLabel.set_markup("<span font=\"12\">Sampling interval in milliseconds</span>");
	m_samplingIntervalLabel.set_halign(Gtk::Align::ALIGN_START);
	
    m_samplingIntervalAdjustment->signal_value_changed().connect(sigc::mem_fun(*this, &SettingsPage::updateSettings));

	m_samplingIntervalScale.set_adjustment(m_samplingIntervalAdjustment);
	m_samplingIntervalScale.set_size_request(600,-1);
	m_samplingIntervalScale.set_digits(0);
	
	m_mainLayoutGrid.insert_column(0);
    m_mainLayoutGrid.insert_row(0);
    m_mainLayoutGrid.insert_row(0);
	m_mainLayoutGrid.insert_row(0);
	m_mainLayoutGrid.insert_row(0);
	m_mainLayoutGrid.insert_row(0);
	
    m_mainLayoutGrid.attach(m_label,0,0);
	m_mainLayoutGrid.attach(m_samplingIntervalScale,0,2);
	m_mainLayoutGrid.attach(m_samplingIntervalLabel,0,1);
	m_mainLayoutGrid.attach(m_dialChannelLabel,0,3);
	m_mainLayoutGrid.attach(m_ScrolledWindow,0,4);

	m_dialChannelLabel.set_markup("<span font=\"12\">Channel(s) to be displayed on the gauge dial</span>");
	m_dialChannelLabel.set_halign(Gtk::Align::ALIGN_START);
	m_dialChannelLabel.set_margin_top(30);
	m_dialChannelLabel.set_margin_bottom(10);
	
	m_ScrolledWindow.add(m_dialChannelView);
	m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
	m_ScrolledWindow.set_size_request(-1,200);
	
	m_refListStore = Gtk::ListStore::create(m_Columns);

	Gtk::TreeModel::iterator iter = m_refListStore->append();
	Gtk::TreeModel::Row row = *iter;
	row[m_Columns.m_colNumber] = -1;
	row[m_Columns.m_colText] = "Sum of all channels";
	
	int numberOfChannels = GlobalSettings::inputDevice->numberOfChannels();
	for(int i=0; i<numberOfChannels; i++)
	{
		Gtk::TreeModel::iterator iter = m_refListStore->append();
		Gtk::TreeModel::Row row = *iter;
		row[m_Columns.m_colText] = std::to_string(i);
		row[m_Columns.m_colNumber] = i;
	}

    m_dialChannelView.set_model(m_refListStore);

    m_dialChannelView.append_column("Dial Channel", m_Columns.m_colText);
	
	
    add(m_mainLayoutGrid);
	
	m_label.show();
	m_mainLayoutGrid.show();
	m_samplingIntervalScale.show();
	m_samplingIntervalLabel.show();
	m_dialChannelLabel.show();
    m_dialChannelView.show();
	m_ScrolledWindow.show();

	signal_show().connect(sigc::mem_fun(*this, &SettingsPage::loadSettings));
}

void SettingsPage::loadSettings()
{
    m_samplingIntervalAdjustment->set_value(GlobalSettings::samplingInterval_ms);
}

void SettingsPage::updateSettings()
{
	GlobalSettings::samplingInterval_ms = m_samplingIntervalAdjustment->get_value();
}
