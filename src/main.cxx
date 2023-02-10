#include <gtkmm.h>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>

#include "MainWindow.hpp"
#include "MockDevice.hpp"
#include "GlobalSettings.hpp"


int main(int argc, char * argv[]) {

    //GlobalSettings::inputDevice = std::shared_ptr<IInputDevice>(new MockDevice);

    auto app = Gtk::Application::create(argc, argv, "zeroMassDaq.gui");
    
    MainWindow w;
    
    return app->run(w);
}
