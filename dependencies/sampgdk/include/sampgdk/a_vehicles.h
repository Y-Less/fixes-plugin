#ifndef SAMPGDK_A_VEHICLES_H
#define SAMPGDK_A_VEHICLES_H

#include <sampgdk/bool.h>
#include <sampgdk/export.h>
#include <sampgdk/types.h>

#define CARMODTYPE_SPOILER (0)
#define CARMODTYPE_HOOD (1)
#define CARMODTYPE_ROOF (2)
#define CARMODTYPE_SIDESKIRT (3)
#define CARMODTYPE_LAMPS (4)
#define CARMODTYPE_NITRO (5)
#define CARMODTYPE_EXHAUST (6)
#define CARMODTYPE_WHEELS (7)
#define CARMODTYPE_STEREO (8)
#define CARMODTYPE_HYDRAULICS (9)
#define CARMODTYPE_FRONT_BUMPER (10)
#define CARMODTYPE_REAR_BUMPER (11)
#define CARMODTYPE_VENT_RIGHT (12)
#define CARMODTYPE_VENT_LEFT (13)
#define VEHICLE_PARAMS_UNSET (-1)
#define VEHICLE_PARAMS_OFF (0)
#define VEHICLE_PARAMS_ON (1)
#define VEHICLE_MODEL_INFO_SIZE (1)
#define VEHICLE_MODEL_INFO_FRONTSEAT (2)
#define VEHICLE_MODEL_INFO_REARSEAT (3)
#define VEHICLE_MODEL_INFO_PETROLCAP (4)
#define VEHICLE_MODEL_INFO_WHEELSFRONT (5)
#define VEHICLE_MODEL_INFO_WHEELSREAR (6)
#define VEHICLE_MODEL_INFO_WHEELSMID (7)
#define VEHICLE_MODEL_INFO_FRONT_BUMPER_Z (8)
#define VEHICLE_MODEL_INFO_REAR_BUMPER_Z (9)

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/IsValidVehicle">IsValidVehicle on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, IsValidVehicle(int vehicleid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetVehicleDistanceFromPoint">GetVehicleDistanceFromPoint on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(float, GetVehicleDistanceFromPoint(int vehicleid, float x, float y, float z));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/CreateVehicle">CreateVehicle on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, CreateVehicle(int vehicletype, float x, float y, float z, float rotation, int color1, int color2, int respawn_delay, bool addsiren));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/DestroyVehicle">DestroyVehicle on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, DestroyVehicle(int vehicleid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/IsVehicleStreamedIn">IsVehicleStreamedIn on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, IsVehicleStreamedIn(int vehicleid, int forplayerid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetVehiclePos">GetVehiclePos on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GetVehiclePos(int vehicleid, float * x, float * y, float * z));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetVehiclePos">SetVehiclePos on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetVehiclePos(int vehicleid, float x, float y, float z));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetVehicleZAngle">GetVehicleZAngle on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GetVehicleZAngle(int vehicleid, float * z_angle));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetVehicleRotationQuat">GetVehicleRotationQuat on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GetVehicleRotationQuat(int vehicleid, float * w, float * x, float * y, float * z));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetVehicleZAngle">SetVehicleZAngle on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetVehicleZAngle(int vehicleid, float z_angle));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetVehicleParamsForPlayer">SetVehicleParamsForPlayer on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetVehicleParamsForPlayer(int vehicleid, int playerid, int objective, int doorslocked));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/ManualVehicleEngineAndLights">ManualVehicleEngineAndLights on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, ManualVehicleEngineAndLights());

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetVehicleParamsEx">SetVehicleParamsEx on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetVehicleParamsEx(int vehicleid, int engine, int lights, int alarm, int doors, int bonnet, int boot, int objective));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetVehicleParamsEx">GetVehicleParamsEx on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GetVehicleParamsEx(int vehicleid, int * engine, int * lights, int * alarm, int * doors, int * bonnet, int * boot, int * objective));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetVehicleParamsSirenState">GetVehicleParamsSirenState on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, GetVehicleParamsSirenState(int vehicleid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetVehicleParamsCarDoors">SetVehicleParamsCarDoors on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetVehicleParamsCarDoors(int vehicleid, int driver, int passenger, int backleft, int backright));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetVehicleParamsCarDoors">GetVehicleParamsCarDoors on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GetVehicleParamsCarDoors(int vehicleid, int * driver, int * passenger, int * backleft, int * backright));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetVehicleParamsCarWindows">SetVehicleParamsCarWindows on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetVehicleParamsCarWindows(int vehicleid, int driver, int passenger, int backleft, int backright));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetVehicleParamsCarWindows">GetVehicleParamsCarWindows on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GetVehicleParamsCarWindows(int vehicleid, int * driver, int * passenger, int * backleft, int * backright));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetVehicleToRespawn">SetVehicleToRespawn on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetVehicleToRespawn(int vehicleid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/LinkVehicleToInterior">LinkVehicleToInterior on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, LinkVehicleToInterior(int vehicleid, int interiorid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/AddVehicleComponent">AddVehicleComponent on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, AddVehicleComponent(int vehicleid, int componentid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/RemoveVehicleComponent">RemoveVehicleComponent on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, RemoveVehicleComponent(int vehicleid, int componentid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/ChangeVehicleColor">ChangeVehicleColor on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, ChangeVehicleColor(int vehicleid, int color1, int color2));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/ChangeVehiclePaintjob">ChangeVehiclePaintjob on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, ChangeVehiclePaintjob(int vehicleid, int paintjobid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetVehicleHealth">SetVehicleHealth on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetVehicleHealth(int vehicleid, float health));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetVehicleHealth">GetVehicleHealth on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GetVehicleHealth(int vehicleid, float * health));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/AttachTrailerToVehicle">AttachTrailerToVehicle on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, AttachTrailerToVehicle(int trailerid, int vehicleid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/DetachTrailerFromVehicle">DetachTrailerFromVehicle on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, DetachTrailerFromVehicle(int vehicleid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/IsTrailerAttachedToVehicle">IsTrailerAttachedToVehicle on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, IsTrailerAttachedToVehicle(int vehicleid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetVehicleTrailer">GetVehicleTrailer on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, GetVehicleTrailer(int vehicleid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetVehicleNumberPlate">SetVehicleNumberPlate on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetVehicleNumberPlate(int vehicleid, const char * numberplate));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetVehicleModel">GetVehicleModel on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, GetVehicleModel(int vehicleid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetVehicleComponentInSlot">GetVehicleComponentInSlot on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, GetVehicleComponentInSlot(int vehicleid, int slot));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetVehicleComponentType">GetVehicleComponentType on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, GetVehicleComponentType(int component));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/RepairVehicle">RepairVehicle on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, RepairVehicle(int vehicleid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetVehicleVelocity">GetVehicleVelocity on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GetVehicleVelocity(int vehicleid, float * X, float * Y, float * Z));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetVehicleVelocity">SetVehicleVelocity on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetVehicleVelocity(int vehicleid, float X, float Y, float Z));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetVehicleAngularVelocity">SetVehicleAngularVelocity on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetVehicleAngularVelocity(int vehicleid, float X, float Y, float Z));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetVehicleDamageStatus">GetVehicleDamageStatus on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GetVehicleDamageStatus(int vehicleid, int * panels, int * doors, int * lights, int * tires));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/UpdateVehicleDamageStatus">UpdateVehicleDamageStatus on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, UpdateVehicleDamageStatus(int vehicleid, int panels, int doors, int lights, int tires));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetVehicleVirtualWorld">SetVehicleVirtualWorld on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetVehicleVirtualWorld(int vehicleid, int worldid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetVehicleVirtualWorld">GetVehicleVirtualWorld on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, GetVehicleVirtualWorld(int vehicleid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetVehicleModelInfo">GetVehicleModelInfo on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GetVehicleModelInfo(int model, int infotype, float * X, float * Y, float * Z));

