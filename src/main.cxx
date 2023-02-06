#include <gtkmm.h>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>

#include "MainWindow.hpp"

/*
class MainWindow : public Gtk::Window {
public:
    MainWindow()
	{
	set_title("Zero Mass DAQ");
	set_default_size(800,480);

	std::vector<std::pair<std::string,std::shared_ptr<Gtk::Widget>>>  slides = {
	    {"A", std::shared_ptr<Gtk::Label>(new Gtk::Label("Page A"))},
	    {"B", std::shared_ptr<Gtk::Label>(new Gtk::Label("Page B"))},
	    {"C", std::shared_ptr<Gtk::Label>(new Gtk::Label("Page C"))}
	};

	
	make_slides(slides, 100, 10);
    }
private:

    void showSlide(int i){
	for (auto & label : m_labels)
	{
	    label->hide();
	}
	m_labels[i]->show();
    }
    
    void make_slides(std::vector<std::pair<std::string,std::shared_ptr<Gtk::Widget>>> slides, int buttonSize, int buttonMargins){
	
	m_mainGrid.insert_column(0);
	m_mainGrid.attach(m_sideGrid, 0, 0);
	add(m_mainGrid);

	std::reverse(slides.begin(),slides.end());
	for(const auto & slide : slides)
	{
	    m_buttons.push_back(Gtk::Button(slide.first));
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
	}


	for(int i =0; i<m_buttons.size(); i++)
	{
	    m_buttons[i].signal_clicked().connect(std::bind(&MainWindow::showSlide, this, i));
	}

	m_mainGrid.show();
	m_sideGrid.show();
    }

private:
    Gtk::Grid m_mainGrid;
    Gtk::Grid m_sideGrid;
    std::vector<Gtk::Button> m_buttons;
    std::vector<std::shared_ptr<Gtk::Widget>> m_labels;
};
*/

int main(int argc, char * argv[]) {

    auto app = Gtk::Application::create(argc, argv, "zeroMassDaq.gui");
    
    MainWindow w;
    
    return app->run(w);
}
