set(CHARLS_MAJOR_VERSION 2)
set(CHARLS_MINOR_VERSION 4)
set(CHARLS_BUILD_VERSION 2)
set(CHARLS_VERSION "${CHARLS_MAJOR_VERSION}.${CHARLS_MINOR_VERSION}.${CHARLS_BUILD_VERSION}")

project(CHARLS_NAMESPACE VERSION ${CHARLS_VERSION} LANGUAGES C CXX)

string(TOLOWER ${CHARLS_NAMESPACE} CHARLS_LIBRARY_NAME)

add_library(${CHARLS_LIBRARY_NAME}
  "${CMAKE_CURRENT_LIST_DIR}/charls_jpegls_decoder.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/charls_jpegls_encoder.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/jpegls_error.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/jpegls.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/jpeg_stream_reader.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/jpeg_stream_writer.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/validate_spiff_header.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/version.cpp")

set(CHARLS_PUB_HEADER_FILES
  "${CMAKE_CURRENT_LIST_DIR}/annotations.h"
  "${CMAKE_CURRENT_LIST_DIR}/api_abi.h"
  "${CMAKE_CURRENT_LIST_DIR}/charls.h"
  "${CMAKE_CURRENT_LIST_DIR}/charls_jpegls_decoder.h"
  "${CMAKE_CURRENT_LIST_DIR}/charls_jpegls_encoder.h"
  "${CMAKE_CURRENT_LIST_DIR}/jpegls_error.h"
  "${CMAKE_CURRENT_LIST_DIR}/public_types.h"
  "${CMAKE_CURRENT_LIST_DIR}/validate_spiff_header.h"
  "${CMAKE_CURRENT_LIST_DIR}/version.h")

if(NOT BUILD_SHARED_LIBS)
  target_compile_definitions(${CHARLS_LIBRARY_NAME} PUBLIC CHARLS_STATIC)
endif()

set_target_properties(${CHARLS_LIBRARY_NAME} PROPERTIES VERSION ${CHARLS_VERSION} SOVERSION ${CHARLS_MAJOR_VERSION})
target_compile_definitions(${CHARLS_LIBRARY_NAME} PRIVATE CHARLS_LIBRARY_BUILD)
target_compile_features(${CHARLS_LIBRARY_NAME} PUBLIC cxx_std_14)
set_target_properties(${CHARLS_LIBRARY_NAME} PROPERTIES CXX_VISIBILITY_PRESET hidden)
set_target_properties(${CHARLS_LIBRARY_NAME} PROPERTIES VISIBILITY_INLINES_HIDDEN 1)

if(WIN32 AND BUILD_SHARED_LIBS)
  if(MSVC AND CMAKE_SIZEOF_VOID_P EQUAL 4)
    target_sources(${CHARLS_LIBRARY_NAME} PRIVATE "${CMAKE_CURRENT_LIST_DIR}/charls.def")
  endif()
endif()

if(NOT CHARLS_INSTALL_NO_LIBRARIES)
  install(TARGETS ${CHARLS_LIBRARY_NAME}
    EXPORT ${MDCM_TARGETS_NAME}
    RUNTIME DESTINATION ${CHARLS_INSTALL_BIN_DIR} COMPONENT Applications
    LIBRARY DESTINATION ${CHARLS_INSTALL_LIB_DIR} COMPONENT Libraries ${NAMELINK_SKIP}
    ARCHIVE DESTINATION ${CHARLS_INSTALL_LIB_DIR} COMPONENT DebugDevel)
  if(NAMELINK_ONLY)
    install(TARGETS ${CHARLS_LIBRARY_NAME}
    EXPORT ${MDCM_TARGETS_NAME}
      LIBRARY DESTINATION ${CHARLS_INSTALL_LIB_DIR} COMPONENT DebugDevel ${NAMELINK_ONLY})
  endif()
endif()

if(NOT CHARLS_INSTALL_NO_DEVELOPMENT)
  install(FILES ${CHARLS_PUB_HEADER_FILES} DESTINATION ${CHARLS_INSTALL_INCLUDE_DIR} COMPONENT Headers)
endif()
