#include "../main.hpp"
#include "../natives.hpp"

DECL_FIX(GetPlayerSkin);

void
	FIXES(GetPlayerSkin)::
	OnPlayerConnect(int playerid)
{
	skin_[playerid] = 0;
}

void
	FIXES(GetPlayerSkin)::
	OnPlayerSpawn(int playerid)
{
	skin_[playerid] = (*GetPlayerSkin)(playerid);
}

void
	FIXES(GetPlayerSkin)::
	Set(int playerid, int skinid)
{
	skin_[playerid] = skinid;
}

int
	FIXES(GetPlayerSkin)::
	Get(int playerid)
{
	return skin_[playerid];
}