#ifndef DOXYGEN

#if defined SAMPGDK_CPP_WRAPPERS && !defined IN_SAMPGDK

namespace sampgdk {

inline bool IsValidVehicle(int vehicleid) {
  return sampgdk_IsValidVehicle(vehicleid);
}

inline float GetVehicleDistanceFromPoint(int vehicleid, float x, float y, float z) {
  return sampgdk_GetVehicleDistanceFromPoint(vehicleid, x, y, z);
}

inline int CreateVehicle(int vehicletype, float x, float y, float z, float rotation, int color1, int color2, int respawn_delay, bool addsiren = false) {
  return sampgdk_CreateVehicle(vehicletype, x, y, z, rotation, color1, color2, respawn_delay, addsiren);
}

inline bool DestroyVehicle(int vehicleid) {
  return sampgdk_DestroyVehicle(vehicleid);
}

inline bool IsVehicleStreamedIn(int vehicleid, int forplayerid) {
  return sampgdk_IsVehicleStreamedIn(vehicleid, forplayerid);
}

inline bool GetVehiclePos(int vehicleid, float * x, float * y, float * z) {
  return sampgdk_GetVehiclePos(vehicleid, x, y, z);
}

inline bool SetVehiclePos(int vehicleid, float x, float y, float z) {
  return sampgdk_SetVehiclePos(vehicleid, x, y, z);
}

inline bool GetVehicleZAngle(int vehicleid, float * z_angle) {
  return sampgdk_GetVehicleZAngle(vehicleid, z_angle);
}

inline bool GetVehicleRotationQuat(int vehicleid, float * w, float * x, float * y, float * z) {
  return sampgdk_GetVehicleRotationQuat(vehicleid, w, x, y, z);
}

inline bool SetVehicleZAngle(int vehicleid, float z_angle) {
  return sampgdk_SetVehicleZAngle(vehicleid, z_angle);
}

inline bool SetVehicleParamsForPlayer(int vehicleid, int playerid, int objective, int doorslocked) {
  return sampgdk_SetVehicleParamsForPlayer(vehicleid, playerid, objective, doorslocked);
}

inline bool ManualVehicleEngineAndLights() {
  return sampgdk_ManualVehicleEngineAndLights();
}

inline bool SetVehicleParamsEx(int vehicleid, int engine, int lights, int alarm, int doors, int bonnet, int boot, int objective) {
  return sampgdk_SetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
}

inline bool GetVehicleParamsEx(int vehicleid, int * engine, int * lights, int * alarm, int * doors, int * bonnet, int * boot, int * objective) {
  return sampgdk_GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
}

inline int GetVehicleParamsSirenState(int vehicleid) {
  return sampgdk_GetVehicleParamsSirenState(vehicleid);
}

inline bool SetVehicleParamsCarDoors(int vehicleid, int driver, int passenger, int backleft, int backright) {
  return sampgdk_SetVehicleParamsCarDoors(vehicleid, driver, passenger, backleft, backright);
}

inline bool GetVehicleParamsCarDoors(int vehicleid, int * driver, int * passenger, int * backleft, int * backright) {
  return sampgdk_GetVehicleParamsCarDoors(vehicleid, driver, passenger, backleft, backright);
}

inline bool SetVehicleParamsCarWindows(int vehicleid, int driver, int passenger, int backleft, int backright) {
  return sampgdk_SetVehicleParamsCarWindows(vehicleid, driver, passenger, backleft, backright);
}

inline bool GetVehicleParamsCarWindows(int vehicleid, int * driver, int * passenger, int * backleft, int * backright) {
  return sampgdk_GetVehicleParamsCarWindows(vehicleid, driver, passenger, backleft, backright);
}

inline bool SetVehicleToRespawn(int vehicleid) {
  return sampgdk_SetVehicleToRespawn(vehicleid);
}

inline bool LinkVehicleToInterior(int vehicleid, int interiorid) {
  return sampgdk_LinkVehicleToInterior(vehicleid, interiorid);
}

inline bool AddVehicleComponent(int vehicleid, int componentid) {
  return sampgdk_AddVehicleComponent(vehicleid, componentid);
}

inline bool RemoveVehicleComponent(int vehicleid, int componentid) {
  return sampgdk_RemoveVehicleComponent(vehicleid, componentid);
}

inline bool ChangeVehicleColor(int vehicleid, int color1, int color2) {
  return sampgdk_ChangeVehicleColor(vehicleid, color1, color2);
}

inline bool ChangeVehiclePaintjob(int vehicleid, int paintjobid) {
  return sampgdk_ChangeVehiclePaintjob(vehicleid, paintjobid);
}

inline bool SetVehicleHealth(int vehicleid, float health) {
  return sampgdk_SetVehicleHealth(vehicleid, health);
}

inline bool GetVehicleHealth(int vehicleid, float * health) {
  return sampgdk_GetVehicleHealth(vehicleid, health);
}

inline bool AttachTrailerToVehicle(int trailerid, int vehicleid) {
  return sampgdk_AttachTrailerToVehicle(trailerid, vehicleid);
}

inline bool DetachTrailerFromVehicle(int vehicleid) {
  return sampgdk_DetachTrailerFromVehicle(vehicleid);
}

inline bool IsTrailerAttachedToVehicle(int vehicleid) {
  return sampgdk_IsTrailerAttachedToVehicle(vehicleid);
}

inline int GetVehicleTrailer(int vehicleid) {
  return sampgdk_GetVehicleTrailer(vehicleid);
}

inline bool SetVehicleNumberPlate(int vehicleid, const char * numberplate) {
  return sampgdk_SetVehicleNumberPlate(vehicleid, numberplate);
}

inline int GetVehicleModel(int vehicleid) {
  return sampgdk_GetVehicleModel(vehicleid);
}

inline int GetVehicleComponentInSlot(int vehicleid, int slot) {
  return sampgdk_GetVehicleComponentInSlot(vehicleid, slot);
}

inline int GetVehicleComponentType(int component) {
  return sampgdk_GetVehicleComponentType(component);
}

inline bool RepairVehicle(int vehicleid) {
  return sampgdk_RepairVehicle(vehicleid);
}

inline bool GetVehicleVelocity(int vehicleid, float * X, float * Y, float * Z) {
  return sampgdk_GetVehicleVelocity(vehicleid, X, Y, Z);
}

inline bool SetVehicleVelocity(int vehicleid, float X, float Y, float Z) {
  return sampgdk_SetVehicleVelocity(vehicleid, X, Y, Z);
}

inline bool SetVehicleAngularVelocity(int vehicleid, float X, float Y, float Z) {
  return sampgdk_SetVehicleAngularVelocity(vehicleid, X, Y, Z);
}

inline bool GetVehicleDamageStatus(int vehicleid, int * panels, int * doors, int * lights, int * tires) {
  return sampgdk_GetVehicleDamageStatus(vehicleid, panels, doors, lights, tires);
}

inline bool UpdateVehicleDamageStatus(int vehicleid, int panels, int doors, int lights, int tires) {
  return sampgdk_UpdateVehicleDamageStatus(vehicleid, panels, doors, lights, tires);
}

inline bool SetVehicleVirtualWorld(int vehicleid, int worldid) {
  return sampgdk_SetVehicleVirtualWorld(vehicleid, worldid);
}

inline int GetVehicleVirtualWorld(int vehicleid) {
  return sampgdk_GetVehicleVirtualWorld(vehicleid);
}

inline bool GetVehicleModelInfo(int model, int infotype, float * X, float * Y, float * Z) {
  return sampgdk_GetVehicleModelInfo(model, infotype, X, Y, Z);
}

} // namespace sampgdk

