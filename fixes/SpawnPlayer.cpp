#include "../main.hpp"
#include "../natives.hpp"

DECL_FIX(SpawnPlayer);

void
	FIXES(SpawnPlayer)::
	operator()(int playerid)
{
	Log(LogLevel::DEBUG, "SpawnPlayer::() called");
	int
		vid = GetPlayerVehicleID(playerid);
	if (vid)
	{
		float
			x,
			y,
			z;
		// Remove them without the animation.
		GetVehiclePos(vid, &x, &y, &z);
		SetPlayerPos(playerid, x, y, z);
	}
}

