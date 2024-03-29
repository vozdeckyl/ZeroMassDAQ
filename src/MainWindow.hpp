#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <gtkmm.h>

class MainWindow : public Gtk::Window {
public:
    MainWindow(bool makeFullscreen);
    void quit();

private:
    void showSlide(int i);
    void make_slides(std::vector<std::pair<std::shared_ptr<Gtk::Widget>,std::shared_ptr<Gtk::Widget>>> slides, int buttonSize, int buttonMargins);

private:
    Gtk::Grid m_mainGrid;
    Gtk::Grid m_sideGrid;
    std::vector<Gtk::Button> m_buttons;
    std::vector<std::shared_ptr<Gtk::Widget>> m_buttonIcons;
    std::vector<std::shared_ptr<Gtk::Widget>> m_labels;
};

#endif
