#include "../main.hpp"
#include "../natives.hpp"

DECL_FIX(OnPlayerSpawn);

void
	FIXES(OnPlayerSpawn)::
	OnPlayerSpawn(int playerid)
{
	ResetPlayerMoney(playerid);
	GivePlayerMoney(playerid, cash_[playerid]);
	cash_[playerid] = 0;
}

void
	FIXES(OnPlayerSpawn)::
	OnPlayerConnect(int playerid)
{
	cash_[playerid] = 0;
}

void
	FIXES(OnPlayerSpawn)::
	OnPlayerDeath(int playerid, int killerid, int reason)
{
	// TODO: Need to sort out callback ordering.  We want this called AFTER user
	// code so that the final value is correct.
	cash_[playerid] = GetPlayerMoney(playerid);
}

void
	FIXES(OnPlayerSpawn)::
	operator()(int playerid)
{
	Log(LogLevel::DEBUG, "OnPlayerSpawn::() called");
	cash_[playerid] = GetPlayerMoney(playerid);
}

