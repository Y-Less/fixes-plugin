#include "../main.hpp"
#include "../natives.hpp"

DECL_FIX(SetPlayerSkin);

void
	FIXES(SetPlayerSkin)::
	operator()(int playerid, int skinid)
{
	int
		vehicleid = GetPlayerVehicleID(playerid);
	if (vehicleid)
	{
		int
			seat = GetPlayerVehicleSeat(playerid);
		ClearAnimations(playerid, 1);
		int
			ret = SetPlayerSkin(playerid, skinid);
		PutPlayerInVehicle(playerid, vehicleid, seat);
		// TODO: Driveby fix (might be handled by the native call).
		return ret;
	}
	return SetPlayerSkin(playerid, skinid);
}

