#include <memory>
#include "GlobalSettings.hpp"
#include "MockDevice.hpp"
#include "SingleChannelUartDevice.hpp"
#include "SixteenChannelUartDevice.hpp"


std::vector<std::shared_ptr<IInputDevice>> GlobalSettings::inputDevices = {
	std::shared_ptr<IInputDevice>(new MockDevice),
	std::shared_ptr<IInputDevice>(new SingleChannelUartDevice),
	std::shared_ptr<IInputDevice>(new SixteenChannelUartDevice)
};


std::shared_ptr<IInputDevice> GlobalSettings::inputDevice = inputDevices[0];

int GlobalSettings::samplingInterval_ms = 1000;
int GlobalSettings::dialChannel = 0;
