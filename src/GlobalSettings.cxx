#include <memory>
#include "GlobalSettings.hpp"
#include "MockDevice.hpp"

std::shared_ptr<IInputDevice> GlobalSettings::inputDevice = std::shared_ptr<IInputDevice>(new MockDevice);
