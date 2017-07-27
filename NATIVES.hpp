#pragma once

#if defined SAMPGDK_CPP_WRAPPERS
	// We don't actually use the `sampgdk` C++ namespace, because otherwise we
	// can't undefine the native function names.  If we did, the names would be
	// in a separate namespace, but it is highly likely that it would have
	// `using`, so would clash anyway.  That's a shame, because otherwise we
	// would not need the `#undef` before each `HOOK_DEFN`.
	#undef SAMPGDK_CPP_WRAPPERS
#endif
#include <sampgdk/a_samp.h>
#include <sampgdk/a_players.h>
#include <sampgdk/a_vehicles.h>
#include <sampgdk/a_objects.h>
#include <sampgdk/a_actor.h>
#include <sampgdk/a_http.h>

#include "src/NativeHook.hpp"
#include "src/NativeFunc.hpp"

//using namespace sampgdk;
using namespace plugin_natives;

#undef SetPlayerPos
HOOK_DEFN(SetPlayerPos, bool(int playerid, float x, float y, float z));

