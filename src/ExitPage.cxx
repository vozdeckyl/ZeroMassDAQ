#include "ExitPage.hpp"

ExitPage::ExitPage(MainWindow * mainWindow)
    : m_mainWindow(mainWindow)
{
    signal_show().connect(sigc::mem_fun(m_mainWindow, &Gtk::Window::close));
}
