cmake_minimum_required(VERSION 3.8.0)
# Note, for CMAKE_CXX_STANDARD:
# For C++20 version 3.12 is required.
# For C++23 version 3.20 is required.
# For C++26 version 3.25 is required.

project(MDCM)

# https://cmake.org/cmake/help/v3.0/policy/CMP0022.html
# Link
if(POLICY CMP0022)
  cmake_policy(SET CMP0022 NEW)
endif()

# https://cmake.org/cmake/help/v3.0/policy/CMP0025.html
# AppleClang
if(POLICY CMP0025)
  cmake_policy(SET CMP0025 NEW)
endif()

# https://cmake.org/cmake/help/v3.6/policy/CMP0026.html
# Disallow LOCATION property
if(POLICY CMP0026)
  cmake_policy(SET CMP0026 NEW)
endif()

# https://cmake.org/cmake/help/v3.0/policy/CMP0042.html
# MACOSX_RPATH is enabled by default
if(POLICY CMP0042)
  cmake_policy(SET CMP0042 NEW)
endif()

# https://cmake.org/cmake/help/v3.3/policy/CMP0063.html
# Honor visibility properties for all target types.
if(POLICY CMP0063 )
  cmake_policy(SET CMP0063 NEW)
endif()

mark_as_advanced(CMAKE_BACKWARDS_COMPATIBILITY)

set(MDCM_CMAKE_DIR "${MDCM_SOURCE_DIR}/CMake" CACHE INTERNAL "")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${MDCM_CMAKE_DIR}")
set(MDCM_MAJOR_VERSION 1)
set(MDCM_MINOR_VERSION 6)
set(MDCM_BUILD_VERSION 1)
set(MDCM_VERSION "${MDCM_MAJOR_VERSION}.${MDCM_MINOR_VERSION}.${MDCM_BUILD_VERSION}")
set(MDCM_API_VERSION "${MDCM_MAJOR_VERSION}.${MDCM_MINOR_VERSION}")
set(MDCM_LIBRARY_PROPERTIES ${MDCM_LIBRARY_PROPERTIES} VERSION "${MDCM_VERSION}" SOVERSION "${MDCM_API_VERSION}")

########################################################################
#
# C++ standard, currently minimum required is C++14.
#
#
set(MDCM_CXX_STANDARD "14" CACHE STRING "Select C++ standard")
set_property(CACHE MDCM_CXX_STANDARD PROPERTY STRINGS "14" "17" "20" "23" "26" "Not set")
if(MDCM_CXX_STANDARD STREQUAL "Not set")
else()
  if(MDCM_CXX_STANDARD STREQUAL "14")
    set(CMAKE_CXX_STANDARD 14)
    message(STATUS "Tried to set C++14")
  elseif(MDCM_CXX_STANDARD STREQUAL "17")
    set(CMAKE_CXX_STANDARD 17)
    message(STATUS "Tried to set C++17")
  elseif(MDCM_CXX_STANDARD STREQUAL "20")
    set(CMAKE_CXX_STANDARD 20)
    message(STATUS "Tried to set C++20")
  elseif(MDCM_CXX_STANDARD STREQUAL "23")
    set(CMAKE_CXX_STANDARD 23)
    message(STATUS "Tried to set C++23")
  elseif(MDCM_CXX_STANDARD STREQUAL "26")
    set(CMAKE_CXX_STANDARD 26)
    message(STATUS "Tried to set C++26")
  endif()
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()
#
#
#
########################################################################

if(WIN32)
  option(MDCM_USE_WIN32_UNC "Unicode, long file path (Windows)" ON)
  if(MDCM_USE_WIN32_UNC)
    add_definitions(-DMDCM_WIN32_UNC)
  endif()
endif()

include(${CMAKE_ROOT}/Modules/TestBigEndian.cmake)
TEST_BIG_ENDIAN(MDCM_WORDS_BIGENDIAN)

set(tmp0_build_type "None")
if(CMAKE_BUILD_TYPE)
  set(tmp0_build_type "${CMAKE_BUILD_TYPE}")
endif()
string(TOUPPER ${tmp0_build_type} tmp1_build_type)
if(NOT ${tmp1_build_type} STREQUAL "DEBUG")
  add_definitions(-DNDEBUG)
endif()

set(MDCM_TARGETS_NAME MDCMTargets)

include(${MDCM_SOURCE_DIR}/CMake/InstallMacros.cmake)

if(MSVC_VERSION EQUAL 1400 OR MSVC_VERSION GREATER 1400)
  add_definitions(-D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -D_CRT_SECURE_NO_WARNINGS)
  add_definitions(-D_SCL_SECURE_NO_DEPRECATE -D_SCL_SECURE_NO_WARNINGS)
endif()

option(MDCM_BUILD_SHARED_LIBS "Build MDCM shared libraries" OFF)
set(BUILD_SHARED_LIBS ${MDCM_BUILD_SHARED_LIBS})

