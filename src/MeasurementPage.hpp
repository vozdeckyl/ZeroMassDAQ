#ifndef MEASUREMENTPAGE_H
#define MEASUREMENTPAGE_H

#include <memory>
#include <vector>
#include <gtkmm.h>

#include "MockDevice.hpp"
#include "Dial.hpp"

class MeasurementPage : public Gtk::Box {
public:
    MeasurementPage();

private:
    bool updateReadings();
    void startMeasurement();
    void stopMeasurement();
    void showPage(int pageNumber);
    void nextPage();
    void previousPage();
    
private:
    Dial m_dial;
    Gtk::Label m_label;
    Gtk::Grid m_mainLayoutGrid;
    Gtk::Grid m_readingsGrid;
	Gtk::Grid m_dialGrid;
    std::vector<Gtk::Label> m_channelLabels;
    std::vector<Gtk::Label> m_readings;

    Gtk::Grid m_pageSwitchingGrid;
    Gtk::Button m_nextPageButton;
    Gtk::Image m_nextPageImage;
    Gtk::Button m_previousPageButton;
    Gtk::Image m_previousPageImage;
    Gtk::Label m_pageNumberLabel;
    int m_currentPage;
    int m_numberOfPages;
    

    sigc::connection m_conn;

    std::shared_ptr<IInputDevice> m_inputDevice;
};

#endif
