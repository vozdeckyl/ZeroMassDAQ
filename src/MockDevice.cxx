#include "MockDevice.hpp"


MockDevice::MockDevice()
    : m_normal_dist(25000, 10000)
{    
}

int MockDevice::numberOfChannels()
{
    return 10;
}

std::string MockDevice::deviceName()
{
    return "Device Mock";
}

std::string MockDevice::interfaceDescription()
{
    return "N/A";
}

std::string MockDevice::deviceDescription()
{
    return "The readings are randomly generated numbers";
}

bool MockDevice::connect(std::string& err)
{
    return true;
}

double MockDevice::readChannel(int channel)
{
    if(channel < 0 || channel > 9)
    {
	return 0;
    }
    else
    {
	return m_normal_dist(m_rd);
    }
}

void MockDevice::disconnect()
{
}
