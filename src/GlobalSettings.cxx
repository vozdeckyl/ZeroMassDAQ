#include <memory>
#include "GlobalSettings.hpp"
#include "MockDevice.hpp"
#include "SingleChannelUartDevice.hpp"
#include "SixteenChannelUartDevice.hpp"

std::shared_ptr<IInputDevice> GlobalSettings::inputDevice = std::shared_ptr<IInputDevice>(new MockDevice);
//std::shared_ptr<IInputDevice> GlobalSettings::inputDevice = std::shared_ptr<IInputDevice>(new SingleChannelUartDevice);
//std::shared_ptr<IInputDevice> GlobalSettings::inputDevice = std::shared_ptr<IInputDevice>(new SixteenChannelUartDevice);

int GlobalSettings::samplingInterval_ms = 1000;
int GlobalSettings::dialChannel = 0;
