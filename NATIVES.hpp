#undef  SetPlayerPos
HOOK(SetPlayerPos, bool(int, float, float, float));
#define SetPlayerPos hooked_SetPlayerPos

