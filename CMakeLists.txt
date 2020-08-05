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
set(MDCM_BUILD_VERSION 27)
set(MDCM_VERSION "${MDCM_MAJOR_VERSION}.${MDCM_MINOR_VERSION}.${MDCM_BUILD_VERSION}")
set(MDCM_API_VERSION "${MDCM_MAJOR_VERSION}.${MDCM_MINOR_VERSION}")
set(MDCM_LIBRARY_PROPERTIES ${MDCM_LIBRARY_PROPERTIES}
  VERSION "${MDCM_VERSION}"
  SOVERSION "${MDCM_API_VERSION}"
)
set(MDCM_STANDALONE 1)

#-----------------------------------------------------------------------------
# Disable deprecation warnings for standard C and STL functions in VS2005
# and later
if(MSVC_VERSION EQUAL 1400 OR MSVC_VERSION GREATER 1400)
  add_definitions(-D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -D_CRT_SECURE_NO_WARNINGS)
  add_definitions(-D_SCL_SECURE_NO_DEPRECATE -D_SCL_SECURE_NO_WARNINGS)
endif()

# Build shared lib
if(MDCM_STANDALONE)
  option(MDCM_BUILD_SHARED_LIBS "Build MDCM with shared libraries." OFF)
  set(BUILD_SHARED_LIBS ${MDCM_BUILD_SHARED_LIBS})
else()
  set(MDCM_BUILD_SHARED_LIBS ${BUILD_SHARED_LIBS})
endif()
if(BUILD_SHARED_LIBS)
  set(NAMELINK_ONLY NAMELINK_ONLY)
  set(NAMELINK_SKIP NAMELINK_SKIP)
endif()

#-----------------------------------------------------------------------------
option(MDCM_USE_JPEGLS "Build MDCM with JPEG-LS support" ON)
mark_as_advanced(MDCM_USE_JPEGLS)

#-----------------------------------------------------------------------------
if(NOT EXECUTABLE_OUTPUT_PATH)
  set(EXECUTABLE_OUTPUT_PATH ${MDCM_BINARY_DIR}/bin CACHE PATH "Single output directory for building all executables.")
  mark_as_advanced(EXECUTABLE_OUTPUT_PATH)
endif()
if(NOT LIBRARY_OUTPUT_PATH)
  set(LIBRARY_OUTPUT_PATH ${MDCM_BINARY_DIR}/bin CACHE PATH "Single output directory for building all libraries.")
  mark_as_advanced(LIBRARY_OUTPUT_PATH)
endif()

#-----------------------------------------------------------------------------
include(${CMAKE_ROOT}/Modules/CheckIncludeFile.cmake)
include(${CMAKE_ROOT}/Modules/CheckIncludeFiles.cmake)
# Check if header file exists and add it to the list.
macro(CHECK_INCLUDE_FILE_CONCAT FILE VARIABLE)
  CHECK_INCLUDE_FILES("${UUID_INCLUDES};${FILE}" ${VARIABLE})
  if(${VARIABLE})
    set(UUID_INCLUDES ${UUID_INCLUDES} ${FILE})
  endif()
endmacro()

CHECK_INCLUDE_FILE("stdint.h" MDCM_HAVE_STDINT_H)
if(UNIX) #Avoid polluting Win32 cmakecache
  CHECK_INCLUDE_FILE("inttypes.h" MDCM_HAVE_INTTYPES_H)
endif()

#-----------------------------------------------------------------------------
# Build the main lib...
if(NOT MDCM_HAVE_STDINT_H)
  if( MSVC OR "x${CMAKE_CXX_COMPILER_ID}x" MATCHES "Intel" )
    include_directories(
      "${MDCM_SOURCE_DIR}/Utilities/C99"
      )
    # Process the install rules from C99
    subdirs(Utilities/C99)
  endif()
endif()

string(TOLOWER ${PROJECT_NAME} projectname)
set(subdir "${projectname}-${MDCM_MAJOR_VERSION}.${MDCM_MINOR_VERSION}")

#System stuff, mainly for packager or paranoid people with up-to-date lib moto
option(MDCM_USE_SYSTEM_ZLIB "Use system zlib" OFF)
option(MDCM_USE_SYSTEM_OPENSSL  "Use system OpenSSL" OFF)
if(UNIX)
  # Will search for the uuid_generate symbols.
  # Can be in libSystem.dylib or libuuid.so
  option(MDCM_USE_SYSTEM_UUID "Use system uuid" OFF)
endif()
option(MDCM_USE_SYSTEM_PAPYRUS3 "Use system Papyrus3" OFF)
option(MDCM_USE_SYSTEM_LJPEG "Use system LJPEG (ijg lib)" OFF)
option(MDCM_USE_SYSTEM_OPENJPEG "Use system OpenJPEG" OFF)
option(MDCM_USE_SYSTEM_CHARLS "Use system CharLS" OFF)
mark_as_advanced(
  MDCM_USE_SYSTEM_ZLIB
  MDCM_USE_SYSTEM_OPENSSL
  MDCM_USE_SYSTEM_UUID
  MDCM_USE_SYSTEM_PAPYRUS3
  MDCM_USE_SYSTEM_LJPEG
  MDCM_USE_SYSTEM_OPENJPEG
  MDCM_USE_SYSTEM_CHARLS)

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

