if(NOT DEFINED CMAKE_MINIMUM_REQUIRED_VERSION)
  cmake_minimum_required(VERSION 3.5)
endif()

if(COMMAND CMAKE_POLICY)
  cmake_policy(SET CMP0003 NEW)
endif()

if(NOT OPENJPEG_NAMESPACE)
  set(OPENJPEG_NAMESPACE "OPENJPEG")
  set(OPENJPEG_STANDALONE 1)
endif()

set(OPENJPEG_LIBRARY_NAME mdcmopenjp2)

project(${OPENJPEG_NAMESPACE} C)

include_regular_expression("^.*$")

# OPENJPEG version number
set(OPENJPEG_VERSION_MAJOR 2)
set(OPENJPEG_VERSION_MINOR 5)
set(OPENJPEG_VERSION_BUILD 2)
set(OPENJPEG_VERSION
  "${OPENJPEG_VERSION_MAJOR}.${OPENJPEG_VERSION_MINOR}.${OPENJPEG_VERSION_BUILD}")
set(PACKAGE_VERSION
  "${OPENJPEG_VERSION_MAJOR}.${OPENJPEG_VERSION_MINOR}.${OPENJPEG_VERSION_BUILD}")

if(NOT OPENJPEG_SOVERSION)
  set(OPENJPEG_SOVERSION 7)
endif(NOT OPENJPEG_SOVERSION)
set(OPENJPEG_LIBRARY_PROPERTIES
  VERSION   "${OPENJPEG_VERSION_MAJOR}.${OPENJPEG_VERSION_MINOR}.${OPENJPEG_VERSION_BUILD}"
  SOVERSION "${OPENJPEG_SOVERSION}")

# Path to CMake modules
set(CMAKE_MODULE_PATH
    ${${OPENJPEG_NAMESPACE}_SOURCE_DIR}/cmake
    ${CMAKE_MODULE_PATH})

include_directories(BEFORE ${CMAKE_CURRENT_BINARY_DIR})

set(MANGLE_PREFIX ${MDCM_OPENJPEG_LIBRARIES})
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/lib/openjp2/openjpeg_mangle.h.in
               ${CMAKE_CURRENT_BINARY_DIR}/openjpeg_mangle.h
               @ONLY)

# This removes MSVC warnings
if(WIN32)
  if(NOT BORLAND)
    if(NOT CYGWIN)
      if(NOT MINGW)
        add_definitions(
          -D_CRT_FAR_MAPPINGS_NO_DEPRECATE
          -D_CRT_IS_WCTYPE_NO_DEPRECATE
          -D_CRT_MANAGED_FP_NO_DEPRECATE
          -D_CRT_NONSTDC_NO_DEPRECATE
          -D_CRT_SECURE_NO_DEPRECATE
          -D_CRT_SECURE_NO_DEPRECATE_GLOBALS
          -D_CRT_SETERRORMODE_BEEP_SLEEP_NO_DEPRECATE
          -D_CRT_TIME_FUNCTIONS_NO_DEPRECATE
          -D_CRT_VCCLRIT_NO_DEPRECATE
          -D_SCL_SECURE_NO_DEPRECATE
          )
      endif()
    endif()
  endif()
endif()

string(TOLOWER ${PROJECT_NAME} projectname)
set(OPENJPEG_INSTALL_SUBDIR "${projectname}-${OPENJPEG_VERSION_MAJOR}.${OPENJPEG_VERSION_MINOR}")

if(NOT OPENJPEG_INSTALL_BIN_DIR)
  set(OPENJPEG_INSTALL_BIN_DIR "bin")
endif()

if(NOT OPENJPEG_INSTALL_LIB_DIR)
  set(OPENJPEG_INSTALL_LIB_DIR "lib")
endif()

if(NOT OPENJPEG_INSTALL_SHARE_DIR)
  set(OPENJPEG_INSTALL_SHARE_DIR "share")
endif()

if(NOT OPENJPEG_INSTALL_DATA_DIR)
  set(OPENJPEG_INSTALL_DATA_DIR "${OPENJPEG_INSTALL_SHARE_DIR}/${OPENJPEG_INSTALL_SUBDIR}")