if(BUILD_SHARED_LIBS)
  set(NAMELINK_ONLY NAMELINK_ONLY)
  set(NAMELINK_SKIP NAMELINK_SKIP)
endif()

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

string(TOLOWER ${PROJECT_NAME} projname)

###################################################
#
#
if(NOT MDCM_INSTALL_LIBDIR)
  if(NOT CMAKE_INSTALL_LIBDIR)
    set(MDCM_INSTALL_LIBDIR "lib")
  else()
    set(MDCM_INSTALL_LIBDIR "${CMAKE_INSTALL_LIBDIR}")
  endif()
endif()

if(NOT MDCM_INSTALL_INCLUDE_DIR)
  set(MDCM_INSTALL_INCLUDE_DIR "include/${projname}")
endif()

if(NOT MDCM_INSTALL_PACKAGE_DIR)
  set(MDCM_INSTALL_PACKAGE_DIR "${MDCM_INSTALL_LIBDIR}/cmake/${projname}" CACHE INTERNAL "")
endif()
#
#
###################################################

if(NOT MDCM_INSTALL_BIN_DIR)
  set(MDCM_INSTALL_BIN_DIR "bin")
endif()

if(NOT MDCM_INSTALL_DATA_DIR)
  set(MDCM_INSTALL_DATA_DIR "share/${projname}")
endif()

if(NOT MDCM_INSTALL_DOC_DIR)
  set(MDCM_INSTALL_DOC_DIR "share/doc/${projname}")
endif()

if(NOT MDCM_INSTALL_MAN_DIR)
  set(MDCM_INSTALL_MAN_DIR "share/man")
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

option(MDCM_USE_SYSTEM_OPENSSL "Use system OpenSSL" OFF)
mark_as_advanced(MDCM_USE_SYSTEM_OPENSSL)

if(UNIX)
  option(MDCM_USE_SYSTEM_UUID "Use system uuid" OFF)
endif()

option(MDCM_USE_SYSTEM_OPENJPEG "Use system OpenJPEG" OFF)

option(MDCM_USE_SYSTEM_CHARLS "Use system CharLS" OFF)

set(MDCM_LJPEG_LIBRARIES mdcmjpeg8 mdcmjpeg12 mdcmjpeg16)

if(MDCM_USE_SYSTEM_CHARLS)
  find_package(CharLS REQUIRED)
  set(MDCM_CHARLS_LIBRARIES ${CHARLS_LIBRARIES})
else()
  set(MDCM_CHARLS_LIBRARIES mdcmcharls)
endif()
add_definitions(-DCHARLS_NO_DEPRECATED_WARNING)

if(MDCM_USE_SYSTEM_OPENJPEG)
  find_package(OpenJPEG 2.0.0 REQUIRED)
  set(MDCM_OPENJPEG_LIBRARIES ${OPENJPEG_LIBRARIES})
else()
  set(MDCM_OPENJPEG_LIBRARIES mdcmopenjp2)
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

if(MDCM_USE_SYSTEM_OPENSSL)
  find_package(OpenSSL REQUIRED)
  message(STATUS "OpenSSL include: " ${OPENSSL_INCLUDE_DIR})
  message(STATUS "OpenSSL libraries: " ${OPENSSL_LIBRARIES})
endif()

set(MDCM_LIBRARY_DIR ${LIBRARY_OUTPUT_PATH}/${CMAKE_CFG_INTDIR})

# Debug postfix eg. 'd'
if(WIN32)
  set(MDCM_DEBUG_POSTFIX "" CACHE STRING "Append a debug postfix to libraries")
  if(MDCM_DEBUG_POSTFIX)
    set(CMAKE_DEBUG_POSTFIX "${MDCM_DEBUG_POSTFIX}")
  endif()
  mark_as_advanced(MDCM_DEBUG_POSTFIX)
endif()

set(MDCM_INCLUDE_PATH
  "${MDCM_SOURCE_DIR}/Source/Common"
  "${MDCM_BINARY_DIR}/Source/Common"
  "${MDCM_SOURCE_DIR}/Source/DataStructureAndEncodingDefinition"
  "${MDCM_SOURCE_DIR}/Source/MediaStorageAndFileFormat"
  "${MDCM_SOURCE_DIR}/Source/DataDictionary")

add_subdirectory(Utilities)
add_subdirectory(Source)

set(MDCM_LIBRARY_DIRS ${LIBRARY_OUTPUT_PATH})
set(MDCM_LIBRARIES mdcmmsff mdcmdsed mdcmdict
  ${MDCM_LJPEG_LIBRARIES}
  ${MDCM_OPENJPEG_LIBRARIES}
  ${MDCM_CHARLS_LIBRARIES}
  ${MDCM_UUID_LIBRARIES}
  ${MDCM_ZLIB_LIBRARIES})

add_subdirectory(CMake/ExportConfiguration)

