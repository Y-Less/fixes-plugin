//#include <sampgdk/a_objects.h>
//#include <sampgdk/a_players.h>
//#include <sampgdk/a_samp.h>
//#include <sampgdk/a_vehicles.h>
#include <sampgdk/core.h>
#include <sampgdk/sdk.h>

// Put the variables in this file's namespace.
#define DEFINE_FIX(name,comments) \
	DeclaredFix<FIXES_CHECK_DEFINED_(name)> const FIX_##name##_(fix_description_s {} comments )

#include "main.hpp"
#include "NATIVES.hpp"
#include <plugin-natives/NativesMain.hpp>

samplog::CPluginLogger
	Log("fixes-plugin");

// In your header:
NATIVE_DECL(fixes, SetPlayerPosAndAngle, bool(int playerid, float x, float y, float z, float a));

// In your code:
NATIVE_DEFN(fixes, SetPlayerPosAndAngle, bool(int playerid, float x, float y, float z, float a))
{
	// Implementation here...
	//(*SetPlayerPos)(playerid, x, y, z);
	SetPlayerPos(playerid, x, y, z);
	return SetPlayerFacingAngle(playerid, a);
}

extern void *
	pAMXFunctions;

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports() {
	return sampgdk::Supports() | SUPPORTS_AMX_NATIVES | SUPPORTS_PROCESS_TICK;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData) {
	pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
	samplog::Init();
	Log.SetLogLevel(LogLevel::DEBUG | LogLevel::ERROR | LogLevel::INFO | LogLevel::WARNING);
	return sampgdk::Load(ppData);
}

PLUGIN_EXPORT void PLUGIN_CALL Unload() {
	samplog::Exit();
}

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX *amx)
{
	return plugin_natives::AmxLoad(amx);
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX *amx) {
	return AMX_ERR_NONE;
}

PLUGIN_EXPORT void PLUGIN_CALL ProcessTick() {
	sampgdk::ProcessTick();
}

