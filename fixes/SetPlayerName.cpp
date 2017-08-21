#include "../main.hpp"
#include "../natives.hpp"

DECL_FIX(SetPlayerName);

static const char
	FIXES_TEMP_NAME[] = "FIXES_TEMP_NAME";

void
	FIXES(SetPlayerName)::
	OnPlayerConnect(int playerid)
{
	// We can't have people joining the server with this name.  If they do it
	// will mess up the fix.  We could use characters that can't be chosen for a
	// name (though with YSF there's no guarantee of that), but instead just use
	// a well defined string (that has been in fixes.inc for years and never
	// complained about).
	char
		name[MAX_PLAYER_NAME];
	GetPlayerName(playerid, name, MAX_PLAYER_NAME);
	if (strcmp(name, FIXES_TEMP_NAME) == 0)
	{
		Kick(playerid);
	}
}

int
	FIXES(SetPlayerName)::
	operator()(int playerid, char const * name)
{
	if (IsNull(name))
	{
		// Don't set a name to nothing.
		return 0;
	}
	char
		oldName[MAX_PLAYER_NAME];
	GetPlayerName(playerid, oldName, MAX_PLAYER_NAME);
	if (strcmp(name, oldName) == 0)
	{
		// The names are identical.
		return 0;
	}
	if (stricmp(name, oldName) == 0)
	{
		// The names are similar.
		SetPlayerName(playerid, FIXES_TEMP_NAME);
		if (SetPlayerName(playerid, name) == -1)
		{
			// Setting the new name failed, fall back.
			SetPlayerName(playerid, oldName);
			return -1;
		}
		return 1;
	}
	return SetPlayerName(playerid, name);
}

