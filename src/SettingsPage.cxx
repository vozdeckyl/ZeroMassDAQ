#include "SettingsPage.hpp"
#include "GlobalSettings.hpp"

SettingsPage::SettingsPage() :
    m_adjustment(Gtk::Adjustment::create(500, 500, 10000, 10, 10, 0))
{
    m_label.set_markup("<span font=\"25\">Settings</span>");
    m_label.set_margin_bottom(20);

	m_samplingIntervalLabel.set_markup("<span font=\"12\">Sampling interval in milliseconds</span>");
	m_samplingIntervalLabel.set_halign(Gtk::Align::ALIGN_START);
	
	m_adjustment->signal_value_changed().connect(sigc::mem_fun(*this, &SettingsPage::updateSettings));

	m_scale.set_adjustment(m_adjustment);
	m_scale.set_size_request(600,-1);
	m_scale.set_digits(0);
	
	m_mainLayoutGrid.insert_column(0);
    m_mainLayoutGrid.insert_row(0);
    m_mainLayoutGrid.insert_row(0);
	m_mainLayoutGrid.insert_row(0);
	
    m_mainLayoutGrid.attach(m_label,0,0);
	m_mainLayoutGrid.attach(m_scale,0,2);
	m_mainLayoutGrid.attach(m_samplingIntervalLabel,0,1);
	
    add(m_mainLayoutGrid);
	
	m_label.show();
	m_mainLayoutGrid.show();
	m_scale.show();
	m_samplingIntervalLabel.show();

	signal_show().connect(sigc::mem_fun(*this, &SettingsPage::loadSettings));
}

void SettingsPage::loadSettings()
{
	m_adjustment->set_value(GlobalSettings::samplingInterval_ms);
}

void SettingsPage::updateSettings()
{
	GlobalSettings::samplingInterval_ms = m_adjustment->get_value();
}
