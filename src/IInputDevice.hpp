#ifndef IINPUTDEVICE_H
#define IINPUTDEVICE_H

#include <string>


class IInputDevice {
public:
    virtual int numberOfChannels() = 0;
    virtual std::string deviceName() = 0;
    virtual std::string interfaceDescription() = 0;
    virtual std::string deviceDescription() = 0;
    virtual bool connect(std::string& err) = 0;
    virtual double readChannel(int channel) = 0;
    virtual void disconnect() = 0;
};

#endif
