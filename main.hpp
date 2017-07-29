#pragma once

#include <samplog/PluginLogger.h>
#include <sampgdk/core.h>

using samplog::LogLevel;
extern samplog::CPluginLogger
	Log;

// Just import one that already exists.
using sampgdk::logprintf;

#define elemsof(array) (sizeof (array) / sizeof ((array)[0]))

// Include all the `extern` declarations for the fix information.
//#include "src/DeclaredFix.hpp"

// Include all the hooked natives.

