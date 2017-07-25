#pragma once

#include <samplog/PluginLogger.h>

using samplog::LogLevel;
extern samplog::CPluginLogger
	Log;

// C++ guidelines say that custom types should not end with "_t", because that
// suffix is reserved for future standardised types.  Tell me a better suffix
// then and I'll use that instead...  In general, I would make types lower-
// case, variables camel-case, and functions pascal-case.  "logprintf" and
// "logprintf_t" are exceptions to this, since they are so prevalent in SA:MP.
typedef void (* logprintf_t)(char const * format, ...);
extern logprintf_t
	logprintf;

#define elemsof(array) (sizeof (array) / sizeof ((array)[0]))

// Include all the `extern` declarations for the fix information.
#include "src/DeclaredFix.hpp"

// Include all the hooked natives.
#include "src/NativeHook.hpp"

