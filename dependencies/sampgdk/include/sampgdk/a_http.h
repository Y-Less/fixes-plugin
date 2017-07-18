#ifndef SAMPGDK_A_HTTP_H
#define SAMPGDK_A_HTTP_H

#include <sampgdk/bool.h>
#include <sampgdk/export.h>
#include <sampgdk/types.h>

#define HTTP_GET (1)
#define HTTP_POST (2)
#define HTTP_HEAD (3)
#define HTTP_ERROR_BAD_HOST (1)
#define HTTP_ERROR_NO_SOCKET (2)
#define HTTP_ERROR_CANT_CONNECT (3)
#define HTTP_ERROR_CANT_WRITE (4)
#define HTTP_ERROR_CONTENT_TOO_BIG (5)
#define HTTP_ERROR_MALFORMED_RESPONSE (6)

/**
 * \ingroup natives
 * \see <a href="http://wiki.sa-mp.com/wiki/HTTP">HTTP on SA-MP Wiki</a>
 */
SAMPGDK_NATIVE(bool, HTTP(int index, int type, const char * url, const char * data));

#ifndef DOXYGEN

#if defined SAMPGDK_CPP_WRAPPERS && !defined IN_SAMPGDK

namespace sampgdk {

inline bool HTTP(int index, int type, const char * url, const char * data) {
  return sampgdk_HTTP(index, type, url, data);
}

} // namespace sampgdk

#else /* SAMPGDK_CPP_WRAPPERS && !IN_SAMPGDK */

#undef  HTTP
#define HTTP sampgdk_HTTP

#endif /* !SAMPGDK_CPP_WRAPPERS || IN_SAMPGDK */
#endif /* !DOXYGEN */

SAMPGDK_CALLBACK(void, OnHTTPResponse(int index, int response_code, const char * data));

#endif /* !SAMPGDK_A_HTTP_H */