#else /* SAMPGDK_CPP_WRAPPERS && !IN_SAMPGDK */

#undef  IsValidVehicle
#define IsValidVehicle sampgdk_IsValidVehicle

#undef  GetVehicleDistanceFromPoint
#define GetVehicleDistanceFromPoint sampgdk_GetVehicleDistanceFromPoint

#undef  CreateVehicle
#define CreateVehicle sampgdk_CreateVehicle

#undef  DestroyVehicle
#define DestroyVehicle sampgdk_DestroyVehicle

#undef  IsVehicleStreamedIn
#define IsVehicleStreamedIn sampgdk_IsVehicleStreamedIn

#undef  GetVehiclePos
#define GetVehiclePos sampgdk_GetVehiclePos

#undef  SetVehiclePos
#define SetVehiclePos sampgdk_SetVehiclePos

#undef  GetVehicleZAngle
#define GetVehicleZAngle sampgdk_GetVehicleZAngle

#undef  GetVehicleRotationQuat
#define GetVehicleRotationQuat sampgdk_GetVehicleRotationQuat

#undef  SetVehicleZAngle
#define SetVehicleZAngle sampgdk_SetVehicleZAngle

#undef  SetVehicleParamsForPlayer
#define SetVehicleParamsForPlayer sampgdk_SetVehicleParamsForPlayer

