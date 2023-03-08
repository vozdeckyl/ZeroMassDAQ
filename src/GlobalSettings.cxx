#include <memory>
#include "GlobalSettings.hpp"
#include "MockDevice.hpp"

std::shared_ptr<IInputDevice> GlobalSettings::inputDevice = std::shared_ptr<IInputDevice>(new MockDevice);
int GlobalSettings::samplingInterval_ms = 1000;
int GlobalSettings::dialChannel = 0;
