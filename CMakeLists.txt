cmake_minimum_required(VERSION 3.1.0)
if(POLICY CMP0022)
  cmake_policy(SET CMP0022 NEW)
endif()
if(POLICY CMP0025)
  cmake_policy(SET CMP0025 NEW)
endif()
if(POLICY CMP0026)
  cmake_policy(SET CMP0026 NEW)
endif()
if(POLICY CMP0042)
  cmake_policy(SET CMP0042 NEW)
endif()
if( POLICY CMP0063 )
  cmake_policy(SET CMP0063 NEW)
endif()
project(MDCM)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
mark_as_advanced(CMAKE_BACKWARDS_COMPATIBILITY CMAKE_BUILD_TYPE CMAKE_INSTALL_PREFIX)
set(MDCM_CMAKE_DIR "${MDCM_SOURCE_DIR}/CMake" CACHE INTERNAL "")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${MDCM_CMAKE_DIR}")

set(MDCM_MAJOR_VERSION 1)
set(MDCM_MINOR_VERSION 0)
set(MDCM_BUILD_VERSION 28)
set(MDCM_VERSION "${MDCM_MAJOR_VERSION}.${MDCM_MINOR_VERSION}.${MDCM_BUILD_VERSION}")
set(MDCM_API_VERSION "${MDCM_MAJOR_VERSION}.${MDCM_MINOR_VERSION}")
set(MDCM_LIBRARY_PROPERTIES ${MDCM_LIBRARY_PROPERTIES}
  VERSION "${MDCM_VERSION}"
  SOVERSION "${MDCM_API_VERSION}")

set(MDCM_TARGETS_NAME MDCMTargets)

include(${MDCM_SOURCE_DIR}/CMake/InstallMacros.cmake)

# Disable warnings for standard C and STL functions in VS2005 and later
if(MSVC_VERSION EQUAL 1400 OR MSVC_VERSION GREATER 1400)
  add_definitions(-D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -D_CRT_SECURE_NO_WARNINGS)
  add_definitions(-D_SCL_SECURE_NO_DEPRECATE -D_SCL_SECURE_NO_WARNINGS)
endif()

option(MDCM_BUILD_SHARED_LIBS "Build MDCM with shared libraries." OFF)
set(BUILD_SHARED_LIBS ${MDCM_BUILD_SHARED_LIBS})

if(BUILD_SHARED_LIBS)
  set(NAMELINK_ONLY NAMELINK_ONLY)
  set(NAMELINK_SKIP NAMELINK_SKIP)
endif()

option(MDCM_USE_JPEGLS "Build MDCM with JPEG-LS support" ON)
mark_as_advanced(MDCM_USE_JPEGLS)

if(NOT EXECUTABLE_OUTPUT_PATH)
  set(EXECUTABLE_OUTPUT_PATH ${MDCM_BINARY_DIR}/bin CACHE PATH "Output directory for executables")
  mark_as_advanced(EXECUTABLE_OUTPUT_PATH)
endif()
if(NOT LIBRARY_OUTPUT_PATH)
  set(LIBRARY_OUTPUT_PATH ${MDCM_BINARY_DIR}/bin CACHE PATH "Output directory for libraries")
  mark_as_advanced(LIBRARY_OUTPUT_PATH)
endif()

include(${CMAKE_ROOT}/Modules/CheckIncludeFile.cmake)
include(${CMAKE_ROOT}/Modules/CheckIncludeFiles.cmake)
macro(CHECK_INCLUDE_FILE_CONCAT FILE VARIABLE)
  CHECK_INCLUDE_FILES("${UUID_INCLUDES};${FILE}" ${VARIABLE})
  if(${VARIABLE})
    set(UUID_INCLUDES ${UUID_INCLUDES} ${FILE})
  endif()
endmacro()

CHECK_INCLUDE_FILE("stdint.h" MDCM_HAVE_STDINT_H)
if(UNIX)
  CHECK_INCLUDE_FILE("inttypes.h" MDCM_HAVE_INTTYPES_H)
endif()

if(NOT MDCM_HAVE_STDINT_H)
  if(MSVC OR "x${CMAKE_CXX_COMPILER_ID}x" MATCHES "Intel")
    include_directories("${MDCM_SOURCE_DIR}/Utilities/C99")
    subdirs(Utilities/C99)
  endif()
endif()

# Install directories
string(TOLOWER ${PROJECT_NAME} projectname)
set(ISUBDIR "${projectname}")

