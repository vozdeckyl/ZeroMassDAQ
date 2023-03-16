#ifndef EXITPAGE_H
#define EXITPAGE_H

class ExitPage : public Gtk::Box
{
public:
    ExitPage(MainWindow * mainWindow)
        : m_mainWindow(mainWindow)
    {
        signal_show().connect(sigc::mem_fun(m_mainWindow, &Gtk::Window::close));
    }

private:
    MainWindow * m_mainWindow;
};

#endif
