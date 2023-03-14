#include <unistd.h>
#include <string>
#include <vector>
#include "SingleChannelUartDevice.hpp"

#include <iostream>

SingleChannelUartDevice::SingleChannelUartDevice()
  : m_deviceFile("/dev/ttyS0"),
    m_port(m_context)
{    
}

int SingleChannelUartDevice::numberOfChannels()
{
    return 1;
}

std::string SingleChannelUartDevice::deviceName()
{
    return "Single Channel UART";
}

std::string SingleChannelUartDevice::interfaceDescription()
{
    return "UART";
}

std::string SingleChannelUartDevice::deviceDescription()
{
    return "Raspberry Pi Pico counting the number of pulses per second using a single ADC channel.";
}

bool SingleChannelUartDevice::connect(std::string& err)
{
  if (access(m_deviceFile.c_str(), F_OK) == -1)
  {
      err = m_deviceFile + " device doesn't exist.";
      return false;
  }

  try
  {
      m_port = boost::asio::serial_port(m_context, m_deviceFile);
      m_port.set_option(boost::asio::serial_port_base::baud_rate(115200));
  }
  catch (std::exception & e)
  {
      err = "Error: " + std::string(e.what());
      return false;
  }
  
  
  return true;
}

double SingleChannelUartDevice::readChannel(int channel)
{
    if(channel < 0 || channel > 1)
    {
	return 0;
    }
    else
    {
	boost::asio::write(m_port, boost::asio::buffer("\r"));
	std::string inputBuffer;
	boost::asio::read_until(m_port, boost::asio::dynamic_buffer(inputBuffer), '\n');
	
	double countsPerSecond;
	
	std::stringstream ss(inputBuffer);
	std::vector<std::string> elems;
	std::string item;
	while (std::getline(ss, item, ' ')) {
	  elems.push_back(item);
	}
	countsPerSecond = std::atof(elems[2].c_str());
	return countsPerSecond;
    }
}

void SingleChannelUartDevice::disconnect()
{
}
