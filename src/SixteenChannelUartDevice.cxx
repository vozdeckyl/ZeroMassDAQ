#include <unistd.h>
#include <string>
#include <vector>
#include "SixteenChannelUartDevice.hpp"

#include <iostream>

SixteenChannelUartDevice::SixteenChannelUartDevice()
	: m_deviceFile("/dev/ttyS0"),
	  m_port(m_context)
{    
}

int SixteenChannelUartDevice::numberOfChannels()
{
    return 16;
}

std::string SixteenChannelUartDevice::deviceName()
{
    return "16 Channel UART";
}

std::string SixteenChannelUartDevice::interfaceDescription()
{
    return "UART";
}

std::string SixteenChannelUartDevice::deviceDescription()
{
    return "Raspberry Pi Pico counting the number of pulses per second using the digital IO pins.";
}

bool SixteenChannelUartDevice::connect(std::string& err)
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

double SixteenChannelUartDevice::readChannel(int channel)
{
    if(channel < 0 || channel > 16)
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
		while (std::getline(ss, item, ' '))
		{
			elems.push_back(item);
		}
		countsPerSecond = std::atof(elems[channel].c_str());
		return countsPerSecond;
    }
}

void SixteenChannelUartDevice::disconnect()
{
}
