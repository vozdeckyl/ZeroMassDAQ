#ifndef SINGLECHANNELUARTDEVICE_H
#define SINGLECHANNELUARTDEVICE_H

#include <string>
#include <boost/asio.hpp>

#include "IInputDevice.hpp"

class SingleChannelUartDevice : public IInputDevice {
public:
    SingleChannelUartDevice();

    int numberOfChannels() override;
    std::string deviceName() override;
    std::string interfaceDescription() override;
    std::string deviceDescription() override;
    bool connect(std::string& err) override;
	void readAllChannels() override;
	double getChannelReading(int channel) override;
    void disconnect() override;

private:
	double m_reading;
    std::string m_deviceFile;
    boost::asio::io_context m_context;
    boost::asio::serial_port m_port;
};

#endif