#undef  ManualVehicleEngineAndLights
#define ManualVehicleEngineAndLights sampgdk_ManualVehicleEngineAndLights

#undef  SetVehicleParamsEx
#define SetVehicleParamsEx sampgdk_SetVehicleParamsEx

#undef  GetVehicleParamsEx
#define GetVehicleParamsEx sampgdk_GetVehicleParamsEx

#undef  GetVehicleParamsSirenState
#define GetVehicleParamsSirenState sampgdk_GetVehicleParamsSirenState

#undef  SetVehicleParamsCarDoors
#define SetVehicleParamsCarDoors sampgdk_SetVehicleParamsCarDoors

#undef  GetVehicleParamsCarDoors
#define GetVehicleParamsCarDoors sampgdk_GetVehicleParamsCarDoors

#undef  SetVehicleParamsCarWindows
#define SetVehicleParamsCarWindows sampgdk_SetVehicleParamsCarWindows

#undef  GetVehicleParamsCarWindows
#define GetVehicleParamsCarWindows sampgdk_GetVehicleParamsCarWindows

#undef  SetVehicleToRespawn
#define SetVehicleToRespawn sampgdk_SetVehicleToRespawn

#undef  LinkVehicleToInterior
#define LinkVehicleToInterior sampgdk_LinkVehicleToInterior

