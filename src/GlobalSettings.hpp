#ifndef GLOBALSETTINGS_H
#define GLOBALSETTINGS_H

#include <memory>

#include "MockDevice.hpp"

class GlobalSettings {
public:
    static std::shared_ptr<IInputDevice> inputDevice;
	static int samplingInterval_ms;
	static int dialChannel;
};

#endif
