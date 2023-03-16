#ifndef EXITPAGE_H
#define EXITPAGE_H

#include "MainWindow.hpp"
#include <gtkmm.h>


class ExitPage : public Gtk::Box
{
public:
    ExitPage(MainWindow * mainWindow);

private:
    MainWindow * m_mainWindow;
};

#endif
