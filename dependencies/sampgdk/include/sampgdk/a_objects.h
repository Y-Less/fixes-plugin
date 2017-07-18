#ifndef SAMPGDK_A_OBJECTS_H
#define SAMPGDK_A_OBJECTS_H

#include <sampgdk/bool.h>
#include <sampgdk/export.h>
#include <sampgdk/types.h>

#define OBJECT_MATERIAL_SIZE_32x32 (10)
#define OBJECT_MATERIAL_SIZE_64x32 (20)
#define OBJECT_MATERIAL_SIZE_64x64 (30)
#define OBJECT_MATERIAL_SIZE_128x32 (40)
#define OBJECT_MATERIAL_SIZE_128x64 (50)
#define OBJECT_MATERIAL_SIZE_128x128 (60)
#define OBJECT_MATERIAL_SIZE_256x32 (70)
#define OBJECT_MATERIAL_SIZE_256x64 (80)
#define OBJECT_MATERIAL_SIZE_256x128 (90)
#define OBJECT_MATERIAL_SIZE_256x256 (100)
#define OBJECT_MATERIAL_SIZE_512x64 (110)
#define OBJECT_MATERIAL_SIZE_512x128 (120)
#define OBJECT_MATERIAL_SIZE_512x256 (130)
#define OBJECT_MATERIAL_SIZE_512x512 (140)
#define OBJECT_MATERIAL_TEXT_ALIGN_LEFT (0)
#define OBJECT_MATERIAL_TEXT_ALIGN_CENTER (1)
#define OBJECT_MATERIAL_TEXT_ALIGN_RIGHT (2)

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/CreateObject">CreateObject on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, CreateObject(int modelid, float x, float y, float z, float rX, float rY, float rZ, float DrawDistance));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/AttachObjectToVehicle">AttachObjectToVehicle on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, AttachObjectToVehicle(int objectid, int vehicleid, float fOffsetX, float fOffsetY, float fOffsetZ, float fRotX, float fRotY, float fRotZ));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/AttachObjectToObject">AttachObjectToObject on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, AttachObjectToObject(int objectid, int attachtoid, float fOffsetX, float fOffsetY, float fOffsetZ, float fRotX, float fRotY, float fRotZ, bool SyncRotation));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/AttachObjectToPlayer">AttachObjectToPlayer on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, AttachObjectToPlayer(int objectid, int playerid, float fOffsetX, float fOffsetY, float fOffsetZ, float fRotX, float fRotY, float fRotZ));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetObjectPos">SetObjectPos on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetObjectPos(int objectid, float x, float y, float z));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetObjectPos">GetObjectPos on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GetObjectPos(int objectid, float * x, float * y, float * z));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetObjectRot">SetObjectRot on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetObjectRot(int objectid, float rotX, float rotY, float rotZ));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetObjectRot">GetObjectRot on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GetObjectRot(int objectid, float * rotX, float * rotY, float * rotZ));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetObjectModel">GetObjectModel on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, GetObjectModel(int objectid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetObjectNoCameraCol">SetObjectNoCameraCol on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetObjectNoCameraCol(int objectid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/IsValidObject">IsValidObject on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, IsValidObject(int objectid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/DestroyObject">DestroyObject on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, DestroyObject(int objectid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/MoveObject">MoveObject on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, MoveObject(int objectid, float X, float Y, float Z, float Speed, float RotX, float RotY, float RotZ));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/StopObject">StopObject on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, StopObject(int objectid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/IsObjectMoving">IsObjectMoving on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, IsObjectMoving(int objectid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/EditObject">EditObject on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, EditObject(int playerid, int objectid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/EditPlayerObject">EditPlayerObject on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, EditPlayerObject(int playerid, int objectid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SelectObject">SelectObject on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SelectObject(int playerid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/CancelEdit">CancelEdit on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, CancelEdit(int playerid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/CreatePlayerObject">CreatePlayerObject on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, CreatePlayerObject(int playerid, int modelid, float x, float y, float z, float rX, float rY, float rZ, float DrawDistance));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/AttachPlayerObjectToPlayer">AttachPlayerObjectToPlayer on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, AttachPlayerObjectToPlayer(int objectplayer, int objectid, int attachplayer, float OffsetX, float OffsetY, float OffsetZ, float rX, float rY, float rZ));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/AttachPlayerObjectToVehicle">AttachPlayerObjectToVehicle on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, AttachPlayerObjectToVehicle(int playerid, int objectid, int vehicleid, float fOffsetX, float fOffsetY, float fOffsetZ, float fRotX, float fRotY, float RotZ));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetPlayerObjectPos">SetPlayerObjectPos on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetPlayerObjectPos(int playerid, int objectid, float x, float y, float z));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetPlayerObjectPos">GetPlayerObjectPos on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GetPlayerObjectPos(int playerid, int objectid, float * x, float * y, float * z));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetPlayerObjectRot">SetPlayerObjectRot on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetPlayerObjectRot(int playerid, int objectid, float rotX, float rotY, float rotZ));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetPlayerObjectRot">GetPlayerObjectRot on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, GetPlayerObjectRot(int playerid, int objectid, float * rotX, float * rotY, float * rotZ));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/GetPlayerObjectModel">GetPlayerObjectModel on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, GetPlayerObjectModel(int playerid, int objectid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetPlayerObjectNoCameraCol">SetPlayerObjectNoCameraCol on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetPlayerObjectNoCameraCol(int playerid, int objectid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/IsValidPlayerObject">IsValidPlayerObject on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, IsValidPlayerObject(int playerid, int objectid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/DestroyPlayerObject">DestroyPlayerObject on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, DestroyPlayerObject(int playerid, int objectid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/MovePlayerObject">MovePlayerObject on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(int, MovePlayerObject(int playerid, int objectid, float x, float y, float z, float Speed, float RotX, float RotY, float RotZ));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/StopPlayerObject">StopPlayerObject on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, StopPlayerObject(int playerid, int objectid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/IsPlayerObjectMoving">IsPlayerObjectMoving on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, IsPlayerObjectMoving(int playerid, int objectid));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetObjectMaterial">SetObjectMaterial on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetObjectMaterial(int objectid, int materialindex, int modelid, const char * txdname, const char * texturename, int materialcolor));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetPlayerObjectMaterial">SetPlayerObjectMaterial on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetPlayerObjectMaterial(int playerid, int objectid, int materialindex, int modelid, const char * txdname, const char * texturename, int materialcolor));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetObjectMaterialText">SetObjectMaterialText on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetObjectMaterialText(int objectid, const char * text, int materialindex, int materialsize, const char * fontface, int fontsize, bool bold, int fontcolor, int backcolor, int textalignment));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetPlayerObjectMaterialText">SetPlayerObjectMaterialText on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetPlayerObjectMaterialText(int playerid, int objectid, const char * text, int materialindex, int materialsize, const char * fontface, int fontsize, bool bold, int fontcolor, int backcolor, int textalignment));

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/SetObjectsDefaultCameraCol">SetObjectsDefaultCameraCol on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, SetObjectsDefaultCameraCol(bool disable));

#ifndef DOXYGEN

#if defined SAMPGDK_CPP_WRAPPERS && !defined IN_SAMPGDK

namespace sampgdk {

inline int CreateObject(int modelid, float x, float y, float z, float rX, float rY, float rZ, float DrawDistance = 0.0) {
  return sampgdk_CreateObject(modelid, x, y, z, rX, rY, rZ, DrawDistance);
}

inline bool AttachObjectToVehicle(int objectid, int vehicleid, float fOffsetX, float fOffsetY, float fOffsetZ, float fRotX, float fRotY, float fRotZ) {
  return sampgdk_AttachObjectToVehicle(objectid, vehicleid, fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ);
}

inline bool AttachObjectToObject(int objectid, int attachtoid, float fOffsetX, float fOffsetY, float fOffsetZ, float fRotX, float fRotY, float fRotZ, bool SyncRotation = false) {
  return sampgdk_AttachObjectToObject(objectid, attachtoid, fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ, SyncRotation);
}

inline bool AttachObjectToPlayer(int objectid, int playerid, float fOffsetX, float fOffsetY, float fOffsetZ, float fRotX, float fRotY, float fRotZ) {
  return sampgdk_AttachObjectToPlayer(objectid, playerid, fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ);
}

inline bool SetObjectPos(int objectid, float x, float y, float z) {
  return sampgdk_SetObjectPos(objectid, x, y, z);
}

inline bool GetObjectPos(int objectid, float * x, float * y, float * z) {
  return sampgdk_GetObjectPos(objectid, x, y, z);
}

inline bool SetObjectRot(int objectid, float rotX, float rotY, float rotZ) {
  return sampgdk_SetObjectRot(objectid, rotX, rotY, rotZ);
}

inline bool GetObjectRot(int objectid, float * rotX, float * rotY, float * rotZ) {
  return sampgdk_GetObjectRot(objectid, rotX, rotY, rotZ);
}

inline int GetObjectModel(int objectid) {
  return sampgdk_GetObjectModel(objectid);
}

inline bool SetObjectNoCameraCol(int objectid) {
  return sampgdk_SetObjectNoCameraCol(objectid);
}

inline bool IsValidObject(int objectid) {
  return sampgdk_IsValidObject(objectid);
}

inline bool DestroyObject(int objectid) {
  return sampgdk_DestroyObject(objectid);
}

inline int MoveObject(int objectid, float X, float Y, float Z, float Speed, float RotX = -1000.0, float RotY = -1000.0, float RotZ = -1000.0) {
  return sampgdk_MoveObject(objectid, X, Y, Z, Speed, RotX, RotY, RotZ);
}

inline bool StopObject(int objectid) {
  return sampgdk_StopObject(objectid);
}

inline bool IsObjectMoving(int objectid) {
  return sampgdk_IsObjectMoving(objectid);
}

inline bool EditObject(int playerid, int objectid) {
  return sampgdk_EditObject(playerid, objectid);
}

inline bool EditPlayerObject(int playerid, int objectid) {
  return sampgdk_EditPlayerObject(playerid, objectid);
}

inline bool SelectObject(int playerid) {
  return sampgdk_SelectObject(playerid);
}

inline bool CancelEdit(int playerid) {
  return sampgdk_CancelEdit(playerid);
}

inline int CreatePlayerObject(int playerid, int modelid, float x, float y, float z, float rX, float rY, float rZ, float DrawDistance = 0.0) {
  return sampgdk_CreatePlayerObject(playerid, modelid, x, y, z, rX, rY, rZ, DrawDistance);
}

inline bool AttachPlayerObjectToPlayer(int objectplayer, int objectid, int attachplayer, float OffsetX, float OffsetY, float OffsetZ, float rX, float rY, float rZ) {
  return sampgdk_AttachPlayerObjectToPlayer(objectplayer, objectid, attachplayer, OffsetX, OffsetY, OffsetZ, rX, rY, rZ);
}

inline bool AttachPlayerObjectToVehicle(int playerid, int objectid, int vehicleid, float fOffsetX, float fOffsetY, float fOffsetZ, float fRotX, float fRotY, float RotZ) {
  return sampgdk_AttachPlayerObjectToVehicle(playerid, objectid, vehicleid, fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, RotZ);
}

inline bool SetPlayerObjectPos(int playerid, int objectid, float x, float y, float z) {
  return sampgdk_SetPlayerObjectPos(playerid, objectid, x, y, z);
}

inline bool GetPlayerObjectPos(int playerid, int objectid, float * x, float * y, float * z) {
  return sampgdk_GetPlayerObjectPos(playerid, objectid, x, y, z);
}

inline bool SetPlayerObjectRot(int playerid, int objectid, float rotX, float rotY, float rotZ) {
  return sampgdk_SetPlayerObjectRot(playerid, objectid, rotX, rotY, rotZ);
}

inline bool GetPlayerObjectRot(int playerid, int objectid, float * rotX, float * rotY, float * rotZ) {
  return sampgdk_GetPlayerObjectRot(playerid, objectid, rotX, rotY, rotZ);
}

inline int GetPlayerObjectModel(int playerid, int objectid) {
  return sampgdk_GetPlayerObjectModel(playerid, objectid);
}

inline bool SetPlayerObjectNoCameraCol(int playerid, int objectid) {
  return sampgdk_SetPlayerObjectNoCameraCol(playerid, objectid);
}

inline bool IsValidPlayerObject(int playerid, int objectid) {
  return sampgdk_IsValidPlayerObject(playerid, objectid);
}

inline bool DestroyPlayerObject(int playerid, int objectid) {
  return sampgdk_DestroyPlayerObject(playerid, objectid);
}

inline int MovePlayerObject(int playerid, int objectid, float x, float y, float z, float Speed, float RotX = -1000.0, float RotY = -1000.0, float RotZ = -1000.0) {
  return sampgdk_MovePlayerObject(playerid, objectid, x, y, z, Speed, RotX, RotY, RotZ);
}

inline bool StopPlayerObject(int playerid, int objectid) {
  return sampgdk_StopPlayerObject(playerid, objectid);
}

inline bool IsPlayerObjectMoving(int playerid, int objectid) {
  return sampgdk_IsPlayerObjectMoving(playerid, objectid);
}

inline bool SetObjectMaterial(int objectid, int materialindex, int modelid, const char * txdname, const char * texturename, int materialcolor = 0) {
  return sampgdk_SetObjectMaterial(objectid, materialindex, modelid, txdname, texturename, materialcolor);
}

inline bool SetPlayerObjectMaterial(int playerid, int objectid, int materialindex, int modelid, const char * txdname, const char * texturename, int materialcolor = 0) {
  return sampgdk_SetPlayerObjectMaterial(playerid, objectid, materialindex, modelid, txdname, texturename, materialcolor);
}

inline bool SetObjectMaterialText(int objectid, const char * text, int materialindex = 0, int materialsize = OBJECT_MATERIAL_SIZE_256x128, const char * fontface = "Arial", int fontsize = 24, bool bold = true, int fontcolor = 0xFFFFFFFFL, int backcolor = 0, int textalignment = 0) {
  return sampgdk_SetObjectMaterialText(objectid, text, materialindex, materialsize, fontface, fontsize, bold, fontcolor, backcolor, textalignment);
}

inline bool SetPlayerObjectMaterialText(int playerid, int objectid, const char * text, int materialindex = 0, int materialsize = OBJECT_MATERIAL_SIZE_256x128, const char * fontface = "Arial", int fontsize = 24, bool bold = true, int fontcolor = 0xFFFFFFFFL, int backcolor = 0, int textalignment = 0) {
  return sampgdk_SetPlayerObjectMaterialText(playerid, objectid, text, materialindex, materialsize, fontface, fontsize, bold, fontcolor, backcolor, textalignment);
}

inline bool SetObjectsDefaultCameraCol(bool disable) {
  return sampgdk_SetObjectsDefaultCameraCol(disable);
}

} // namespace sampgdk

#else /* SAMPGDK_CPP_WRAPPERS && !IN_SAMPGDK */

#undef  CreateObject
#define CreateObject sampgdk_CreateObject

#undef  AttachObjectToVehicle
#define AttachObjectToVehicle sampgdk_AttachObjectToVehicle

#undef  AttachObjectToObject
#define AttachObjectToObject sampgdk_AttachObjectToObject

#undef  AttachObjectToPlayer
#define AttachObjectToPlayer sampgdk_AttachObjectToPlayer

#undef  SetObjectPos
#define SetObjectPos sampgdk_SetObjectPos

#undef  GetObjectPos
#define GetObjectPos sampgdk_GetObjectPos

#undef  SetObjectRot
#define SetObjectRot sampgdk_SetObjectRot

#undef  GetObjectRot
#define GetObjectRot sampgdk_GetObjectRot

#undef  GetObjectModel
#define GetObjectModel sampgdk_GetObjectModel

#undef  SetObjectNoCameraCol
#define SetObjectNoCameraCol sampgdk_SetObjectNoCameraCol

#undef  IsValidObject
#define IsValidObject sampgdk_IsValidObject

#undef  DestroyObject
#define DestroyObject sampgdk_DestroyObject

#undef  MoveObject
#define MoveObject sampgdk_MoveObject

#undef  StopObject
#define StopObject sampgdk_StopObject

#undef  IsObjectMoving
#define IsObjectMoving sampgdk_IsObjectMoving

#undef  EditObject
#define EditObject sampgdk_EditObject

#undef  EditPlayerObject
#define EditPlayerObject sampgdk_EditPlayerObject

#undef  SelectObject
#define SelectObject sampgdk_SelectObject

#undef  CancelEdit
#define CancelEdit sampgdk_CancelEdit

#undef  CreatePlayerObject
#define CreatePlayerObject sampgdk_CreatePlayerObject

#undef  AttachPlayerObjectToPlayer
#define AttachPlayerObjectToPlayer sampgdk_AttachPlayerObjectToPlayer

#undef  AttachPlayerObjectToVehicle
#define AttachPlayerObjectToVehicle sampgdk_AttachPlayerObjectToVehicle

#undef  SetPlayerObjectPos
#define SetPlayerObjectPos sampgdk_SetPlayerObjectPos

#undef  GetPlayerObjectPos
#define GetPlayerObjectPos sampgdk_GetPlayerObjectPos

#undef  SetPlayerObjectRot
#define SetPlayerObjectRot sampgdk_SetPlayerObjectRot

#undef  GetPlayerObjectRot
#define GetPlayerObjectRot sampgdk_GetPlayerObjectRot

#undef  GetPlayerObjectModel
#define GetPlayerObjectModel sampgdk_GetPlayerObjectModel

#undef  SetPlayerObjectNoCameraCol
#define SetPlayerObjectNoCameraCol sampgdk_SetPlayerObjectNoCameraCol

#undef  IsValidPlayerObject
#define IsValidPlayerObject sampgdk_IsValidPlayerObject

#undef  DestroyPlayerObject
#define DestroyPlayerObject sampgdk_DestroyPlayerObject

#undef  MovePlayerObject
#define MovePlayerObject sampgdk_MovePlayerObject

#undef  StopPlayerObject
#define StopPlayerObject sampgdk_StopPlayerObject

#undef  IsPlayerObjectMoving
#define IsPlayerObjectMoving sampgdk_IsPlayerObjectMoving

#undef  SetObjectMaterial
#define SetObjectMaterial sampgdk_SetObjectMaterial

#undef  SetPlayerObjectMaterial
#define SetPlayerObjectMaterial sampgdk_SetPlayerObjectMaterial

#undef  SetObjectMaterialText
#define SetObjectMaterialText sampgdk_SetObjectMaterialText

#undef  SetPlayerObjectMaterialText
#define SetPlayerObjectMaterialText sampgdk_SetPlayerObjectMaterialText

#undef  SetObjectsDefaultCameraCol
#define SetObjectsDefaultCameraCol sampgdk_SetObjectsDefaultCameraCol

#endif /* !SAMPGDK_CPP_WRAPPERS || IN_SAMPGDK */
#endif /* !DOXYGEN */

#endif /* !SAMPGDK_A_OBJECTS_H */
