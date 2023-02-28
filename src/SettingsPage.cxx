#include "SettingsPage.hpp"

SettingsPage::SettingsPage()
{
    m_label.set_markup("<span font=\"25\">Settings</span>");
    m_label.set_margin_bottom(20);

	m_mainLayoutGrid.insert_column(0);
    m_mainLayoutGrid.insert_row(0);
    m_mainLayoutGrid.insert_row(0);

    m_mainLayoutGrid.attach(m_label,0,0);
    
    add(m_mainLayoutGrid);

	m_label.show();
	m_mainLayoutGrid.show();
}
