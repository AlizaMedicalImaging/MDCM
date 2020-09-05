include_regular_expression("^mdcm.*$")

option(MDCM_SUPPORT_BROKEN_IMPLEMENTATION "Handle broken DICOM" ON)
mark_as_advanced(MDCM_SUPPORT_BROKEN_IMPLEMENTATION)

CHECK_INCLUDE_FILE_CONCAT("sys/time.h" MDCM_HAVE_SYS_TIME_H)
CHECK_INCLUDE_FILE_CONCAT("byteswap.h" MDCM_HAVE_BYTESWAP_FILE_H)
# s. GDCM bug #324
if(MDCM_HAVE_BYTESWAP_FILE_H)
  include(CheckCXXSourceCompiles)
  CHECK_CXX_SOURCE_COMPILES("\#include <byteswap.h>\nint main(){return bswap_32(42);}"
    MDCM_HAVE_BYTESWAP_H)
endif()
CHECK_INCLUDE_FILE("rpc.h"      MDCM_HAVE_RPC_H)
CHECK_INCLUDE_FILE("langinfo.h" MDCM_HAVE_LANGINFO_H)

include(CheckFunctionExists)
# See http://public.kitware.com/Bug/view.php?id=8246
include(CheckSymbolExists)
CHECK_SYMBOL_EXISTS(nl_langinfo "langinfo.h" MDCM_HAVE_NL_LANGINFO)
#C99
#CHECK_FUNCTION_EXISTS(strcasecmp MDCM_HAVE_STRCASECMP)
CHECK_SYMBOL_EXISTS(strcasecmp "strings.h" MDCM_HAVE_STRCASECMP)
#CHECK_FUNCTION_EXISTS(strncasecmp MDCM_HAVE_STRNCASECMP)
CHECK_SYMBOL_EXISTS(strncasecmp "strings.h" MDCM_HAVE_STRNCASECMP)
#CHECK_FUNCTION_EXISTS(snprintf MDCM_HAVE_SNPRINTF)
CHECK_SYMBOL_EXISTS(snprintf "stdio.h" MDCM_HAVE_SNPRINTF)
#CHECK_SYMBOL_EXISTS(strptime "time.h" MDCM_HAVE_STRPTIME)
CHECK_FUNCTION_EXISTS(strptime MDCM_HAVE_STRPTIME)
#M$ extension:
CHECK_FUNCTION_EXISTS(_stricmp  MDCM_HAVE__STRICMP)
CHECK_FUNCTION_EXISTS(_strnicmp MDCM_HAVE__STRNICMP)
CHECK_FUNCTION_EXISTS(_snprintf MDCM_HAVE__SNPRINTF)
# This is C99
set(CMAKE_REQUIRED_INCLUDES math.h)
set(CMAKE_REQUIRED_LIBRARIES m)
check_function_exists(lround MDCM_HAVE_LROUND)

CHECK_FUNCTION_EXISTS(gettimeofday MDCM_HAVE_GETTIMEOFDAY)

include(CheckCXXSourceCompiles)
CHECK_CXX_SOURCE_COMPILES("int main(){const char *f =__FUNCTION__;return 0;}"
  MDCM_CXX_HAS_FUNCTION)
CHECK_CXX_SOURCE_COMPILES("\#include <fstream>\nint main(){const wchar_t fn[10]={};std::ifstream is(fn);return 0;}"
  MDCM_HAVE_WCHAR_IFSTREAM)
if(MDCM_USE_SYSTEM_OPENSSL)
  set(CMAKE_REQUIRED_INCLUDES ${OPENSSL_INCLUDE_DIR})
  set(CMAKE_REQUIRED_LIBRARIES ${OPENSSL_LIBRARIES} ${CMAKE_DL_LIBS}) #FIXME
  CHECK_CXX_SOURCE_COMPILES("\#include <openssl/cms.h>\nint main(){CMS_add0_recipient_password(0,0,0,0,0,0,0);return 0;}"
    MDCM_HAVE_CMS_RECIPIENT_PASSWORD)
endif()
# "\#include <openssl/cms.h>\nint main() { CMS_add0_recipient_key(0); return 0;}"
# HAVE_CMS_RECIPIENT_KEY

configure_file(
  "${MDCM_SOURCE_DIR}/Source/Common/mdcmConfigure.h.in"
  "${MDCM_BINARY_DIR}/Source/Common/mdcmConfigure.h")

include_directories(
  "${MDCM_BINARY_DIR}/Source/Common"
  "${MDCM_SOURCE_DIR}/Source/Common"
  "${MDCM_SOURCE_DIR}/Source/DataStructureAndEncodingDefinition"
  "${MDCM_SOURCE_DIR}/Utilities")

if(NOT MDCM_USE_SYSTEM_ZLIB)
  include_directories("${MDCM_BINARY_DIR}/Utilities/mdcmzlib")
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
  mdcmUnpacker12Bits.cxx)

if(WIN32)
  set(Common_SRCS ${Common_SRCS} mdcmCAPICryptographicMessageSyntax.cxx mdcmCAPICryptoFactory.cxx)
endif()

if(MDCM_USE_SYSTEM_OPENSSL)
  set(Common_SRCS ${Common_SRCS} mdcmOpenSSLP7CryptographicMessageSyntax.cxx)
endif()

if(MDCM_USE_SYSTEM_OPENSSL AND MDCM_HAVE_CMS_RECIPIENT_PASSWORD)
  set(Common_SRCS ${Common_SRCS} mdcmOpenSSLCryptoFactory.cxx mdcmOpenSSLCryptographicMessageSyntax.cxx)
endif()

add_library(mdcmcommon ${Common_SRCS})

if(APPLE)
  if(MDCM_USE_COREFOUNDATION_LIBRARY)
    target_link_libraries(mdcmcommon LINK_PRIVATE ${COREFOUNDATION_LIBRARY})
  endif()
endif()

if(UNIX)
  target_link_libraries(mdcmcommon LINK_PRIVATE ${CMAKE_DL_LIBS})
endif()

if(WIN32)
  target_link_libraries(mdcmcommon LINK_PRIVATE crypt32)
endif()

if(MDCM_USE_SYSTEM_OPENSSL)
  include_directories(${OPENSSL_INCLUDE_DIR})
  target_link_libraries(mdcmcommon LINK_PRIVATE ${OPENSSL_LIBRARIES})
endif()

set_target_properties(mdcmcommon PROPERTIES ${MDCM_LIBRARY_PROPERTIES})

install_library(mdcmcommon)
install_pdb(mdcmcommon)
install_includes("*.h" "*.txx")
if(NOT MDCM_INSTALL_NO_DEVELOPMENT)
  install(FILES ${header_files}
    "${MDCM_BINARY_DIR}/Source/Common/mdcmConfigure.h"
    DESTINATION ${MDCM_INSTALL_INCLUDE_DIR} COMPONENT Headers)
endif()
