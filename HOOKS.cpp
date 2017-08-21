#pragma once

#undef SetPlayerPos
PLUGIN_HOOK(fixes, SetPlayerPos, bool(int playerid, float x, float y, float z))
{
	RETURN_FIX(SetPlayerPos)(playerid, x, y, z);
	return SetPlayerPos(playerid, x, y, z);
}

#undef SpawnPlayer
PLUGIN_HOOK(fixes, SpawnPlayer, bool(int playerid))
{
	TRY_FIX(SpawnPlayer)(playerid);
	TRY_FIX(OnPlayerSpawn)(playerid);
	return SpawnPlayer(playerid);
}

