# Rebuild mdcm whenever a file starting with mdcm* is modified
include_regular_expression("^mdcm.*$")

# configure the .h file
option(MDCM_SUPPORT_BROKEN_IMPLEMENTATION "Handle broken DICOM" ON)
mark_as_advanced(MDCM_SUPPORT_BROKEN_IMPLEMENTATION)

CHECK_INCLUDE_FILE_CONCAT("sys/time.h" MDCM_HAVE_SYS_TIME_H)
CHECK_INCLUDE_FILE_CONCAT("winsock.h"  MDCM_HAVE_WINSOCK_H)
CHECK_INCLUDE_FILE_CONCAT("byteswap.h" MDCM_HAVE_BYTESWAP_FILE_H)
# see bug #324
if(MDCM_HAVE_BYTESWAP_FILE_H)
  include(CheckCXXSourceCompiles)
  CHECK_CXX_SOURCE_COMPILES(
    "\#include <byteswap.h>\nint main() { return bswap_32( 42 ); }"
    MDCM_HAVE_BYTESWAP_H)
endif()
CHECK_INCLUDE_FILE("rpc.h"      MDCM_HAVE_RPC_H)
CHECK_INCLUDE_FILE("langinfo.h" MDCM_HAVE_LANGINFO_H)

include(CheckFunctionExists)
# See http://public.kitware.com/Bug/view.php?id=8246
include(CheckSymbolExists)
CHECK_SYMBOL_EXISTS(nl_langinfo "langinfo.h" MDCM_HAVE_NL_LANGINFO)
#C99
#CHECK_FUNCTION_EXISTS(strcasecmp  MDCM_HAVE_STRCASECMP)
CHECK_SYMBOL_EXISTS(strcasecmp "strings.h" MDCM_HAVE_STRCASECMP)
#CHECK_FUNCTION_EXISTS(strncasecmp MDCM_HAVE_STRNCASECMP)
CHECK_SYMBOL_EXISTS(strncasecmp "strings.h" MDCM_HAVE_STRNCASECMP)
#CHECK_FUNCTION_EXISTS(snprintf MDCM_HAVE_SNPRINTF)
CHECK_SYMBOL_EXISTS(snprintf "stdio.h" MDCM_HAVE_SNPRINTF)
#CHECK_SYMBOL_EXISTS(strptime "time.h"    MDCM_HAVE_STRPTIME)
CHECK_FUNCTION_EXISTS(strptime    MDCM_HAVE_STRPTIME)
#M$ extension:
CHECK_FUNCTION_EXISTS(_stricmp  MDCM_HAVE__STRICMP)
CHECK_FUNCTION_EXISTS(_strnicmp MDCM_HAVE__STRNICMP)
CHECK_FUNCTION_EXISTS(_snprintf MDCM_HAVE__SNPRINTF)
# This is C99
set(CMAKE_REQUIRED_INCLUDES math.h)
set(CMAKE_REQUIRED_LIBRARIES m)
check_function_exists(lround MDCM_HAVE_LROUND)

#include(CheckSymbolExists)
CHECK_FUNCTION_EXISTS(gettimeofday MDCM_HAVE_GETTIMEOFDAY)
# json-c API changed:
if(MDCM_USE_SYSTEM_JSON)
  set(CMAKE_REQUIRED_INCLUDES ${JSON_INCLUDE_DIRS})
  set(CMAKE_REQUIRED_LIBRARIES ${JSON_LIBRARIES})
  CHECK_SYMBOL_EXISTS(json_object_object_get_ex "json.h" MDCM_HAVE_JSON_OBJECT_OBJECT_GET_EX)
endif()

include(CheckCXXSourceCompiles)
CHECK_CXX_SOURCE_COMPILES(
  "int main() { const char *f = __FUNCTION__; return 0;}"
  MDCM_CXX_HAS_FUNCTION)
CHECK_CXX_SOURCE_COMPILES(
  "\#include <fstream>\nint main() { const wchar_t fn[10] = {}; std::ifstream is( fn ); return 0;}"
  MDCM_HAVE_WCHAR_IFSTREAM)
if(MDCM_USE_SYSTEM_OPENSSL)
set(CMAKE_REQUIRED_INCLUDES ${OPENSSL_INCLUDE_DIR})
set(CMAKE_REQUIRED_LIBRARIES ${OPENSSL_LIBRARIES}
  ${CMAKE_DL_LIBS} # FIXME ??
  )