#undef  AddVehicleComponent
#define AddVehicleComponent sampgdk_AddVehicleComponent

#undef  RemoveVehicleComponent
#define RemoveVehicleComponent sampgdk_RemoveVehicleComponent

#undef  ChangeVehicleColor
#define ChangeVehicleColor sampgdk_ChangeVehicleColor

#undef  ChangeVehiclePaintjob
#define ChangeVehiclePaintjob sampgdk_ChangeVehiclePaintjob

#undef  SetVehicleHealth
#define SetVehicleHealth sampgdk_SetVehicleHealth

#undef  GetVehicleHealth
#define GetVehicleHealth sampgdk_GetVehicleHealth

#undef  AttachTrailerToVehicle
#define AttachTrailerToVehicle sampgdk_AttachTrailerToVehicle

#undef  DetachTrailerFromVehicle
#define DetachTrailerFromVehicle sampgdk_DetachTrailerFromVehicle

#undef  IsTrailerAttachedToVehicle
#define IsTrailerAttachedToVehicle sampgdk_IsTrailerAttachedToVehicle

#undef  GetVehicleTrailer
#define GetVehicleTrailer sampgdk_GetVehicleTrailer

#undef  SetVehicleNumberPlate
#define SetVehicleNumberPlate sampgdk_SetVehicleNumberPlate

#undef  GetVehicleModel
#define GetVehicleModel sampgdk_GetVehicleModel

#undef  GetVehicleComponentInSlot
#define GetVehicleComponentInSlot sampgdk_GetVehicleComponentInSlot

#undef  GetVehicleComponentType
#define GetVehicleComponentType sampgdk_GetVehicleComponentType

#undef  RepairVehicle
#define RepairVehicle sampgdk_RepairVehicle

#undef  GetVehicleVelocity
#define GetVehicleVelocity sampgdk_GetVehicleVelocity

#undef  SetVehicleVelocity
#define SetVehicleVelocity sampgdk_SetVehicleVelocity

#undef  SetVehicleAngularVelocity
#define SetVehicleAngularVelocity sampgdk_SetVehicleAngularVelocity

#undef  GetVehicleDamageStatus
#define GetVehicleDamageStatus sampgdk_GetVehicleDamageStatus

#undef  UpdateVehicleDamageStatus
#define UpdateVehicleDamageStatus sampgdk_UpdateVehicleDamageStatus

#undef  SetVehicleVirtualWorld
#define SetVehicleVirtualWorld sampgdk_SetVehicleVirtualWorld

#undef  GetVehicleVirtualWorld
#define GetVehicleVirtualWorld sampgdk_GetVehicleVirtualWorld

#undef  GetVehicleModelInfo
#define GetVehicleModelInfo sampgdk_GetVehicleModelInfo

#endif /* !SAMPGDK_CPP_WRAPPERS || IN_SAMPGDK */
#endif /* !DOXYGEN */

#endif /* !SAMPGDK_A_VEHICLES_H */