endif()

if(NOT OPENJPEG_INSTALL_INCLUDE_DIR)
  set(OPENJPEG_INSTALL_INCLUDE_DIR "include/${OPENJPEG_INSTALL_SUBDIR}")
endif()

if(NOT OPENJPEG_INSTALL_JNI_DIR)
  if(WIN32)
    set(OPENJPEG_INSTALL_JNI_DIR ${OPENJPEG_INSTALL_BIN_DIR})
  else()
    set(OPENJPEG_INSTALL_JNI_DIR ${OPENJPEG_INSTALL_LIB_DIR})
  endif()
endif()

if(NOT OPENJPEG_INSTALL_PACKAGE_DIR)
  # We could install *.cmake files in share/ however those files contains
  # hardcoded path to libraries on a multi-arch system (fedora/debian) those
  # path will be different (lib/i386-linux-gnu vs lib/x86_64-linux-gnu)
  set(OPENJPEG_INSTALL_PACKAGE_DIR "${OPENJPEG_INSTALL_LIB_DIR}/${OPENJPEG_INSTALL_SUBDIR}")
endif()

if (APPLE)
	list(APPEND OPENJPEG_LIBRARY_PROPERTIES INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/${OPENJPEG_INSTALL_LIB_DIR}")
	option(OPJ_USE_DSYMUTIL "Call dsymutil on binaries after build." OFF)
endif()

# Big endian test
include(${CMAKE_ROOT}/Modules/TestBigEndian.cmake)
TEST_BIG_ENDIAN(OPJ_BIG_ENDIAN)

# Setup file for setting custom ctest vars
#configure_file(
#  ${${OPENJPEG_NAMESPACE}_SOURCE_DIR}/cmake/CTestCustom.cmake.in
#  ${${OPENJPEG_NAMESPACE}_BINARY_DIR}/CTestCustom.cmake
#  @ONLY)

# OpenJPEG build configuration options
#option(BUILD_SHARED_LIBS "Build OpenJPEG shared library and link executables against it." ON)
set(EXECUTABLE_OUTPUT_PATH ${OPENJPEG_BINARY_DIR}/bin CACHE PATH "Single output directory for building all executables.")
set(LIBRARY_OUTPUT_PATH ${OPENJPEG_BINARY_DIR}/bin CACHE PATH "Single output directory for building all libraries.")
mark_as_advanced(LIBRARY_OUTPUT_PATH EXECUTABLE_OUTPUT_PATH)

# opj_config.h generation (1/2)

# Check if some include files are provided by the system
include(EnsureFileInclude)
# These files are mandatory
ensure_file_include("string.h"   HAVE_STRING_H YES)
ensure_file_include("memory.h"   HAVE_MEMORY_H YES)
ensure_file_include("stdlib.h"   HAVE_STDLIB_H YES)
ensure_file_include("stdio.h"    HAVE_STDIO_H  YES)
ensure_file_include("math.h"     HAVE_MATH_H   YES)
ensure_file_include("float.h"    HAVE_FLOAT_H  YES)
ensure_file_include("time.h"     HAVE_TIME_H   YES)
ensure_file_include("stdarg.h"   HAVE_STDARG_H YES)
ensure_file_include("ctype.h"    HAVE_CTYPE_H  YES)
ensure_file_include("assert.h"   HAVE_ASSERT_H YES)
ensure_file_include("stdint.h"   HAVE_STDINT_H   YES)
ensure_file_include("inttypes.h" HAVE_INTTYPES_H YES)

# For openjpip?
include (${CMAKE_ROOT}/Modules/CheckIncludeFile.cmake)
CHECK_INCLUDE_FILE("strings.h"   HAVE_STRINGS_H)
CHECK_INCLUDE_FILE("sys/stat.h"  HAVE_SYS_STAT_H)
CHECK_INCLUDE_FILE("sys/types.h" HAVE_SYS_TYPES_H)
CHECK_INCLUDE_FILE("unistd.h"    HAVE_UNISTD_H)

# Large file support
include(TestLargeFiles)
OPJ_TEST_LARGE_FILES(OPJ_HAVE_LARGEFILES)

# Allocating aligned memory blocks
include(CheckIncludeFiles)
check_include_files(malloc.h OPJ_HAVE_MALLOC_H)
include(CheckSymbolExists)
# _aligned_alloc https://msdn.microsoft.com/en-us/library/8z34s9c6.aspx
check_symbol_exists(_aligned_malloc malloc.h OPJ_HAVE__ALIGNED_MALLOC)
# posix_memalign (needs _POSIX_C_SOURCE >= 200112L on Linux)
set(CMAKE_REQUIRED_DEFINITIONS -D_POSIX_C_SOURCE=200112L)
check_symbol_exists(posix_memalign stdlib.h OPJ_HAVE_POSIX_MEMALIGN)
unset(CMAKE_REQUIRED_DEFINITIONS)
# memalign (obsolete)
check_symbol_exists(memalign malloc.h OPJ_HAVE_MEMALIGN)

add_subdirectory(src/lib)

# opj_config.h generation (2/2)
configure_file(
 ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/openjp2/opj_config.h.cmake.in
 ${CMAKE_CURRENT_BINARY_DIR}/src/lib/openjp2/opj_config.h
 @ONLY)

 configure_file(
 ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/openjp2/opj_config_private.h.cmake.in
 ${CMAKE_CURRENT_BINARY_DIR}/src/lib/openjp2/opj_config_private.h
 @ONLY)

# Buld Testing
#option(BUILD_TESTING "Build the tests." OFF)
#if(BUILD_TESTING)
#  if(BUILD_CODEC)
#    enable_testing()
#    include(CTest)
#
#    # Search openjpeg data needed for the tests
#    # They could be found via git on the OpenJPEG GitHub code project
#    # git clone https://github.com/uclouvain/openjpeg-data.git
#    find_path(OPJ_DATA_ROOT README-OPJ-Data
#      PATHS $ENV{OPJ_DATA_ROOT} ${CMAKE_SOURCE_DIR}/../data
#      NO_DEFAULT_PATH NO_CMAKE_FIND_ROOT_PATH)
#
#    # Add repository where to find tests
#    add_subdirectory(tests)
#
#  else()
#    #message(FATAL_ERROR "You need build codec to run the tests")
#  endif()
#endif()

# install all targets referenced as OPENJPEGTargets
#install(EXPORT OpenJPEGTargets DESTINATION ${OPENJPEG_INSTALL_PACKAGE_DIR})

#configure_file(${${OPENJPEG_NAMESPACE}_SOURCE_DIR}/cmake/OpenJPEGConfig.cmake.in
#  ${${OPENJPEG_NAMESPACE}_BINARY_DIR}/OpenJPEGConfig.cmake
#  @ONLY)
#
#install(FILES ${${OPENJPEG_NAMESPACE}_BINARY_DIR}/OpenJPEGConfig.cmake
#  DESTINATION ${OPENJPEG_INSTALL_PACKAGE_DIR})

## install CHANGES and LICENSE
#if(BUILD_DOC)
#if(EXISTS ${OPENJPEG_SOURCE_DIR}/CHANGES)
#  install(FILES CHANGES DESTINATION ${OPENJPEG_INSTALL_DOC_DIR})
#endif()
#
#install(FILES LICENSE DESTINATION ${OPENJPEG_INSTALL_DOC_DIR})
#endif()
#
##include (cmake/OpenJPEGCPack.cmake)
#
## pkgconfig support
## enabled by default on Unix, disabled by default on other platforms
#if(UNIX)
#  option(BUILD_PKGCONFIG_FILES "Build and install pkg-config files" ON)
#else()
#  option(BUILD_PKGCONFIG_FILES "Build and install pkg-config files" OFF)
#endif()
#if(BUILD_PKGCONFIG_FILES)
#  # install in lib and not share (see multi-arch note above)
#  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/lib/openjp2/libopenjp2.pc.cmake.in
#    ${CMAKE_CURRENT_BINARY_DIR}/libopenjp2.pc @ONLY)
#  install( FILES  ${CMAKE_CURRENT_BINARY_DIR}/libopenjp2.pc DESTINATION
#    ${OPENJPEG_INSTALL_LIB_DIR}/pkgconfig )
#endif()

