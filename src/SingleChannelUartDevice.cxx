#include <unistd.h>
#include <string>
#include <vector>
#include <regex>
#include "SingleChannelUartDevice.hpp"


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

  // request a reading and verify the format of the message
  std::regex regex("[0-9]*\\.[0-9]*");

  boost::asio::write(m_port, boost::asio::buffer("\r"));
  std::string inputBuffer;
  boost::asio::read_until(m_port, boost::asio::dynamic_buffer(inputBuffer), '\n');
  
  std::stringstream ss(inputBuffer);
  std::vector<std::string> elems;
  std::string item;
  while (std::getline(ss, item, ' ')) {
      elems.push_back(item);
  }

  elems.pop_back();

  for(auto & e : elems)
  {
     if(!std::regex_match(e,regex))
     {
         err = "Error: the data sent by the device is not in the expected format.";
         return false;
     }
  }
  
  if(elems.size()!=numberOfChannels())
  {
      err = "Error: the data sent by the device is not in the expected format.";
      return false;
  }
  
  return true;
}


void SingleChannelUartDevice::readAllChannels()
{
	boost::asio::write(m_port, boost::asio::buffer("\r"));
	std::string inputBuffer;
	boost::asio::read_until(m_port, boost::asio::dynamic_buffer(inputBuffer), '\n');
	
	std::stringstream ss(inputBuffer);
	std::vector<std::string> elems;
	std::string item;
	while (std::getline(ss, item, ' ')) {
	  elems.push_back(item);
	}
    m_reading = std::atof(elems[0].c_str());
}

double SingleChannelUartDevice::getChannelReading(int channel)
{
	if(channel < 0 || channel > 1)
    {
		return 0;
    }
    else
    {
		return m_reading;
    }
}

void SingleChannelUartDevice::disconnect()
{
}
