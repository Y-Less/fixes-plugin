#pragma once

#if defined SAMPGDK_CPP_WRAPPERS
	// We don't actually use the `sampgdk` C++ namespace, because otherwise we
	// can't undefine the native function names.  If we did, the names would be
	// in a separate namespace, but it is highly likely that it would have
	// `using`, so would clash anyway.  That's a shame, because otherwise we
	// would not need the `#undef` before each `HOOK_DECL`.
	#undef SAMPGDK_CPP_WRAPPERS
#endif
#include <sampgdk/a_samp.h>
#include <sampgdk/a_players.h>
#include <sampgdk/a_vehicles.h>
#include <sampgdk/a_objects.h>
#include <sampgdk/a_actor.h>
#include <sampgdk/a_http.h>

#define LOG_NATIVE_ERROR(...)   Log(LogLevel::ERROR, __VA_ARGS__)
#define LOG_NATIVE_WARNING(...) Log(LogLevel::WARNING, __VA_ARGS__)
#define LOG_NATIVE_DEBUG(...)   Log(LogLevel::DEBUG, __VA_ARGS__)
#define LOG_NATIVE_INFO(...)    Log(LogLevel::INFO, __VA_ARGS__)

#include <plugin-natives/NativeHook.hpp>
#include <plugin-natives/NativeFunc.hpp>

namespace fixes
{
};

using namespace fixes;