if(NOT MDCM_INSTALL_BIN_DIR)
  set(MDCM_INSTALL_BIN_DIR "bin")
endif()

if(NOT MDCM_INSTALL_LIB_DIR)
  set(MDCM_INSTALL_LIB_DIR "lib")
endif()

if(NOT MDCM_INSTALL_DATA_DIR)
  set(MDCM_INSTALL_DATA_DIR "share/${ISUBDIR}")
endif()

if(NOT MDCM_INSTALL_INCLUDE_DIR)
  set(MDCM_INSTALL_INCLUDE_DIR "include/${ISUBDIR}")
endif()

if(NOT MDCM_INSTALL_DOC_DIR)
  set(MDCM_INSTALL_DOC_DIR "share/doc/${ISUBDIR}")
endif()

if(NOT MDCM_INSTALL_MAN_DIR)
  set(MDCM_INSTALL_MAN_DIR "share/man")
endif()

if(NOT MDCM_INSTALL_PACKAGE_DIR)
  set(MDCM_INSTALL_PACKAGE_DIR ${MDCM_INSTALL_LIB_DIR}/${ISUBDIR}
    CACHE INTERNAL "")
endif()

if(NOT MDCM_INSTALL_NO_DEVELOPMENT)
  set(MDCM_INSTALL_NO_DEVELOPMENT 0)
endif()

if(NOT MDCM_INSTALL_NO_RUNTIME)
  set(MDCM_INSTALL_NO_RUNTIME 0)
endif()

if(NOT MDCM_INSTALL_NO_DOCUMENTATION)
  set(MDCM_INSTALL_NO_DOCUMENTATION 0)
endif()

set(MDCM_INSTALL_NO_LIBRARIES)
if(MDCM_BUILD_SHARED_LIBS)
  if(MDCM_INSTALL_NO_RUNTIME AND MDCM_INSTALL_NO_DEVELOPMENT)
    set(MDCM_INSTALL_NO_LIBRARIES 1)
  endif()
else()
  if(MDCM_INSTALL_NO_DEVELOPMENT)
    set(MDCM_INSTALL_NO_LIBRARIES 1)
  endif()
endif()

option(MDCM_USE_SYSTEM_ZLIB "Use system zlib" OFF)
mark_as_advanced(MDCM_USE_SYSTEM_ZLIB)

#option(MDCM_USE_SYSTEM_OPENSSL "Use system OpenSSL" OFF)
#mark_as_advanced(MDCM_USE_SYSTEM_OPENSSL)

if(UNIX)
  option(MDCM_USE_SYSTEM_UUID "Use system uuid" OFF)
  mark_as_advanced(MDCM_USE_SYSTEM_UUID)
endif()

#option(MDCM_USE_SYSTEM_PAPYRUS3 "Use system Papyrus3" OFF)
#mark_as_advanced(MDCM_USE_SYSTEM_PAPYRUS3)

#option(MDCM_USE_SYSTEM_LJPEG "Use system LJPEG (IJG)" OFF)
#mark_as_advanced(MDCM_USE_SYSTEM_LJPEG)

option(MDCM_USE_SYSTEM_OPENJPEG "Use system OpenJPEG" OFF)
mark_as_advanced(MDCM_USE_SYSTEM_OPENJPEG)

option(MDCM_USE_SYSTEM_CHARLS "Use system CharLS" OFF)
mark_as_advanced(MDCM_USE_SYSTEM_CHARLS)

if(MDCM_USE_SYSTEM_LJPEG)
  find_package(LJPEG REQUIRED)
  set(MDCM_LJPEG_LIBRARIES ${LJPEG_LIBRARIES})
else()
  set(MDCM_LJPEG_LIBRARIES mdcmjpeg8 mdcmjpeg12 mdcmjpeg16)
endif()

if(MDCM_USE_SYSTEM_CHARLS)
  find_package(CharLS 2.0.0 REQUIRED)
  #set(MDCM_CHARLS_LIBRARIES ${CHARLS_LIBRARIES})
  set(MDCM_CHARLS_LIBRARIES ${CHARLS_LIBRARY})
else()
  set(MDCM_CHARLS_LIBRARIES mdcmcharls)
endif()

if(MDCM_USE_SYSTEM_OPENJPEG)
  find_package(OpenJPEG 2.0.0 REQUIRED)
  set(MDCM_OPENJPEG_LIBRARIES ${OPENJPEG_LIBRARIES})
