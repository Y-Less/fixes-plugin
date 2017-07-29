#include "../main.hpp"
#include "../NATIVES.hpp"

using namespace plugin_natives;

#define _FIXES_WEAPON_SLOTS                     (13)

// In your code:
HOOK_DEFN(fixes, SetPlayerPos, bool(int playerid, float x, float y, float z))
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

