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
    double readChannel(int channel) override;
    void disconnect() override;

private:
    std::string m_deviceFile;
    boost::asio::io_context m_context;
    boost::asio::serial_port m_port;
};

#endif
