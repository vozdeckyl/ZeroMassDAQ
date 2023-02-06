#include <gtkmm.h>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>

#include "MainWindow.hpp"


int main(int argc, char * argv[]) {

    auto app = Gtk::Application::create(argc, argv, "zeroMassDaq.gui");
    
    MainWindow w;
    
    return app->run(w);
}
