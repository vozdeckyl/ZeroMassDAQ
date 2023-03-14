#ifndef GLOBALSETTINGS_H
#define GLOBALSETTINGS_H

#include <memory>
#include <vector>

#include "MockDevice.hpp"

class GlobalSettings {
public:
    static std::shared_ptr<IInputDevice> inputDevice;
	static std::vector<std::shared_ptr<IInputDevice>> inputDevices;
	static int samplingInterval_ms;
	static int dialChannel;
};

#endif
