#ifndef SAMPGDK_A_SAMP_H
#define SAMPGDK_A_SAMP_H

#include <sampgdk/bool.h>
#include <sampgdk/export.h>
#include <sampgdk/types.h>

#define MAX_PLAYER_NAME (24)
#define MAX_CLIENT_MESSAGE (144)
#define MAX_PLAYERS (1000)
#define MAX_VEHICLES (2000)
#define MAX_ACTORS (1000)
#define INVALID_PLAYER_ID (0xFFFF)
#define INVALID_VEHICLE_ID (0xFFFF)
#define INVALID_ACTOR_ID (0xFFFF)
#define NO_TEAM (255)
#define MAX_OBJECTS (1000)
#define INVALID_OBJECT_ID (0xFFFF)
#define MAX_GANG_ZONES (1024)
#define MAX_TEXT_DRAWS (2048)
#define MAX_PLAYER_TEXT_DRAWS (256)
#define MAX_MENUS (128)
#define MAX_3DTEXT_GLOBAL (1024)
#define MAX_3DTEXT_PLAYER (1024)
#define MAX_PICKUPS (4096)
#define INVALID_MENU (0xFF)
#define INVALID_TEXT_DRAW (0xFFFF)
#define INVALID_GANG_ZONE (-1)
#define INVALID_3DTEXT_ID (0xFFFF)
#define SERVER_VARTYPE_NONE (0)
#define SERVER_VARTYPE_INT (1)
#define SERVER_VARTYPE_STRING (2)
#define SERVER_VARTYPE_FLOAT (3)
#define TEXT_DRAW_FONT_SPRITE_DRAW (4)
#define TEXT_DRAW_FONT_MODEL_PREVIEW (5)
#define DIALOG_STYLE_MSGBOX (0)
#define DIALOG_STYLE_INPUT (1)
#define DIALOG_STYLE_LIST (2)
#define DIALOG_STYLE_PASSWORD (3)
#define DIALOG_STYLE_TABLIST (4)
#define DIALOG_STYLE_TABLIST_HEADERS (5)
#define PLAYER_STATE_NONE (0)
#define PLAYER_STATE_ONFOOT (1)
#define PLAYER_STATE_DRIVER (2)
#define PLAYER_STATE_PASSENGER (3)
#define PLAYER_STATE_EXIT_VEHICLE (4)
#define PLAYER_STATE_ENTER_VEHICLE_DRIVER (5)
#define PLAYER_STATE_ENTER_VEHICLE_PASSENGER (6)
#define PLAYER_STATE_WASTED (7)
#define PLAYER_STATE_SPAWNED (8)
#define PLAYER_STATE_SPECTATING (9)
#define PLAYER_MARKERS_MODE_OFF (0)
#define PLAYER_MARKERS_MODE_GLOBAL (1)
#define PLAYER_MARKERS_MODE_STREAMED (2)
#define WEAPON_BRASSKNUCKLE (1)
#define WEAPON_GOLFCLUB (2)
#define WEAPON_NITESTICK (3)
#define WEAPON_KNIFE (4)
#define WEAPON_BAT (5)
#define WEAPON_SHOVEL (6)
#define WEAPON_POOLSTICK (7)
#define WEAPON_KATANA (8)
#define WEAPON_CHAINSAW (9)
#define WEAPON_DILDO (10)
#define WEAPON_DILDO2 (11)
#define WEAPON_VIBRATOR (12)
#define WEAPON_VIBRATOR2 (13)
#define WEAPON_FLOWER (14)
#define WEAPON_CANE (15)
#define WEAPON_GRENADE (16)
#define WEAPON_TEARGAS (17)
#define WEAPON_MOLTOV (18)
#define WEAPON_COLT45 (22)
#define WEAPON_SILENCED (23)
#define WEAPON_DEAGLE (24)
#define WEAPON_SHOTGUN (25)
#define WEAPON_SAWEDOFF (26)
#define WEAPON_SHOTGSPA (27)
#define WEAPON_UZI (28)
#define WEAPON_MP5 (29)
#define WEAPON_AK47 (30)
#define WEAPON_M4 (31)
#define WEAPON_TEC9 (32)
#define WEAPON_RIFLE (33)
#define WEAPON_SNIPER (34)
#define WEAPON_ROCKETLAUNCHER (35)
#define WEAPON_HEATSEEKER (36)
#define WEAPON_FLAMETHROWER (37)
#define WEAPON_MINIGUN (38)
#define WEAPON_SATCHEL (39)
#define WEAPON_BOMB (40)
#define WEAPON_SPRAYCAN (41)
#define WEAPON_FIREEXTINGUISHER (42)
#define WEAPON_CAMERA (43)
#define WEAPON_NIGHTVISION (44)
#define WEAPON_INFRARED (45)
#define WEAPON_PARACHUTE (46)
#define WEAPON_VEHICLE (49)
#define WEAPON_DROWN (53)
#define WEAPON_COLLISION (54)
#define KEY_ACTION (1)
#define KEY_CROUCH (2)
#define KEY_FIRE (4)
#define KEY_SPRINT (8)
#define KEY_SECONDARY_ATTACK (16)
#define KEY_JUMP (32)
#define KEY_LOOK_RIGHT (64)
#define KEY_HANDBRAKE (128)
#define KEY_LOOK_LEFT (256)
#define KEY_SUBMISSION (512)
#define KEY_LOOK_BEHIND (512)
#define KEY_WALK (1024)
#define KEY_ANALOG_UP (2048)
#define KEY_ANALOG_DOWN (4096)
#define KEY_ANALOG_LEFT (8192)
#define KEY_ANALOG_RIGHT (16384)
#define KEY_YES (65536)
#define KEY_NO (131072)
#define KEY_CTRL_BACK (262144)
#define KEY_UP (-128)
#define KEY_DOWN (128)
#define KEY_LEFT (-128)
#define KEY_RIGHT (128)
#define BODY_PART_TORSO (3)
#define BODY_PART_GROIN (4)
#define BODY_PART_LEFT_ARM (5)
#define BODY_PART_RIGHT_ARM (6)
#define BODY_PART_LEFT_LEG (7)
#define BODY_PART_RIGHT_LEG (8)
#define BODY_PART_HEAD (9)
#define CLICK_SOURCE_SCOREBOARD (0)
#define EDIT_RESPONSE_CANCEL (0)
#define EDIT_RESPONSE_FINAL (1)
#define EDIT_RESPONSE_UPDATE (2)
#define SELECT_OBJECT_GLOBAL_OBJECT (1)
#define SELECT_OBJECT_PLAYER_OBJECT (2)
#define BULLET_HIT_TYPE_NONE (0)
#define BULLET_HIT_TYPE_PLAYER (1)
#define BULLET_HIT_TYPE_VEHICLE (2)
#define BULLET_HIT_TYPE_OBJECT (3)
#define BULLET_HIT_TYPE_PLAYER_OBJECT (4)

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SendClientMessage">SendClientMessage on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SendClientMessage(int playerid, int color, const char * message));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SendClientMessageToAll">SendClientMessageToAll on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SendClientMessageToAll(int color, const char * message));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SendPlayerMessageToPlayer">SendPlayerMessageToPlayer on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SendPlayerMessageToPlayer(int playerid, int senderid, const char * message));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SendPlayerMessageToAll">SendPlayerMessageToAll on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SendPlayerMessageToAll(int senderid, const char * message));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SendDeathMessage">SendDeathMessage on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SendDeathMessage(int killer, int killee, int weapon));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SendDeathMessageToPlayer">SendDeathMessageToPlayer on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SendDeathMessageToPlayer(int playerid, int killer, int killee, int weapon));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GameTextForAll">GameTextForAll on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GameTextForAll(const char * text, int time, int style));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GameTextForPlayer">GameTextForPlayer on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GameTextForPlayer(int playerid, const char * text, int time, int style));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetTickCount">GetTickCount on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, GetTickCount());

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetMaxPlayers">GetMaxPlayers on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, GetMaxPlayers());

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/VectorSize">VectorSize on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(float, VectorSize(float x, float y, float z));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetPlayerPoolSize">GetPlayerPoolSize on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, GetPlayerPoolSize());

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetVehiclePoolSize">GetVehiclePoolSize on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, GetVehiclePoolSize());

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetActorPoolSize">GetActorPoolSize on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, GetActorPoolSize());

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SHA256_PassHash">SHA256_PassHash on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SHA256_PassHash(const char * password, const char * salt, char * ret_hash, int ret_hash_len));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetSVarInt">SetSVarInt on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetSVarInt(const char * varname, int int_value));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetSVarInt">GetSVarInt on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, GetSVarInt(const char * varname));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetSVarString">SetSVarString on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetSVarString(const char * varname, const char * string_value));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetSVarString">GetSVarString on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GetSVarString(const char * varname, char * string_return, int len));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetSVarFloat">SetSVarFloat on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetSVarFloat(const char * varname, float float_value));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetSVarFloat">GetSVarFloat on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(float, GetSVarFloat(const char * varname));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/DeleteSVar">DeleteSVar on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, DeleteSVar(const char * varname));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetSVarsUpperIndex">GetSVarsUpperIndex on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, GetSVarsUpperIndex());

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetSVarNameAtIndex">GetSVarNameAtIndex on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GetSVarNameAtIndex(int index, char * ret_varname, int ret_len));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetSVarType">GetSVarType on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, GetSVarType(const char * varname));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetGameModeText">SetGameModeText on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetGameModeText(const char * text));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetTeamCount">SetTeamCount on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetTeamCount(int count));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/AddPlayerClass">AddPlayerClass on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, AddPlayerClass(int modelid, float spawn_x, float spawn_y, float spawn_z, float z_angle, int weapon1, int weapon1_ammo, int weapon2, int weapon2_ammo, int weapon3, int weapon3_ammo));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/AddPlayerClassEx">AddPlayerClassEx on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, AddPlayerClassEx(int teamid, int modelid, float spawn_x, float spawn_y, float spawn_z, float z_angle, int weapon1, int weapon1_ammo, int weapon2, int weapon2_ammo, int weapon3, int weapon3_ammo));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/AddStaticVehicle">AddStaticVehicle on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, AddStaticVehicle(int modelid, float spawn_x, float spawn_y, float spawn_z, float z_angle, int color1, int color2));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/AddStaticVehicleEx">AddStaticVehicleEx on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, AddStaticVehicleEx(int modelid, float spawn_x, float spawn_y, float spawn_z, float z_angle, int color1, int color2, int respawn_delay, bool addsiren));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/AddStaticPickup">AddStaticPickup on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, AddStaticPickup(int model, int type, float x, float y, float z, int virtualworld));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/CreatePickup">CreatePickup on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, CreatePickup(int model, int type, float x, float y, float z, int virtualworld));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/DestroyPickup">DestroyPickup on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, DestroyPickup(int pickup));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/ShowNameTags">ShowNameTags on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, ShowNameTags(bool show));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/ShowPlayerMarkers">ShowPlayerMarkers on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, ShowPlayerMarkers(int mode));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GameModeExit">GameModeExit on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GameModeExit());

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetWorldTime">SetWorldTime on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetWorldTime(int hour));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetWeaponName">GetWeaponName on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GetWeaponName(int weaponid, char * name, int size));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/EnableTirePopping">EnableTirePopping on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, EnableTirePopping(bool enable));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/EnableVehicleFriendlyFire">EnableVehicleFriendlyFire on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, EnableVehicleFriendlyFire());

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/AllowInteriorWeapons">AllowInteriorWeapons on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, AllowInteriorWeapons(bool allow));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetWeather">SetWeather on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetWeather(int weatherid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetGravity">SetGravity on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetGravity(float gravity));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetGravity">GetGravity on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(float, GetGravity());

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/AllowAdminTeleport">AllowAdminTeleport on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, AllowAdminTeleport(bool allow));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetDeathDropAmount">SetDeathDropAmount on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetDeathDropAmount(int amount));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/CreateExplosion">CreateExplosion on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, CreateExplosion(float x, float y, float z, int type, float radius));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/EnableZoneNames">EnableZoneNames on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, EnableZoneNames(bool enable));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/UsePlayerPedAnims">UsePlayerPedAnims on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, UsePlayerPedAnims());

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/DisableInteriorEnterExits">DisableInteriorEnterExits on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, DisableInteriorEnterExits());

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetNameTagDrawDistance">SetNameTagDrawDistance on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetNameTagDrawDistance(float distance));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/DisableNameTagLOS">DisableNameTagLOS on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, DisableNameTagLOS());

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/LimitGlobalChatRadius">LimitGlobalChatRadius on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, LimitGlobalChatRadius(float chat_radius));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/LimitPlayerMarkerRadius">LimitPlayerMarkerRadius on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, LimitPlayerMarkerRadius(float marker_radius));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/ConnectNPC">ConnectNPC on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, ConnectNPC(const char * name, const char * script));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/IsPlayerNPC">IsPlayerNPC on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, IsPlayerNPC(int playerid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/IsPlayerAdmin">IsPlayerAdmin on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, IsPlayerAdmin(int playerid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/Kick">Kick on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, Kick(int playerid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/Ban">Ban on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, Ban(int playerid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/BanEx">BanEx on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, BanEx(int playerid, const char * reason));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SendRconCommand">SendRconCommand on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SendRconCommand(const char * command));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetPlayerNetworkStats">GetPlayerNetworkStats on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GetPlayerNetworkStats(int playerid, char * retstr, int size));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetNetworkStats">GetNetworkStats on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GetNetworkStats(char * retstr, int size));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetPlayerVersion">GetPlayerVersion on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GetPlayerVersion(int playerid, char * version, int len));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/BlockIpAddress">BlockIpAddress on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, BlockIpAddress(const char * ip_address, int timems));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/UnBlockIpAddress">UnBlockIpAddress on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, UnBlockIpAddress(const char * ip_address));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetServerVarAsString">GetServerVarAsString on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GetServerVarAsString(const char * varname, char * value, int size));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetServerVarAsInt">GetServerVarAsInt on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, GetServerVarAsInt(const char * varname));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetServerVarAsBool">GetServerVarAsBool on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GetServerVarAsBool(const char * varname));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetConsoleVarAsString">GetConsoleVarAsString on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GetConsoleVarAsString(const char * varname, char * buffer, int len));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetConsoleVarAsInt">GetConsoleVarAsInt on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, GetConsoleVarAsInt(const char * varname));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetConsoleVarAsBool">GetConsoleVarAsBool on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GetConsoleVarAsBool(const char * varname));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetServerTickRate">GetServerTickRate on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, GetServerTickRate());

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/NetStats_GetConnectedTime">NetStats_GetConnectedTime on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, NetStats_GetConnectedTime(int playerid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/NetStats_MessagesReceived">NetStats_MessagesReceived on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, NetStats_MessagesReceived(int playerid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/NetStats_BytesReceived">NetStats_BytesReceived on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, NetStats_BytesReceived(int playerid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/NetStats_MessagesSent">NetStats_MessagesSent on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, NetStats_MessagesSent(int playerid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/NetStats_BytesSent">NetStats_BytesSent on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, NetStats_BytesSent(int playerid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/NetStats_MessagesRecvPerSecond">NetStats_MessagesRecvPerSecond on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, NetStats_MessagesRecvPerSecond(int playerid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/NetStats_PacketLossPercent">NetStats_PacketLossPercent on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(float, NetStats_PacketLossPercent(int playerid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/NetStats_ConnectionStatus">NetStats_ConnectionStatus on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, NetStats_ConnectionStatus(int playerid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/NetStats_GetIpPort">NetStats_GetIpPort on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, NetStats_GetIpPort(int playerid, char * ip_port, int ip_port_len));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/CreateMenu">CreateMenu on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, CreateMenu(const char * title, int columns, float x, float y, float col1width, float col2width));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/DestroyMenu">DestroyMenu on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, DestroyMenu(int menuid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/AddMenuItem">AddMenuItem on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, AddMenuItem(int menuid, int column, const char * menutext));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetMenuColumnHeader">SetMenuColumnHeader on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetMenuColumnHeader(int menuid, int column, const char * columnheader));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/ShowMenuForPlayer">ShowMenuForPlayer on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, ShowMenuForPlayer(int menuid, int playerid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/HideMenuForPlayer">HideMenuForPlayer on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, HideMenuForPlayer(int menuid, int playerid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/IsValidMenu">IsValidMenu on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, IsValidMenu(int menuid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/DisableMenu">DisableMenu on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, DisableMenu(int menuid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/DisableMenuRow">DisableMenuRow on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, DisableMenuRow(int menuid, int row));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetPlayerMenu">GetPlayerMenu on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, GetPlayerMenu(int playerid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/TextDrawCreate">TextDrawCreate on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, TextDrawCreate(float x, float y, const char * text));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/TextDrawDestroy">TextDrawDestroy on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, TextDrawDestroy(int text));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/TextDrawLetterSize">TextDrawLetterSize on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, TextDrawLetterSize(int text, float x, float y));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/TextDrawTextSize">TextDrawTextSize on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, TextDrawTextSize(int text, float x, float y));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/TextDrawAlignment">TextDrawAlignment on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, TextDrawAlignment(int text, int alignment));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/TextDrawColor">TextDrawColor on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, TextDrawColor(int text, int color));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/TextDrawUseBox">TextDrawUseBox on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, TextDrawUseBox(int text, bool use));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/TextDrawBoxColor">TextDrawBoxColor on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, TextDrawBoxColor(int text, int color));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/TextDrawSetShadow">TextDrawSetShadow on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, TextDrawSetShadow(int text, int size));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/TextDrawSetOutline">TextDrawSetOutline on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, TextDrawSetOutline(int text, int size));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/TextDrawBackgroundColor">TextDrawBackgroundColor on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, TextDrawBackgroundColor(int text, int color));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/TextDrawFont">TextDrawFont on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, TextDrawFont(int text, int font));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/TextDrawSetProportional">TextDrawSetProportional on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, TextDrawSetProportional(int text, bool set));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/TextDrawSetSelectable">TextDrawSetSelectable on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, TextDrawSetSelectable(int text, bool set));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/TextDrawShowForPlayer">TextDrawShowForPlayer on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, TextDrawShowForPlayer(int playerid, int text));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/TextDrawHideForPlayer">TextDrawHideForPlayer on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, TextDrawHideForPlayer(int playerid, int text));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/TextDrawShowForAll">TextDrawShowForAll on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, TextDrawShowForAll(int text));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/TextDrawHideForAll">TextDrawHideForAll on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, TextDrawHideForAll(int text));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/TextDrawSetString">TextDrawSetString on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, TextDrawSetString(int text, const char * string));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/TextDrawSetPreviewModel">TextDrawSetPreviewModel on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, TextDrawSetPreviewModel(int text, int modelindex));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/TextDrawSetPreviewRot">TextDrawSetPreviewRot on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, TextDrawSetPreviewRot(int text, float fRotX, float fRotY, float fRotZ, float fZoom));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/TextDrawSetPreviewVehCol">TextDrawSetPreviewVehCol on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, TextDrawSetPreviewVehCol(int text, int color1, int color2));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SelectTextDraw">SelectTextDraw on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SelectTextDraw(int playerid, int hovercolor));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/CancelSelectTextDraw">CancelSelectTextDraw on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, CancelSelectTextDraw(int playerid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GangZoneCreate">GangZoneCreate on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, GangZoneCreate(float minx, float miny, float maxx, float maxy));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GangZoneDestroy">GangZoneDestroy on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GangZoneDestroy(int zone));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GangZoneShowForPlayer">GangZoneShowForPlayer on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GangZoneShowForPlayer(int playerid, int zone, int color));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GangZoneShowForAll">GangZoneShowForAll on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GangZoneShowForAll(int zone, int color));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GangZoneHideForPlayer">GangZoneHideForPlayer on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GangZoneHideForPlayer(int playerid, int zone));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GangZoneHideForAll">GangZoneHideForAll on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GangZoneHideForAll(int zone));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GangZoneFlashForPlayer">GangZoneFlashForPlayer on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GangZoneFlashForPlayer(int playerid, int zone, int flashcolor));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GangZoneFlashForAll">GangZoneFlashForAll on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GangZoneFlashForAll(int zone, int flashcolor));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GangZoneStopFlashForPlayer">GangZoneStopFlashForPlayer on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GangZoneStopFlashForPlayer(int playerid, int zone));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GangZoneStopFlashForAll">GangZoneStopFlashForAll on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GangZoneStopFlashForAll(int zone));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/Create3DTextLabel">Create3DTextLabel on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, Create3DTextLabel(const char * text, int color, float x, float y, float z, float DrawDistance, int virtualworld, bool testLOS));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/Delete3DTextLabel">Delete3DTextLabel on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, Delete3DTextLabel(int id));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/Attach3DTextLabelToPlayer">Attach3DTextLabelToPlayer on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, Attach3DTextLabelToPlayer(int id, int playerid, float OffsetX, float OffsetY, float OffsetZ));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/Attach3DTextLabelToVehicle">Attach3DTextLabelToVehicle on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, Attach3DTextLabelToVehicle(int id, int vehicleid, float OffsetX, float OffsetY, float OffsetZ));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/Update3DTextLabelText">Update3DTextLabelText on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, Update3DTextLabelText(int id, int color, const char * text));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/CreatePlayer3DTextLabel">CreatePlayer3DTextLabel on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, CreatePlayer3DTextLabel(int playerid, const char * text, int color, float x, float y, float z, float DrawDistance, int attachedplayer, int attachedvehicle, bool testLOS));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/DeletePlayer3DTextLabel">DeletePlayer3DTextLabel on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, DeletePlayer3DTextLabel(int playerid, int id));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/UpdatePlayer3DTextLabelText">UpdatePlayer3DTextLabelText on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, UpdatePlayer3DTextLabelText(int playerid, int id, int color, const char * text));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/ShowPlayerDialog">ShowPlayerDialog on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, ShowPlayerDialog(int playerid, int dialogid, int style, const char * caption, const char * info, const char * button1, const char * button2));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetTimer">SetTimer on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, SetTimer(int interval, bool repeat, TimerCallback callback, void * param));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/KillTimer">KillTimer on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, KillTimer(int timerid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/gpci">gpci on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, gpci(int playerid, char * buffer, int size));

#ifndef DOXYGEN

#if defined SAMPGDK_CPP_WRAPPERS && !defined IN_SAMPGDK

namespace sampgdk {

inline bool SendClientMessage(int playerid, int color, const char * message) {
  return sampgdk_SendClientMessage(playerid, color, message);
}

inline bool SendClientMessageToAll(int color, const char * message) {
  return sampgdk_SendClientMessageToAll(color, message);
}

inline bool SendPlayerMessageToPlayer(int playerid, int senderid, const char * message) {
  return sampgdk_SendPlayerMessageToPlayer(playerid, senderid, message);
}

inline bool SendPlayerMessageToAll(int senderid, const char * message) {
  return sampgdk_SendPlayerMessageToAll(senderid, message);
}

inline bool SendDeathMessage(int killer, int killee, int weapon) {
  return sampgdk_SendDeathMessage(killer, killee, weapon);
}

inline bool SendDeathMessageToPlayer(int playerid, int killer, int killee, int weapon) {
  return sampgdk_SendDeathMessageToPlayer(playerid, killer, killee, weapon);
}

inline bool GameTextForAll(const char * text, int time, int style) {
  return sampgdk_GameTextForAll(text, time, style);
}

inline bool GameTextForPlayer(int playerid, const char * text, int time, int style) {
  return sampgdk_GameTextForPlayer(playerid, text, time, style);
}

inline int GetTickCount() {
  return sampgdk_GetTickCount();
}

inline int GetMaxPlayers() {
  return sampgdk_GetMaxPlayers();
}

inline float VectorSize(float x, float y, float z) {
  return sampgdk_VectorSize(x, y, z);
}

inline int GetPlayerPoolSize() {
  return sampgdk_GetPlayerPoolSize();
}

inline int GetVehiclePoolSize() {
  return sampgdk_GetVehiclePoolSize();
}

inline int GetActorPoolSize() {
  return sampgdk_GetActorPoolSize();
}

inline bool SHA256_PassHash(const char * password, const char * salt, char * ret_hash, int ret_hash_len) {
  return sampgdk_SHA256_PassHash(password, salt, ret_hash, ret_hash_len);
}

inline bool SetSVarInt(const char * varname, int int_value) {
  return sampgdk_SetSVarInt(varname, int_value);
}

inline int GetSVarInt(const char * varname) {
  return sampgdk_GetSVarInt(varname);
}

inline bool SetSVarString(const char * varname, const char * string_value) {
  return sampgdk_SetSVarString(varname, string_value);
}

inline bool GetSVarString(const char * varname, char * string_return, int len) {
  return sampgdk_GetSVarString(varname, string_return, len);
}

inline bool SetSVarFloat(const char * varname, float float_value) {
  return sampgdk_SetSVarFloat(varname, float_value);
}

inline float GetSVarFloat(const char * varname) {
  return sampgdk_GetSVarFloat(varname);
}

inline bool DeleteSVar(const char * varname) {
  return sampgdk_DeleteSVar(varname);
}

inline int GetSVarsUpperIndex() {
  return sampgdk_GetSVarsUpperIndex();
}

inline bool GetSVarNameAtIndex(int index, char * ret_varname, int ret_len) {
  return sampgdk_GetSVarNameAtIndex(index, ret_varname, ret_len);
}

inline int GetSVarType(const char * varname) {
  return sampgdk_GetSVarType(varname);
}

inline bool SetGameModeText(const char * text) {
  return sampgdk_SetGameModeText(text);
}

inline bool SetTeamCount(int count) {
  return sampgdk_SetTeamCount(count);
}

inline int AddPlayerClass(int modelid, float spawn_x, float spawn_y, float spawn_z, float z_angle, int weapon1, int weapon1_ammo, int weapon2, int weapon2_ammo, int weapon3, int weapon3_ammo) {
  return sampgdk_AddPlayerClass(modelid, spawn_x, spawn_y, spawn_z, z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
}

inline int AddPlayerClassEx(int teamid, int modelid, float spawn_x, float spawn_y, float spawn_z, float z_angle, int weapon1, int weapon1_ammo, int weapon2, int weapon2_ammo, int weapon3, int weapon3_ammo) {
  return sampgdk_AddPlayerClassEx(teamid, modelid, spawn_x, spawn_y, spawn_z, z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
}

inline int AddStaticVehicle(int modelid, float spawn_x, float spawn_y, float spawn_z, float z_angle, int color1, int color2) {
  return sampgdk_AddStaticVehicle(modelid, spawn_x, spawn_y, spawn_z, z_angle, color1, color2);
}

inline int AddStaticVehicleEx(int modelid, float spawn_x, float spawn_y, float spawn_z, float z_angle, int color1, int color2, int respawn_delay, bool addsiren = false) {
  return sampgdk_AddStaticVehicleEx(modelid, spawn_x, spawn_y, spawn_z, z_angle, color1, color2, respawn_delay, addsiren);
}

inline int AddStaticPickup(int model, int type, float x, float y, float z, int virtualworld = 0) {
  return sampgdk_AddStaticPickup(model, type, x, y, z, virtualworld);
}

inline int CreatePickup(int model, int type, float x, float y, float z, int virtualworld = 0) {
  return sampgdk_CreatePickup(model, type, x, y, z, virtualworld);
}

inline bool DestroyPickup(int pickup) {
  return sampgdk_DestroyPickup(pickup);
}

inline bool ShowNameTags(bool show) {
  return sampgdk_ShowNameTags(show);
}

inline bool ShowPlayerMarkers(int mode) {
  return sampgdk_ShowPlayerMarkers(mode);
}

inline bool GameModeExit() {
  return sampgdk_GameModeExit();
}

inline bool SetWorldTime(int hour) {
  return sampgdk_SetWorldTime(hour);
}

inline bool GetWeaponName(int weaponid, char * name, int size) {
  return sampgdk_GetWeaponName(weaponid, name, size);
}

inline bool EnableTirePopping(bool enable) {
  return sampgdk_EnableTirePopping(enable);
}

inline bool EnableVehicleFriendlyFire() {
  return sampgdk_EnableVehicleFriendlyFire();
}

inline bool AllowInteriorWeapons(bool allow) {
  return sampgdk_AllowInteriorWeapons(allow);
}

inline bool SetWeather(int weatherid) {
  return sampgdk_SetWeather(weatherid);
}

inline bool SetGravity(float gravity) {
  return sampgdk_SetGravity(gravity);
}

inline float GetGravity() {
  return sampgdk_GetGravity();
}

inline bool AllowAdminTeleport(bool allow) {
  return sampgdk_AllowAdminTeleport(allow);
}

inline bool SetDeathDropAmount(int amount) {
  return sampgdk_SetDeathDropAmount(amount);
}

inline bool CreateExplosion(float x, float y, float z, int type, float radius) {
  return sampgdk_CreateExplosion(x, y, z, type, radius);
}

inline bool EnableZoneNames(bool enable) {
  return sampgdk_EnableZoneNames(enable);
}

inline bool UsePlayerPedAnims() {
  return sampgdk_UsePlayerPedAnims();
}

inline bool DisableInteriorEnterExits() {
  return sampgdk_DisableInteriorEnterExits();
}

inline bool SetNameTagDrawDistance(float distance) {
  return sampgdk_SetNameTagDrawDistance(distance);
}

inline bool DisableNameTagLOS() {
  return sampgdk_DisableNameTagLOS();
}

inline bool LimitGlobalChatRadius(float chat_radius) {
  return sampgdk_LimitGlobalChatRadius(chat_radius);
}

inline bool LimitPlayerMarkerRadius(float marker_radius) {
  return sampgdk_LimitPlayerMarkerRadius(marker_radius);
}

inline bool ConnectNPC(const char * name, const char * script) {
  return sampgdk_ConnectNPC(name, script);
}

inline bool IsPlayerNPC(int playerid) {
  return sampgdk_IsPlayerNPC(playerid);
}

inline bool IsPlayerAdmin(int playerid) {
  return sampgdk_IsPlayerAdmin(playerid);
}

inline bool Kick(int playerid) {
  return sampgdk_Kick(playerid);
}

inline bool Ban(int playerid) {
  return sampgdk_Ban(playerid);
}

inline bool BanEx(int playerid, const char * reason) {
  return sampgdk_BanEx(playerid, reason);
}

inline bool SendRconCommand(const char * command) {
  return sampgdk_SendRconCommand(command);
}

inline bool GetPlayerNetworkStats(int playerid, char * retstr, int size) {
  return sampgdk_GetPlayerNetworkStats(playerid, retstr, size);
}

inline bool GetNetworkStats(char * retstr, int size) {
  return sampgdk_GetNetworkStats(retstr, size);
}

inline bool GetPlayerVersion(int playerid, char * version, int len) {
  return sampgdk_GetPlayerVersion(playerid, version, len);
}

inline bool BlockIpAddress(const char * ip_address, int timems) {
  return sampgdk_BlockIpAddress(ip_address, timems);
}

inline bool UnBlockIpAddress(const char * ip_address) {
  return sampgdk_UnBlockIpAddress(ip_address);
}

inline bool GetServerVarAsString(const char * varname, char * value, int size) {
  return sampgdk_GetServerVarAsString(varname, value, size);
}

inline int GetServerVarAsInt(const char * varname) {
  return sampgdk_GetServerVarAsInt(varname);
}

inline bool GetServerVarAsBool(const char * varname) {
  return sampgdk_GetServerVarAsBool(varname);
}

inline bool GetConsoleVarAsString(const char * varname, char * buffer, int len) {
  return sampgdk_GetConsoleVarAsString(varname, buffer, len);
}

inline int GetConsoleVarAsInt(const char * varname) {
  return sampgdk_GetConsoleVarAsInt(varname);
}

inline bool GetConsoleVarAsBool(const char * varname) {
  return sampgdk_GetConsoleVarAsBool(varname);
}

inline int GetServerTickRate() {
  return sampgdk_GetServerTickRate();
}

inline int NetStats_GetConnectedTime(int playerid) {
  return sampgdk_NetStats_GetConnectedTime(playerid);
}

inline int NetStats_MessagesReceived(int playerid) {
  return sampgdk_NetStats_MessagesReceived(playerid);
}

inline int NetStats_BytesReceived(int playerid) {
  return sampgdk_NetStats_BytesReceived(playerid);
}

inline int NetStats_MessagesSent(int playerid) {
  return sampgdk_NetStats_MessagesSent(playerid);
}

inline int NetStats_BytesSent(int playerid) {
  return sampgdk_NetStats_BytesSent(playerid);
}

inline int NetStats_MessagesRecvPerSecond(int playerid) {
  return sampgdk_NetStats_MessagesRecvPerSecond(playerid);
}

inline float NetStats_PacketLossPercent(int playerid) {
  return sampgdk_NetStats_PacketLossPercent(playerid);
}

inline int NetStats_ConnectionStatus(int playerid) {
  return sampgdk_NetStats_ConnectionStatus(playerid);
}

inline bool NetStats_GetIpPort(int playerid, char * ip_port, int ip_port_len) {
  return sampgdk_NetStats_GetIpPort(playerid, ip_port, ip_port_len);
}

inline int CreateMenu(const char * title, int columns, float x, float y, float col1width, float col2width = 0.0) {
  return sampgdk_CreateMenu(title, columns, x, y, col1width, col2width);
}

inline bool DestroyMenu(int menuid) {
  return sampgdk_DestroyMenu(menuid);
}

inline int AddMenuItem(int menuid, int column, const char * menutext) {
  return sampgdk_AddMenuItem(menuid, column, menutext);
}

inline bool SetMenuColumnHeader(int menuid, int column, const char * columnheader) {
  return sampgdk_SetMenuColumnHeader(menuid, column, columnheader);
}

inline bool ShowMenuForPlayer(int menuid, int playerid) {
  return sampgdk_ShowMenuForPlayer(menuid, playerid);
}

inline bool HideMenuForPlayer(int menuid, int playerid) {
  return sampgdk_HideMenuForPlayer(menuid, playerid);
}

inline bool IsValidMenu(int menuid) {
  return sampgdk_IsValidMenu(menuid);
}

inline bool DisableMenu(int menuid) {
  return sampgdk_DisableMenu(menuid);
}

inline bool DisableMenuRow(int menuid, int row) {
  return sampgdk_DisableMenuRow(menuid, row);
}

inline int GetPlayerMenu(int playerid) {
  return sampgdk_GetPlayerMenu(playerid);
}

inline int TextDrawCreate(float x, float y, const char * text) {
  return sampgdk_TextDrawCreate(x, y, text);
}

inline bool TextDrawDestroy(int text) {
  return sampgdk_TextDrawDestroy(text);
}

inline bool TextDrawLetterSize(int text, float x, float y) {
  return sampgdk_TextDrawLetterSize(text, x, y);
}

inline bool TextDrawTextSize(int text, float x, float y) {
  return sampgdk_TextDrawTextSize(text, x, y);
}

inline bool TextDrawAlignment(int text, int alignment) {
  return sampgdk_TextDrawAlignment(text, alignment);
}

inline bool TextDrawColor(int text, int color) {
  return sampgdk_TextDrawColor(text, color);
}

inline bool TextDrawUseBox(int text, bool use) {
  return sampgdk_TextDrawUseBox(text, use);
}

inline bool TextDrawBoxColor(int text, int color) {
  return sampgdk_TextDrawBoxColor(text, color);
}

inline bool TextDrawSetShadow(int text, int size) {
  return sampgdk_TextDrawSetShadow(text, size);
}

inline bool TextDrawSetOutline(int text, int size) {
  return sampgdk_TextDrawSetOutline(text, size);
}

inline bool TextDrawBackgroundColor(int text, int color) {
  return sampgdk_TextDrawBackgroundColor(text, color);
}

inline bool TextDrawFont(int text, int font) {
  return sampgdk_TextDrawFont(text, font);
}

inline bool TextDrawSetProportional(int text, bool set) {
  return sampgdk_TextDrawSetProportional(text, set);
}

inline bool TextDrawSetSelectable(int text, bool set) {
  return sampgdk_TextDrawSetSelectable(text, set);
}

inline bool TextDrawShowForPlayer(int playerid, int text) {
  return sampgdk_TextDrawShowForPlayer(playerid, text);
}

inline bool TextDrawHideForPlayer(int playerid, int text) {
  return sampgdk_TextDrawHideForPlayer(playerid, text);
}

inline bool TextDrawShowForAll(int text) {
  return sampgdk_TextDrawShowForAll(text);
}

inline bool TextDrawHideForAll(int text) {
  return sampgdk_TextDrawHideForAll(text);
}

inline bool TextDrawSetString(int text, const char * string) {
  return sampgdk_TextDrawSetString(text, string);
}

inline bool TextDrawSetPreviewModel(int text, int modelindex) {
  return sampgdk_TextDrawSetPreviewModel(text, modelindex);
}

inline bool TextDrawSetPreviewRot(int text, float fRotX, float fRotY, float fRotZ, float fZoom = 1.0) {
  return sampgdk_TextDrawSetPreviewRot(text, fRotX, fRotY, fRotZ, fZoom);
}

inline bool TextDrawSetPreviewVehCol(int text, int color1, int color2) {
  return sampgdk_TextDrawSetPreviewVehCol(text, color1, color2);
}

inline bool SelectTextDraw(int playerid, int hovercolor) {
  return sampgdk_SelectTextDraw(playerid, hovercolor);
}

inline bool CancelSelectTextDraw(int playerid) {
  return sampgdk_CancelSelectTextDraw(playerid);
}

inline int GangZoneCreate(float minx, float miny, float maxx, float maxy) {
  return sampgdk_GangZoneCreate(minx, miny, maxx, maxy);
}

inline bool GangZoneDestroy(int zone) {
  return sampgdk_GangZoneDestroy(zone);
}

inline bool GangZoneShowForPlayer(int playerid, int zone, int color) {
  return sampgdk_GangZoneShowForPlayer(playerid, zone, color);
}

inline bool GangZoneShowForAll(int zone, int color) {
  return sampgdk_GangZoneShowForAll(zone, color);
}

inline bool GangZoneHideForPlayer(int playerid, int zone) {
  return sampgdk_GangZoneHideForPlayer(playerid, zone);
}

inline bool GangZoneHideForAll(int zone) {
  return sampgdk_GangZoneHideForAll(zone);
}

inline bool GangZoneFlashForPlayer(int playerid, int zone, int flashcolor) {
  return sampgdk_GangZoneFlashForPlayer(playerid, zone, flashcolor);
}

inline bool GangZoneFlashForAll(int zone, int flashcolor) {
  return sampgdk_GangZoneFlashForAll(zone, flashcolor);
}

inline bool GangZoneStopFlashForPlayer(int playerid, int zone) {
  return sampgdk_GangZoneStopFlashForPlayer(playerid, zone);
}

inline bool GangZoneStopFlashForAll(int zone) {
  return sampgdk_GangZoneStopFlashForAll(zone);
}

inline int Create3DTextLabel(const char * text, int color, float x, float y, float z, float DrawDistance, int virtualworld, bool testLOS = false) {
  return sampgdk_Create3DTextLabel(text, color, x, y, z, DrawDistance, virtualworld, testLOS);
}

inline bool Delete3DTextLabel(int id) {
  return sampgdk_Delete3DTextLabel(id);
}

inline bool Attach3DTextLabelToPlayer(int id, int playerid, float OffsetX, float OffsetY, float OffsetZ) {
  return sampgdk_Attach3DTextLabelToPlayer(id, playerid, OffsetX, OffsetY, OffsetZ);
}

inline bool Attach3DTextLabelToVehicle(int id, int vehicleid, float OffsetX, float OffsetY, float OffsetZ) {
  return sampgdk_Attach3DTextLabelToVehicle(id, vehicleid, OffsetX, OffsetY, OffsetZ);
}

inline bool Update3DTextLabelText(int id, int color, const char * text) {
  return sampgdk_Update3DTextLabelText(id, color, text);
}

inline int CreatePlayer3DTextLabel(int playerid, const char * text, int color, float x, float y, float z, float DrawDistance, int attachedplayer = INVALID_PLAYER_ID, int attachedvehicle = INVALID_VEHICLE_ID, bool testLOS = false) {
  return sampgdk_CreatePlayer3DTextLabel(playerid, text, color, x, y, z, DrawDistance, attachedplayer, attachedvehicle, testLOS);
}

inline bool DeletePlayer3DTextLabel(int playerid, int id) {
  return sampgdk_DeletePlayer3DTextLabel(playerid, id);
}

inline bool UpdatePlayer3DTextLabelText(int playerid, int id, int color, const char * text) {
  return sampgdk_UpdatePlayer3DTextLabelText(playerid, id, color, text);
}

inline bool ShowPlayerDialog(int playerid, int dialogid, int style, const char * caption, const char * info, const char * button1, const char * button2) {
  return sampgdk_ShowPlayerDialog(playerid, dialogid, style, caption, info, button1, button2);
}

inline int SetTimer(int interval, bool repeat, TimerCallback callback, void * param) {
  return sampgdk_SetTimer(interval, repeat, callback, param);
}

inline bool KillTimer(int timerid) {
  return sampgdk_KillTimer(timerid);
}

inline bool gpci(int playerid, char * buffer, int size) {
  return sampgdk_gpci(playerid, buffer, size);
}

} // namespace sampgdk

#else /* SAMPGDK_CPP_WRAPPERS && !IN_SAMPGDK */

#undef  SendClientMessage
#define SendClientMessage sampgdk_SendClientMessage

#undef  SendClientMessageToAll
#define SendClientMessageToAll sampgdk_SendClientMessageToAll

#undef  SendPlayerMessageToPlayer
#define SendPlayerMessageToPlayer sampgdk_SendPlayerMessageToPlayer

#undef  SendPlayerMessageToAll
#define SendPlayerMessageToAll sampgdk_SendPlayerMessageToAll

#undef  SendDeathMessage
#define SendDeathMessage sampgdk_SendDeathMessage

#undef  SendDeathMessageToPlayer
#define SendDeathMessageToPlayer sampgdk_SendDeathMessageToPlayer

#undef  GameTextForAll
#define GameTextForAll sampgdk_GameTextForAll

#undef  GameTextForPlayer
#define GameTextForPlayer sampgdk_GameTextForPlayer

#undef  GetTickCount
#define GetTickCount sampgdk_GetTickCount

#undef  GetMaxPlayers
#define GetMaxPlayers sampgdk_GetMaxPlayers

#undef  VectorSize
#define VectorSize sampgdk_VectorSize

#undef  GetPlayerPoolSize
#define GetPlayerPoolSize sampgdk_GetPlayerPoolSize

#undef  GetVehiclePoolSize
#define GetVehiclePoolSize sampgdk_GetVehiclePoolSize

#undef  GetActorPoolSize
#define GetActorPoolSize sampgdk_GetActorPoolSize

#undef  SHA256_PassHash
#define SHA256_PassHash sampgdk_SHA256_PassHash

#undef  SetSVarInt
#define SetSVarInt sampgdk_SetSVarInt

#undef  GetSVarInt
#define GetSVarInt sampgdk_GetSVarInt

#undef  SetSVarString
#define SetSVarString sampgdk_SetSVarString

#undef  GetSVarString
#define GetSVarString sampgdk_GetSVarString

#undef  SetSVarFloat
#define SetSVarFloat sampgdk_SetSVarFloat

#undef  GetSVarFloat
#define GetSVarFloat sampgdk_GetSVarFloat

#undef  DeleteSVar
#define DeleteSVar sampgdk_DeleteSVar

#undef  GetSVarsUpperIndex
#define GetSVarsUpperIndex sampgdk_GetSVarsUpperIndex

#undef  GetSVarNameAtIndex
#define GetSVarNameAtIndex sampgdk_GetSVarNameAtIndex

#undef  GetSVarType
#define GetSVarType sampgdk_GetSVarType

#undef  SetGameModeText
#define SetGameModeText sampgdk_SetGameModeText

#undef  SetTeamCount
#define SetTeamCount sampgdk_SetTeamCount

#undef  AddPlayerClass
#define AddPlayerClass sampgdk_AddPlayerClass

#undef  AddPlayerClassEx
#define AddPlayerClassEx sampgdk_AddPlayerClassEx

#undef  AddStaticVehicle
#define AddStaticVehicle sampgdk_AddStaticVehicle

#undef  AddStaticVehicleEx
#define AddStaticVehicleEx sampgdk_AddStaticVehicleEx

#undef  AddStaticPickup
#define AddStaticPickup sampgdk_AddStaticPickup

#undef  CreatePickup
#define CreatePickup sampgdk_CreatePickup

#undef  DestroyPickup
#define DestroyPickup sampgdk_DestroyPickup

#undef  ShowNameTags
#define ShowNameTags sampgdk_ShowNameTags

#undef  ShowPlayerMarkers
#define ShowPlayerMarkers sampgdk_ShowPlayerMarkers

#undef  GameModeExit
#define GameModeExit sampgdk_GameModeExit

#undef  SetWorldTime
#define SetWorldTime sampgdk_SetWorldTime

#undef  GetWeaponName
#define GetWeaponName sampgdk_GetWeaponName

#undef  EnableTirePopping
#define EnableTirePopping sampgdk_EnableTirePopping

#undef  EnableVehicleFriendlyFire
#define EnableVehicleFriendlyFire sampgdk_EnableVehicleFriendlyFire

#undef  AllowInteriorWeapons
#define AllowInteriorWeapons sampgdk_AllowInteriorWeapons

#undef  SetWeather
#define SetWeather sampgdk_SetWeather

#undef  SetGravity
#define SetGravity sampgdk_SetGravity

#undef  GetGravity
#define GetGravity sampgdk_GetGravity

#undef  AllowAdminTeleport
#define AllowAdminTeleport sampgdk_AllowAdminTeleport

#undef  SetDeathDropAmount
#define SetDeathDropAmount sampgdk_SetDeathDropAmount

#undef  CreateExplosion
#define CreateExplosion sampgdk_CreateExplosion

#undef  EnableZoneNames
#define EnableZoneNames sampgdk_EnableZoneNames

#undef  UsePlayerPedAnims
#define UsePlayerPedAnims sampgdk_UsePlayerPedAnims

#undef  DisableInteriorEnterExits
#define DisableInteriorEnterExits sampgdk_DisableInteriorEnterExits

#undef  SetNameTagDrawDistance
#define SetNameTagDrawDistance sampgdk_SetNameTagDrawDistance

#undef  DisableNameTagLOS
#define DisableNameTagLOS sampgdk_DisableNameTagLOS

#undef  LimitGlobalChatRadius
#define LimitGlobalChatRadius sampgdk_LimitGlobalChatRadius

#undef  LimitPlayerMarkerRadius
#define LimitPlayerMarkerRadius sampgdk_LimitPlayerMarkerRadius

#undef  ConnectNPC
#define ConnectNPC sampgdk_ConnectNPC

#undef  IsPlayerNPC
#define IsPlayerNPC sampgdk_IsPlayerNPC

#undef  IsPlayerAdmin
#define IsPlayerAdmin sampgdk_IsPlayerAdmin

#undef  Kick
#define Kick sampgdk_Kick

#undef  Ban
#define Ban sampgdk_Ban

#undef  BanEx
#define BanEx sampgdk_BanEx

#undef  SendRconCommand
#define SendRconCommand sampgdk_SendRconCommand

#undef  GetPlayerNetworkStats
#define GetPlayerNetworkStats sampgdk_GetPlayerNetworkStats

#undef  GetNetworkStats
#define GetNetworkStats sampgdk_GetNetworkStats

#undef  GetPlayerVersion
#define GetPlayerVersion sampgdk_GetPlayerVersion

#undef  BlockIpAddress
#define BlockIpAddress sampgdk_BlockIpAddress

#undef  UnBlockIpAddress
#define UnBlockIpAddress sampgdk_UnBlockIpAddress

#undef  GetServerVarAsString
#define GetServerVarAsString sampgdk_GetServerVarAsString

#undef  GetServerVarAsInt
#define GetServerVarAsInt sampgdk_GetServerVarAsInt

#undef  GetServerVarAsBool
#define GetServerVarAsBool sampgdk_GetServerVarAsBool

#undef  GetConsoleVarAsString
#define GetConsoleVarAsString sampgdk_GetConsoleVarAsString

#undef  GetConsoleVarAsInt
#define GetConsoleVarAsInt sampgdk_GetConsoleVarAsInt

#undef  GetConsoleVarAsBool
#define GetConsoleVarAsBool sampgdk_GetConsoleVarAsBool

#undef  GetServerTickRate
#define GetServerTickRate sampgdk_GetServerTickRate

#undef  NetStats_GetConnectedTime
#define NetStats_GetConnectedTime sampgdk_NetStats_GetConnectedTime

#undef  NetStats_MessagesReceived
#define NetStats_MessagesReceived sampgdk_NetStats_MessagesReceived

#undef  NetStats_BytesReceived
#define NetStats_BytesReceived sampgdk_NetStats_BytesReceived

#undef  NetStats_MessagesSent
#define NetStats_MessagesSent sampgdk_NetStats_MessagesSent

#undef  NetStats_BytesSent
#define NetStats_BytesSent sampgdk_NetStats_BytesSent

#undef  NetStats_MessagesRecvPerSecond
#define NetStats_MessagesRecvPerSecond sampgdk_NetStats_MessagesRecvPerSecond

#undef  NetStats_PacketLossPercent
#define NetStats_PacketLossPercent sampgdk_NetStats_PacketLossPercent

#undef  NetStats_ConnectionStatus
#define NetStats_ConnectionStatus sampgdk_NetStats_ConnectionStatus

#undef  NetStats_GetIpPort
#define NetStats_GetIpPort sampgdk_NetStats_GetIpPort

#undef  CreateMenu
#define CreateMenu sampgdk_CreateMenu

#undef  DestroyMenu
#define DestroyMenu sampgdk_DestroyMenu

#undef  AddMenuItem
#define AddMenuItem sampgdk_AddMenuItem

#undef  SetMenuColumnHeader
#define SetMenuColumnHeader sampgdk_SetMenuColumnHeader

#undef  ShowMenuForPlayer
#define ShowMenuForPlayer sampgdk_ShowMenuForPlayer

#undef  HideMenuForPlayer
#define HideMenuForPlayer sampgdk_HideMenuForPlayer

#undef  IsValidMenu
#define IsValidMenu sampgdk_IsValidMenu

#undef  DisableMenu
#define DisableMenu sampgdk_DisableMenu

#undef  DisableMenuRow
#define DisableMenuRow sampgdk_DisableMenuRow

#undef  GetPlayerMenu
#define GetPlayerMenu sampgdk_GetPlayerMenu

#undef  TextDrawCreate
#define TextDrawCreate sampgdk_TextDrawCreate

#undef  TextDrawDestroy
#define TextDrawDestroy sampgdk_TextDrawDestroy

#undef  TextDrawLetterSize
#define TextDrawLetterSize sampgdk_TextDrawLetterSize

#undef  TextDrawTextSize
#define TextDrawTextSize sampgdk_TextDrawTextSize

#undef  TextDrawAlignment
#define TextDrawAlignment sampgdk_TextDrawAlignment

#undef  TextDrawColor
#define TextDrawColor sampgdk_TextDrawColor

#undef  TextDrawUseBox
#define TextDrawUseBox sampgdk_TextDrawUseBox

#undef  TextDrawBoxColor
#define TextDrawBoxColor sampgdk_TextDrawBoxColor

#undef  TextDrawSetShadow
#define TextDrawSetShadow sampgdk_TextDrawSetShadow

#undef  TextDrawSetOutline
#define TextDrawSetOutline sampgdk_TextDrawSetOutline

#undef  TextDrawBackgroundColor
#define TextDrawBackgroundColor sampgdk_TextDrawBackgroundColor

#undef  TextDrawFont
#define TextDrawFont sampgdk_TextDrawFont

#undef  TextDrawSetProportional
#define TextDrawSetProportional sampgdk_TextDrawSetProportional

#undef  TextDrawSetSelectable
#define TextDrawSetSelectable sampgdk_TextDrawSetSelectable

#undef  TextDrawShowForPlayer
#define TextDrawShowForPlayer sampgdk_TextDrawShowForPlayer

#undef  TextDrawHideForPlayer
#define TextDrawHideForPlayer sampgdk_TextDrawHideForPlayer

#undef  TextDrawShowForAll
#define TextDrawShowForAll sampgdk_TextDrawShowForAll

#undef  TextDrawHideForAll
#define TextDrawHideForAll sampgdk_TextDrawHideForAll

#undef  TextDrawSetString
#define TextDrawSetString sampgdk_TextDrawSetString

#undef  TextDrawSetPreviewModel
#define TextDrawSetPreviewModel sampgdk_TextDrawSetPreviewModel

#undef  TextDrawSetPreviewRot
#define TextDrawSetPreviewRot sampgdk_TextDrawSetPreviewRot

#undef  TextDrawSetPreviewVehCol
#define TextDrawSetPreviewVehCol sampgdk_TextDrawSetPreviewVehCol

#undef  SelectTextDraw
#define SelectTextDraw sampgdk_SelectTextDraw

#undef  CancelSelectTextDraw
#define CancelSelectTextDraw sampgdk_CancelSelectTextDraw

#undef  GangZoneCreate
#define GangZoneCreate sampgdk_GangZoneCreate

#undef  GangZoneDestroy
#define GangZoneDestroy sampgdk_GangZoneDestroy

#undef  GangZoneShowForPlayer
#define GangZoneShowForPlayer sampgdk_GangZoneShowForPlayer

#undef  GangZoneShowForAll
#define GangZoneShowForAll sampgdk_GangZoneShowForAll

#undef  GangZoneHideForPlayer
#define GangZoneHideForPlayer sampgdk_GangZoneHideForPlayer

#undef  GangZoneHideForAll
#define GangZoneHideForAll sampgdk_GangZoneHideForAll

#undef  GangZoneFlashForPlayer
#define GangZoneFlashForPlayer sampgdk_GangZoneFlashForPlayer

#undef  GangZoneFlashForAll
#define GangZoneFlashForAll sampgdk_GangZoneFlashForAll

#undef  GangZoneStopFlashForPlayer
#define GangZoneStopFlashForPlayer sampgdk_GangZoneStopFlashForPlayer

#undef  GangZoneStopFlashForAll
#define GangZoneStopFlashForAll sampgdk_GangZoneStopFlashForAll

#undef  Create3DTextLabel
#define Create3DTextLabel sampgdk_Create3DTextLabel

#undef  Delete3DTextLabel
#define Delete3DTextLabel sampgdk_Delete3DTextLabel

#undef  Attach3DTextLabelToPlayer
#define Attach3DTextLabelToPlayer sampgdk_Attach3DTextLabelToPlayer

#undef  Attach3DTextLabelToVehicle
#define Attach3DTextLabelToVehicle sampgdk_Attach3DTextLabelToVehicle

#undef  Update3DTextLabelText
#define Update3DTextLabelText sampgdk_Update3DTextLabelText

#undef  CreatePlayer3DTextLabel
#define CreatePlayer3DTextLabel sampgdk_CreatePlayer3DTextLabel

#undef  DeletePlayer3DTextLabel
#define DeletePlayer3DTextLabel sampgdk_DeletePlayer3DTextLabel

#undef  UpdatePlayer3DTextLabelText
#define UpdatePlayer3DTextLabelText sampgdk_UpdatePlayer3DTextLabelText

#undef  ShowPlayerDialog
#define ShowPlayerDialog sampgdk_ShowPlayerDialog

#undef  SetTimer
#define SetTimer sampgdk_SetTimer

#undef  KillTimer
#define KillTimer sampgdk_KillTimer

#undef  gpci
#define gpci sampgdk_gpci

#endif /* !SAMPGDK_CPP_WRAPPERS || IN_SAMPGDK */
#endif /* !DOXYGEN */

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnGameModeInit">OnGameModeInit on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnGameModeInit());

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnGameModeExit">OnGameModeExit on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnGameModeExit());

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerConnect">OnPlayerConnect on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerConnect(int playerid));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerDisconnect">OnPlayerDisconnect on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerDisconnect(int playerid, int reason));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerSpawn">OnPlayerSpawn on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerSpawn(int playerid));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerDeath">OnPlayerDeath on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerDeath(int playerid, int killerid, int reason));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnVehicleSpawn">OnVehicleSpawn on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnVehicleSpawn(int vehicleid));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnVehicleDeath">OnVehicleDeath on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnVehicleDeath(int vehicleid, int killerid));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerText">OnPlayerText on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerText(int playerid, const char * text));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerCommandText">OnPlayerCommandText on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerCommandText(int playerid, const char * cmdtext));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerRequestClass">OnPlayerRequestClass on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerRequestClass(int playerid, int classid));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerEnterVehicle">OnPlayerEnterVehicle on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerEnterVehicle(int playerid, int vehicleid, bool ispassenger));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerExitVehicle">OnPlayerExitVehicle on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerExitVehicle(int playerid, int vehicleid));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerStateChange">OnPlayerStateChange on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerStateChange(int playerid, int newstate, int oldstate));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerEnterCheckpoint">OnPlayerEnterCheckpoint on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerEnterCheckpoint(int playerid));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerLeaveCheckpoint">OnPlayerLeaveCheckpoint on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerLeaveCheckpoint(int playerid));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerEnterRaceCheckpoint">OnPlayerEnterRaceCheckpoint on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerEnterRaceCheckpoint(int playerid));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerLeaveRaceCheckpoint">OnPlayerLeaveRaceCheckpoint on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerLeaveRaceCheckpoint(int playerid));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnRconCommand">OnRconCommand on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnRconCommand(const char * cmd));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerRequestSpawn">OnPlayerRequestSpawn on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerRequestSpawn(int playerid));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnObjectMoved">OnObjectMoved on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnObjectMoved(int objectid));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerObjectMoved">OnPlayerObjectMoved on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerObjectMoved(int playerid, int objectid));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerPickUpPickup">OnPlayerPickUpPickup on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerPickUpPickup(int playerid, int pickupid));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnVehicleMod">OnVehicleMod on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnVehicleMod(int playerid, int vehicleid, int componentid));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnEnterExitModShop">OnEnterExitModShop on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnEnterExitModShop(int playerid, int enterexit, int interiorid));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnVehiclePaintjob">OnVehiclePaintjob on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnVehiclePaintjob(int playerid, int vehicleid, int paintjobid));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnVehicleRespray">OnVehicleRespray on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnVehicleRespray(int playerid, int vehicleid, int color1, int color2));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnVehicleDamageStatusUpdate">OnVehicleDamageStatusUpdate on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnVehicleDamageStatusUpdate(int vehicleid, int playerid));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnUnoccupiedVehicleUpdate">OnUnoccupiedVehicleUpdate on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnUnoccupiedVehicleUpdate(int vehicleid, int playerid, int passenger_seat, float new_x, float new_y, float new_z, float vel_x, float vel_y, float vel_z));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerSelectedMenuRow">OnPlayerSelectedMenuRow on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerSelectedMenuRow(int playerid, int row));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerExitedMenu">OnPlayerExitedMenu on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerExitedMenu(int playerid));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerInteriorChange">OnPlayerInteriorChange on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerInteriorChange(int playerid, int newinteriorid, int oldinteriorid));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerKeyStateChange">OnPlayerKeyStateChange on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerKeyStateChange(int playerid, int newkeys, int oldkeys));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnRconLoginAttempt">OnRconLoginAttempt on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnRconLoginAttempt(const char * ip, const char * password, bool success));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerUpdate">OnPlayerUpdate on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerUpdate(int playerid));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerStreamIn">OnPlayerStreamIn on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerStreamIn(int playerid, int forplayerid));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerStreamOut">OnPlayerStreamOut on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerStreamOut(int playerid, int forplayerid));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnVehicleStreamIn">OnVehicleStreamIn on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnVehicleStreamIn(int vehicleid, int forplayerid));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnVehicleStreamOut">OnVehicleStreamOut on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnVehicleStreamOut(int vehicleid, int forplayerid));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnActorStreamIn">OnActorStreamIn on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnActorStreamIn(int actorid, int forplayerid));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnActorStreamOut">OnActorStreamOut on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnActorStreamOut(int actorid, int forplayerid));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnDialogResponse">OnDialogResponse on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnDialogResponse(int playerid, int dialogid, int response, int listitem, const char * inputtext));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerTakeDamage">OnPlayerTakeDamage on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerTakeDamage(int playerid, int issuerid, float amount, int weaponid, int bodypart));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerGiveDamage">OnPlayerGiveDamage on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerGiveDamage(int playerid, int damagedid, float amount, int weaponid, int bodypart));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerGiveDamageActor">OnPlayerGiveDamageActor on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerGiveDamageActor(int playerid, int damaged_actorid, float amount, int weaponid, int bodypart));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerClickMap">OnPlayerClickMap on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerClickMap(int playerid, float fX, float fY, float fZ));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerClickTextDraw">OnPlayerClickTextDraw on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerClickTextDraw(int playerid, int clickedid));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerClickPlayerTextDraw">OnPlayerClickPlayerTextDraw on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerClickPlayerTextDraw(int playerid, int playertextid));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnIncomingConnection">OnIncomingConnection on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnIncomingConnection(int playerid, const char * ip_address, int port));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnTrailerUpdate">OnTrailerUpdate on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnTrailerUpdate(int playerid, int vehicleid));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnVehicleSirenStateChange">OnVehicleSirenStateChange on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnVehicleSirenStateChange(int playerid, int vehicleid, int newstate));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerClickPlayer">OnPlayerClickPlayer on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerClickPlayer(int playerid, int clickedplayerid, int source));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerEditObject">OnPlayerEditObject on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerEditObject(int playerid, bool playerobject, int objectid, int response, float fX, float fY, float fZ, float fRotX, float fRotY, float fRotZ));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerEditAttachedObject">OnPlayerEditAttachedObject on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerEditAttachedObject(int playerid, int response, int index, int modelid, int boneid, float fOffsetX, float fOffsetY, float fOffsetZ, float fRotX, float fRotY, float fRotZ, float fScaleX, float fScaleY, float fScaleZ));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerSelectObject">OnPlayerSelectObject on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerSelectObject(int playerid, int type, int objectid, int modelid, float fX, float fY, float fZ));

/**
 * \ingroup callbacks
 * \see <a href="http://wiki.sa-mp.com/wiki/OnPlayerWeaponShot">OnPlayerWeaponShot on SA-MP Wiki</a>
 */
SAMPGDK_CALLBACK(bool, OnPlayerWeaponShot(int playerid, int weaponid, int hittype, int hitid, float fX, float fY, float fZ));

#endif /* !SAMPGDK_A_SAMP_H */
