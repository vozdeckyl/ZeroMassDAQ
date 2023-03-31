#include <gtkmm.h>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>

#include "MainWindow.hpp"
#include "MockDevice.hpp"
#include "GlobalSettings.hpp"

#include "config.h"

int main(int argc, char * argv[]) {
    auto app = Gtk::Application::create(argc, argv, "zeroMassDaq.gui");
    MainWindow w(FULLSCREEN);
    return app->run(w);
}