# Very advanced user option:
# This will cause building of the broken JPEG library released by the Standford PVRG group:
option(MDCM_USE_PVRG "Use pvrg lib, only turn it on if you know what you are doing." OFF)
mark_as_advanced(MDCM_USE_PVRG)

option(MDCM_USE_KAKADU "Use kakadu lib, only turn it on if you know what you are doing." OFF)
mark_as_advanced(MDCM_USE_KAKADU)

if(MDCM_USE_KAKADU)
  option(MDCM_USE_SYSTEM_KAKADU "Use system KAKADU " ON)
  mark_as_advanced(MDCM_USE_SYSTEM_KAKADU)
  if(MDCM_USE_SYSTEM_KAKADU)
    find_package(KAKADU REQUIRED)
  else()
    message(FATAL_ERROR "Not Implemented")
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

if(MDCM_USE_SYSTEM_PAPYRUS3)
  find_package(PAPYRUS3 REQUIRED)
endif()

#-----------------------------------------------------------------------------

set(MDCM_LIBRARY_DIR ${LIBRARY_OUTPUT_PATH}/${CMAKE_CFG_INTDIR})

#-----------------------------------------------------------------------------
# we need to link against CoreFoundation so that we can use CFBundle to get the executable path.
if(APPLE)
  option(MDCM_USE_COREFOUNDATION_LIBRARY "Use COREFOUNDATION_LIBRARY?" ON)
  if(MDCM_USE_COREFOUNDATION_LIBRARY)
    find_library(COREFOUNDATION_LIBRARY CoreFoundation )
  endif()
endif()

#-----------------------------------------------------------------------------
# Allow user to set a postfix symbol to a target library name (eg. 'd')
if(WIN32)
  set(MDCM_DEBUG_POSTFIX "" CACHE STRING "Globally append a debug postfix symbols on all libraries")
  if(MDCM_DEBUG_POSTFIX)
    set(CMAKE_DEBUG_POSTFIX "${MDCM_DEBUG_POSTFIX}")
  endif()
  mark_as_advanced(MDCM_DEBUG_POSTFIX)
endif()
#-----------------------------------------------------------------------------

# Need to subdirs in Source/Common before Wrapping
# to have mdcmConfigure.h around
subdirs(Utilities)
add_subdirectory(Source)

# Need pthread for the following class:
CHECK_INCLUDE_FILE("pthread.h" MDCM_HAVE_PTHREAD_H)

# Big endian thing:
if(MDCM_STANDALONE)
  include(${CMAKE_ROOT}/Modules/TestBigEndian.cmake)
  TEST_BIG_ENDIAN(MDCM_WORDS_BIGENDIAN)
endif()

#
macro(PROCESSONEDIR DIRNAME myoutput)
  file(GLOB files
    ${DIRNAME}/*
  )
  foreach(file ${files})
    if(IS_DIRECTORY ${file})
      if("${file}" MATCHES ".git")
        #message("${file} is git dir")
      else()
        #message("${file} is dir")
        PROCESSONEDIR(${file} mytests2)
        list(APPEND ${myoutput} ${mytests2})
      endif()
    else()
      #message("${file} is file")
      get_filename_component(filename ${file} NAME)
      if("${filename}" MATCHES "Test" AND ${filename} MATCHES ".cxx")
        string(LENGTH ${filename} filename_length)
        #message("${filename} is test, ${filename_length}")
        math(EXPR fileend "${filename_length} - 4 - 4") # Need to remove 'Test' and '.cxx'
        string(SUBSTRING ${filename} 4 ${fileend} classname)
        #message("${classname} is tested")
        list(APPEND ${myoutput} ${classname})
      endif()
    endif()
  endforeach()
endmacro()

#-----------------------------------------------------------------------------
# Need to be the last operation:
set(MDCM_INCLUDE_PATH
  "${MDCM_SOURCE_DIR}/Source/Common"
  "${MDCM_BINARY_DIR}/Source/Common"
  "${MDCM_SOURCE_DIR}/Source/DataStructureAndEncodingDefinition"
  "${MDCM_SOURCE_DIR}/Source/MediaStorageAndFileFormat"
  "${MDCM_SOURCE_DIR}/Source/DataDictionary"
  )
if(NOT MDCM_HAVE_STDINT_H)
  if(MSVC)
    set(MDCM_INCLUDE_PATH
      ${MDCM_INCLUDE_PATH}
      "${MDCM_SOURCE_DIR}/Utilities/C99"
    )
  endif()
endif()
set(MDCM_LIBRARY_DIRS ${LIBRARY_OUTPUT_PATH})
if(MDCM_STANDALONE)
subdirs(CMake/ExportConfiguration)
endif()

# Expose a way to pass -fPIC to static libs of gdcm core, while still build wrapped language as shared lib:
if(MDCM_USE_PIC_FOR_STATIC_LIBS)
  if(BUILD_SHARED_LIBS)
    message(FATAL_ERROR "Invalid configuration for static/shared lib")
  else()
    set(CMAKE_POSITION_INDEPENDENT_CODE ON)
  endif()
endif()
