#ifndef MOCKDEVICE_H
#define MOCKDEVICE_H

#include <string>
#include <random>

#include "IInputDevice.hpp"

class MockDevice : public IInputDevice {
public:
    MockDevice();

    int numberOfChannels() override;
    std::string deviceName() override;
    std::string interfaceDescription() override;
    std::string deviceDescription() override;
    bool connect(std::string& err) override;
	void readAllChannels() override;
	double getChannelReading(int channel) override;
    void disconnect() override;

private:
	double m_readings[32];
    std::random_device m_rd;
    std::normal_distribution<double> m_normal_dist;
};

#endif
