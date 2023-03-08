#ifndef MEASUREMENTPAGE_H
#define MEASUREMENTPAGE_H

#include <memory>
#include <vector>
#include <gtkmm.h>

#include "MockDevice.hpp"
#include "Dial.hpp"

class MeasurementPage : public Gtk::Box {
public:
    MeasurementPage(int noOfChannels);

private:
    bool updateReadings();
    void startMeasurement();
    void stopMeasurement();
    
private:
    Dial m_dial;
    Gtk::Label m_label;
    Gtk::Grid m_mainLayoutGrid;
    Gtk::Grid m_readingsGrid;
	Gtk::Grid m_dialGrid;
	Gtk::ScrolledWindow m_readingsWindow;
    std::vector<Gtk::Label> m_channelLabels;
    std::vector<Gtk::Label> m_readings;

    sigc::connection m_conn;

    std::shared_ptr<IInputDevice> m_inputDevice;
};

#endif
