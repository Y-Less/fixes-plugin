/* Copyright (C) 2011-2015 Zeex
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SAMPGDK_VERSION_H
#define SAMPGDK_VERSION_H

#include <sampgdk/export.h>

/**
 * \addtogroup version
 * @{
 */

/**
 * \brief Major version
 */
#define SAMPGDK_VERSION_MAJOR 4

/**
 * \brief Minor version
 */
#define SAMPGDK_VERSION_MINOR 5

/**
 * \brief Patch version
 */
#define SAMPGDK_VERSION_PATCH 2

/**
 * \brief Library version number in the form of \c 0xAABBCC00 where
 * \c AA, \c BB and \c CC are the major, minor and patch numbers
 */
#define SAMPGDK_VERSION_ID 67437056

/**
 * \brief Library version string in the form of \c x.y.z where \c x,
 * \c y and \c z are the major, minor and patch numbers
 */
#define SAMPGDK_VERSION_STRING "4.5.2"

/**
 * \brief Gets library version number
 *
 * \returns version number
 *
 * \see SAMPGDK_VERSION_ID
 * \see sampgdk_GetVersionString()
 */
SAMPGDK_API(int, sampgdk_GetVersion(void));

/**
 * \brief Gets library version string
 *
 * \returns version string
 *
 * \see SAMPGDK_VERSION_STRING
 * \see sampgdk_GetVersion()
 */
SAMPGDK_API(const char *, sampgdk_GetVersionString(void));

#ifdef __cplusplus

namespace sampgdk {

/// \brief C++ wrapper around sampgdk_GetVersion()
inline int GetVersion() {
  return sampgdk_GetVersion();
}

/// \brief C++ wrapper around sampgdk_GetVersionString()
inline const char *GetVersionString() {
  return sampgdk_GetVersionString();
}

} // namespace sampgdk

#endif /* __cplusplus */

/** @} */

#endif /* !SAMPGDK_VERSION_H */