else()
  set(MDCM_OPENJPEG_LIBRARIES mdcmopenjp2)
endif()

# JPEG library released by the Standford PVRG group
option(MDCM_USE_PVRG "Use PVRG, advanced" OFF)
mark_as_advanced(MDCM_USE_PVRG)

#option(MDCM_USE_KAKADU "Use Kakadu, advanced" OFF)
#mark_as_advanced(MDCM_USE_KAKADU)
#if(MDCM_USE_KAKADU)
#  option(MDCM_USE_SYSTEM_KAKADU "Use system KAKADU " ON)
#  mark_as_advanced(MDCM_USE_SYSTEM_KAKADU)
#  if(MDCM_USE_SYSTEM_KAKADU)
#    find_package(KAKADU REQUIRED)
#  else()
#    message(FATAL_ERROR "Not Implemented")
#  endif()
#endif()

if(MDCM_USE_PVRG)
  option(MDCM_USE_SYSTEM_PVRG "Use system PVRG" OFF)
  mark_as_advanced(MDCM_USE_SYSTEM_PVRG)
  if(MDCM_USE_SYSTEM_PVRG)
    find_package(PVRGJPEG REQUIRED)
  endif()
endif()

if(MDCM_USE_SYSTEM_ZLIB)
  find_package(ZLIB REQUIRED)
  include_directories(${ZLIB_INCLUDE_DIR})
  set(MDCM_ZLIB_LIBRARIES ${ZLIB_LIBRARIES})
else()
  set(MDCM_ZLIB_LIBRARIES "mdcmzlib")
endif()

if(MDCM_USE_SYSTEM_UUID)
  find_package(UUID REQUIRED)
  set(MDCM_UUID_LIBRARIES ${UUID_LIBRARIES})
else()
  set(MDCM_UUID_LIBRARIES "mdcmuuid")
endif()

#if(MDCM_USE_SYSTEM_PAPYRUS3)
#  find_package(PAPYRUS3 REQUIRED)
#endif()

set(MDCM_LIBRARY_DIR ${LIBRARY_OUTPUT_PATH}/${CMAKE_CFG_INTDIR})

if(APPLE)
  option(MDCM_USE_COREFOUNDATION_LIBRARY "Use CoreFoundation library?" ON)
  if(MDCM_USE_COREFOUNDATION_LIBRARY)
    find_library(COREFOUNDATION_LIBRARY CoreFoundation )
  endif()
endif()

# Debug postfix eg. "d"
if(WIN32)
  set(MDCM_DEBUG_POSTFIX "" CACHE STRING "Append a debug postfix to libraries")
  if(MDCM_DEBUG_POSTFIX)
    set(CMAKE_DEBUG_POSTFIX "${MDCM_DEBUG_POSTFIX}")
  endif()
  mark_as_advanced(MDCM_DEBUG_POSTFIX)
endif()

subdirs(Utilities)
add_subdirectory(Source)

CHECK_INCLUDE_FILE("pthread.h" MDCM_HAVE_PTHREAD_H)

include(${CMAKE_ROOT}/Modules/TestBigEndian.cmake)
TEST_BIG_ENDIAN(MDCM_WORDS_BIGENDIAN)

set(MDCM_INCLUDE_PATH
  "${MDCM_SOURCE_DIR}/Source/Common"
  "${MDCM_BINARY_DIR}/Source/Common"
  "${MDCM_SOURCE_DIR}/Source/DataStructureAndEncodingDefinition"
  "${MDCM_SOURCE_DIR}/Source/MediaStorageAndFileFormat"
  "${MDCM_SOURCE_DIR}/Source/DataDictionary")
if(NOT MDCM_HAVE_STDINT_H AND MSVC)
  set(MDCM_INCLUDE_PATH ${MDCM_INCLUDE_PATH} "${MDCM_SOURCE_DIR}/Utilities/C99")
endif()

set(MDCM_LIBRARY_DIRS ${LIBRARY_OUTPUT_PATH})
set(MDCM_LIBRARIES mdcmmsff mdcmdsed mdcmdict
  ${MDCM_LJPEG_LIBRARIES}
  ${MDCM_OPENJPEG_LIBRARIES}
  ${MDCM_CHARLS_LIBRARIES}
  ${MDCM_UUID_LIBRARIES}
  ${MDCM_ZLIB_LIBRARIES})

subdirs(CMake/ExportConfiguration)

