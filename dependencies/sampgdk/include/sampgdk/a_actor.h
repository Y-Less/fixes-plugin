#ifndef SAMPGDK_A_ACTOR_H
#define SAMPGDK_A_ACTOR_H

#include <sampgdk/bool.h>
#include <sampgdk/export.h>
#include <sampgdk/types.h>


/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/CreateActor">CreateActor on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, CreateActor(int modelid, float x, float y, float z, float rotation));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/DestroyActor">DestroyActor on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, DestroyActor(int actorid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/IsActorStreamedIn">IsActorStreamedIn on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, IsActorStreamedIn(int actorid, int forplayerid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetActorVirtualWorld">SetActorVirtualWorld on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetActorVirtualWorld(int actorid, int vworld));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetActorVirtualWorld">GetActorVirtualWorld on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, GetActorVirtualWorld(int actorid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/ApplyActorAnimation">ApplyActorAnimation on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, ApplyActorAnimation(int actorid, const char * animlib, const char * animname, float fDelta, bool loop, bool lockx, bool locky, bool freeze, int time));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/ClearActorAnimations">ClearActorAnimations on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, ClearActorAnimations(int actorid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetActorPos">SetActorPos on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetActorPos(int actorid, float x, float y, float z));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetActorPos">GetActorPos on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GetActorPos(int actorid, float * x, float * y, float * z));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetActorFacingAngle">SetActorFacingAngle on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetActorFacingAngle(int actorid, float angle));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetActorFacingAngle">GetActorFacingAngle on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GetActorFacingAngle(int actorid, float * angle));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetActorHealth">SetActorHealth on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetActorHealth(int actorid, float health));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetActorHealth">GetActorHealth on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GetActorHealth(int actorid, float * health));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetActorInvulnerable">SetActorInvulnerable on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetActorInvulnerable(int actorid, bool invulnerable));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/IsActorInvulnerable">IsActorInvulnerable on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, IsActorInvulnerable(int actorid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/IsValidActor">IsValidActor on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, IsValidActor(int actorid));

#ifndef DOXYGEN

#if defined SAMPGDK_CPP_WRAPPERS && !defined IN_SAMPGDK

namespace sampgdk {

inline int CreateActor(int modelid, float x, float y, float z, float rotation) {
  return sampgdk_CreateActor(modelid, x, y, z, rotation);
}

inline bool DestroyActor(int actorid) {
  return sampgdk_DestroyActor(actorid);
}

inline bool IsActorStreamedIn(int actorid, int forplayerid) {
  return sampgdk_IsActorStreamedIn(actorid, forplayerid);
}

inline bool SetActorVirtualWorld(int actorid, int vworld) {
  return sampgdk_SetActorVirtualWorld(actorid, vworld);
}

inline int GetActorVirtualWorld(int actorid) {
  return sampgdk_GetActorVirtualWorld(actorid);
}

inline bool ApplyActorAnimation(int actorid, const char * animlib, const char * animname, float fDelta, bool loop, bool lockx, bool locky, bool freeze, int time) {
  return sampgdk_ApplyActorAnimation(actorid, animlib, animname, fDelta, loop, lockx, locky, freeze, time);
}

inline bool ClearActorAnimations(int actorid) {
  return sampgdk_ClearActorAnimations(actorid);
}

inline bool SetActorPos(int actorid, float x, float y, float z) {
  return sampgdk_SetActorPos(actorid, x, y, z);
}

inline bool GetActorPos(int actorid, float * x, float * y, float * z) {
  return sampgdk_GetActorPos(actorid, x, y, z);
}

inline bool SetActorFacingAngle(int actorid, float angle) {
  return sampgdk_SetActorFacingAngle(actorid, angle);
}

inline bool GetActorFacingAngle(int actorid, float * angle) {
  return sampgdk_GetActorFacingAngle(actorid, angle);
}

inline bool SetActorHealth(int actorid, float health) {
  return sampgdk_SetActorHealth(actorid, health);
}

inline bool GetActorHealth(int actorid, float * health) {
  return sampgdk_GetActorHealth(actorid, health);
}

inline bool SetActorInvulnerable(int actorid, bool invulnerable = true) {
  return sampgdk_SetActorInvulnerable(actorid, invulnerable);
}

inline bool IsActorInvulnerable(int actorid) {
  return sampgdk_IsActorInvulnerable(actorid);
}

inline bool IsValidActor(int actorid) {
  return sampgdk_IsValidActor(actorid);
}

} // namespace sampgdk

#else /* SAMPGDK_CPP_WRAPPERS && !IN_SAMPGDK */

#undef  CreateActor
#define CreateActor sampgdk_CreateActor

#undef  DestroyActor
#define DestroyActor sampgdk_DestroyActor

#undef  IsActorStreamedIn
#define IsActorStreamedIn sampgdk_IsActorStreamedIn

#undef  SetActorVirtualWorld
#define SetActorVirtualWorld sampgdk_SetActorVirtualWorld

#undef  GetActorVirtualWorld
#define GetActorVirtualWorld sampgdk_GetActorVirtualWorld

#undef  ApplyActorAnimation
#define ApplyActorAnimation sampgdk_ApplyActorAnimation

#undef  ClearActorAnimations
#define ClearActorAnimations sampgdk_ClearActorAnimations

#undef  SetActorPos
#define SetActorPos sampgdk_SetActorPos

#undef  GetActorPos
#define GetActorPos sampgdk_GetActorPos

#undef  SetActorFacingAngle
#define SetActorFacingAngle sampgdk_SetActorFacingAngle

#undef  GetActorFacingAngle
#define GetActorFacingAngle sampgdk_GetActorFacingAngle

#undef  SetActorHealth
#define SetActorHealth sampgdk_SetActorHealth

#undef  GetActorHealth
#define GetActorHealth sampgdk_GetActorHealth

#undef  SetActorInvulnerable
#define SetActorInvulnerable sampgdk_SetActorInvulnerable

#undef  IsActorInvulnerable
#define IsActorInvulnerable sampgdk_IsActorInvulnerable

#undef  IsValidActor
#define IsValidActor sampgdk_IsValidActor

#endif /* !SAMPGDK_CPP_WRAPPERS || IN_SAMPGDK */
#endif /* !DOXYGEN */

#endif /* !SAMPGDK_A_ACTOR_H */
