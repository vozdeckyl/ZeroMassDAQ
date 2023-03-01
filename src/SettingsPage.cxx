#include "SettingsPage.hpp"

SettingsPage::SettingsPage() :
    m_adjustment(Gtk::Adjustment::create(1000, 500, 10000, 10, 10, 0))
{
    m_label.set_markup("<span font=\"25\">Settings</span>");
    m_label.set_margin_bottom(20);

	m_scale.set_adjustment(m_adjustment);
	m_scale.set_size_request(600,-1);
	m_scale.set_digits(0);
	
	m_mainLayoutGrid.insert_column(0);
    m_mainLayoutGrid.insert_row(0);
    m_mainLayoutGrid.insert_row(0);
	
    m_mainLayoutGrid.attach(m_label,0,0);
	m_mainLayoutGrid.attach(m_scale,0,1);
	
	
    add(m_mainLayoutGrid);
	
	m_label.show();
	m_scale.show();
	m_mainLayoutGrid.show();
}
