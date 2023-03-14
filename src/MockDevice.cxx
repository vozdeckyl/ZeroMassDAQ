#include "MockDevice.hpp"


MockDevice::MockDevice()
    : m_normal_dist(25000, 10000)
{    
}

int MockDevice::numberOfChannels()
{
    return 32;
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

void MockDevice::readAllChannels()
{
	for(int i=0; i<32; i++)
	{
		m_readings[i] = m_normal_dist(m_rd);
	}
}

double MockDevice::getChannelReading(int channel)
{
	if(channel < 0 || channel > 31)
    {
		return 0;
    }
    else
    {
		return m_readings[channel];
    }
}

void MockDevice::disconnect()
{
}