CHECK_CXX_SOURCE_COMPILES(
  #  "\#include <openssl/cms.h>\nint main() { CMS_add0_recipient_key(0); return 0;}"
  #HAVE_CMS_RECIPIENT_KEY)
    "\#include <openssl/cms.h>\nint main() { CMS_add0_recipient_password(0,0,0,0,0,0,0); return 0;}"
  MDCM_HAVE_CMS_RECIPIENT_PASSWORD)
endif()

# Provide compatibility options.
option(MDCM_LEGACY_REMOVE "Remove all legacy code completely." OFF)
option(MDCM_LEGACY_SILENT "Silence all legacy code messages." OFF)
mark_as_advanced(MDCM_LEGACY_REMOVE MDCM_LEGACY_SILENT)


configure_file(
  "${MDCM_SOURCE_DIR}/Source/Common/mdcmConfigure.h.in"
  "${MDCM_BINARY_DIR}/Source/Common/mdcmConfigure.h"
  )

# Add the include paths
include_directories(
  "${MDCM_BINARY_DIR}/Source/Common"
  "${MDCM_SOURCE_DIR}/Source/Common"
  "${MDCM_SOURCE_DIR}/Source/DataStructureAndEncodingDefinition"
  "${MDCM_SOURCE_DIR}/Utilities"
  )

if(NOT MDCM_USE_SYSTEM_ZLIB)
include_directories(
  "${MDCM_BINARY_DIR}/Utilities/mdcmzlib"
)
endif()

set(Common_SRCS
  mdcmVersion.cxx
  mdcmRegion.cxx
  mdcmBoxRegion.cxx
  mdcmEvent.cxx
  mdcmMD5.cxx
  mdcmBase64.cxx
  mdcmSHA1.cxx
  mdcmDummyValueGenerator.cxx
  mdcmCryptoFactory.cxx
  mdcmASN1.cxx
  mdcmSubject.cxx
  mdcmDirectory.cxx
  mdcmFilename.cxx
  mdcmFilenameGenerator.cxx
  mdcmSwapCode.cxx
  mdcmSystem.cxx
  mdcmTrace.cxx
  mdcmUnpacker12Bits.cxx
  )

if(WIN32)
set(Common_SRCS ${Common_SRCS}
  mdcmCAPICryptographicMessageSyntax.cxx
  mdcmCAPICryptoFactory.cxx
)
endif()

if(MDCM_USE_SYSTEM_OPENSSL)
set(Common_SRCS ${Common_SRCS}
  mdcmOpenSSLP7CryptographicMessageSyntax.cxx
)
endif()

if(MDCM_USE_SYSTEM_OPENSSL AND MDCM_HAVE_CMS_RECIPIENT_PASSWORD)
set(Common_SRCS ${Common_SRCS}
  mdcmOpenSSLCryptoFactory.cxx
  mdcmOpenSSLCryptographicMessageSyntax.cxx
)
endif()

add_library(mdcmCommon ${Common_SRCS})

if(APPLE)
  if(MDCM_USE_COREFOUNDATION_LIBRARY)
    target_link_libraries(mdcmCommon LINK_PRIVATE ${COREFOUNDATION_LIBRARY})
  endif()
endif()
if(UNIX)
  target_link_libraries(mdcmCommon LINK_PRIVATE ${CMAKE_DL_LIBS})
endif()

if(WIN32)
  target_link_libraries(mdcmCommon LINK_PRIVATE ws2_32)
  target_link_libraries(mdcmCommon LINK_PRIVATE crypt32)
endif()

if(MDCM_USE_SYSTEM_OPENSSL)
  include_directories(${OPENSSL_INCLUDE_DIR})
  target_link_libraries(mdcmCommon LINK_PRIVATE ${OPENSSL_LIBRARIES})
endif()
set_target_properties(mdcmCommon PROPERTIES ${MDCM_LIBRARY_PROPERTIES})

install_library(mdcmCommon)
install_pdb(mdcmCommon)
install_includes("*.h" "*.txx")
if(NOT MDCM_INSTALL_NO_DEVELOPMENT)
  install(FILES ${header_files}
    "${MDCM_BINARY_DIR}/Source/Common/mdcmConfigure.h"
    DESTINATION ${MDCM_INSTALL_INCLUDE_DIR} COMPONENT Headers)
endif()
