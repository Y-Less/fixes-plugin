#undef  SetPlayerPos
HOOK(SetPlayerPos, bool(int playerid, float x, float y, float z));
#define SetPlayerPos FIXES_SetPlayerPos
#define BAD_SetPlayerPos *FIXES_SetPlayerPos

