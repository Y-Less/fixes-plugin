#pragma once

#undef SetPlayerPos
HOOK_DECL(fixes, SetPlayerPos, bool(int playerid, float x, float y, float z));

