#include <memory>
#include "GlobalSettings.hpp"
#include "MockDevice.hpp"
#include "SingleChannelUartDevice.hpp"

std::shared_ptr<IInputDevice> GlobalSettings::inputDevice = std::shared_ptr<IInputDevice>(new MockDevice);
//std::shared_ptr<IInputDevice> GlobalSettings::inputDevice = std::shared_ptr<IInputDevice>(new SingleChannelUartDevice);
int GlobalSettings::samplingInterval_ms = 1000;
int GlobalSettings::dialChannel = 0;