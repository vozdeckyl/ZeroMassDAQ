#ifndef EXITPAGE_H
#define EXITPAGE_H

class ExitPage : public Gtk::Box
{
public:
    ExitPage(std::shared_ptr<MainWindow> mainWindow)
        : m_mainWindow(mainWindow)
    {
        signal_show().connect([](){});
    }

private:
    std::shared_ptr<MainWindow> m_mainWindow;
};

#endif
