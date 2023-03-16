#include "MainWindow.hpp"
#include "MeasurementPage.hpp"
#include "SettingsPage.hpp"
#include "DevicesPage.hpp"
#include "ExitPage.hpp"

MainWindow::MainWindow()
{
    set_title("Zero Mass DAQ");
    set_default_size(800,480);

    std::vector<std::pair<std::shared_ptr<Gtk::Widget>,std::shared_ptr<Gtk::Widget>>>  slides = {
        {std::shared_ptr<Gtk::Image>(new Gtk::Image("icons/measurement.png")), std::shared_ptr<MeasurementPage>(new MeasurementPage(32))},
        {std::shared_ptr<Gtk::Image>(new Gtk::Image("icons/settings.png")), std::shared_ptr<SettingsPage>(new SettingsPage())},
        {std::shared_ptr<Gtk::Image>(new Gtk::Image("icons/inputDevice.png")), std::shared_ptr<DevicesPage>(new DevicesPage)},
        {std::shared_ptr<Gtk::Label>(new Gtk::Label("Exit")), std::shared_ptr<ExitPage>(new ExitPage(this))}
    };
        
    make_slides(slides, 100, 10);
}

void MainWindow::quit()
{
    close();
}


void MainWindow::showSlide(int i)
{
    for (auto & label : m_labels)
    {
        label->hide();
    }
    m_labels[i]->show();
}
    
void MainWindow::make_slides(std::vector<std::pair<std::shared_ptr<Gtk::Widget>,std::shared_ptr<Gtk::Widget>>> slides, int buttonSize, int buttonMargins)
{    
    m_mainGrid.insert_column(0);
    m_mainGrid.attach(m_sideGrid, 0, 0);
    add(m_mainGrid);
    
    std::reverse(slides.begin(),slides.end());
    for(auto& slide : slides)
    {
        m_buttons.push_back(Gtk::Button());
        m_buttonIcons.push_back(slide.first);
        m_buttons.back().set_image(*slide.first);
        slide.first->show();
        m_sideGrid.insert_row(0);
        m_sideGrid.attach(m_buttons.back(), 0, 0);
    }
    
    for(auto & button : m_buttons)
    {
        button.set_size_request(buttonSize,buttonSize);
        button.set_margin_left(buttonMargins);
        button.set_margin_right(buttonMargins);
        button.set_margin_top(buttonMargins);
        button.set_margin_bottom(buttonMargins);
        button.show();
    }
    
    for(auto & slide : slides)
    {
        m_labels.push_back(slide.second);
    }
    
    
    for (auto & label : m_labels)
    {
        m_mainGrid.attach(*label, 1, 0);
        label->set_margin_left(50);
    }
    
    
    for(int i =0; i<m_buttons.size(); i++)
    {
        m_buttons[i].signal_clicked().connect(std::bind(&MainWindow::showSlide, this, i));
    }
    
    m_mainGrid.show();
    m_sideGrid.show();
}
