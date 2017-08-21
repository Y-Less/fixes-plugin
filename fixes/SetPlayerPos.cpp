#include "../main.hpp"
#include "Defines.hpp"

DECL_FIX(SetPlayerPos);

bool
	FIXES(SetPlayerPos)::
	operator()(int playerid, float x, float y, float z)
{
	Log(LogLevel::DEBUG, "FIXES_SetPlayerPos called");
	int
		ret = SetPlayerPos(playerid, x, y, z),
		index = GetPlayerAnimationIndex(playerid);
	switch (index)
	{
		case 958:
		case 959:
		case 960:
		case 961:
		case 962:
		case 1134:
		{
			int
				slot,
				weapons[_FIXES_WEAPON_SLOTS],
				ammo[_FIXES_WEAPON_SLOTS];
			for (slot = 0; slot < elemsof (weapons); slot++)
			{
				GetPlayerWeaponData(playerid, slot, &weapons[slot], &ammo[slot]);
			}
			weapons[11] = 0;
			ResetPlayerWeapons(playerid);
			for (slot = 0; slot < elemsof (weapons); slot++)
			{
				GivePlayerWeapon(playerid, weapons[slot], ammo[slot]);
			}
		}
	}
	return ret;
}

