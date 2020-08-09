macro(install_library library)
  if(NOT MDCM_INSTALL_NO_LIBRARIES)
    install(TARGETS ${library}
      EXPORT ${MDCM_TARGETS_NAME}
      RUNTIME DESTINATION ${MDCM_INSTALL_BIN_DIR} COMPONENT Applications
      LIBRARY DESTINATION ${MDCM_INSTALL_LIB_DIR} COMPONENT Libraries ${NAMELINK_SKIP}
      INCLUDES DESTINATION ${MDCM_INSTALL_INCLUDE_DIR}
      ARCHIVE DESTINATION ${MDCM_INSTALL_LIB_DIR} COMPONENT DebugDevel)
    if(NAMELINK_ONLY)
      install(TARGETS ${library}
        EXPORT ${MDCM_TARGETS_NAME}
        LIBRARY DESTINATION ${MDCM_INSTALL_LIB_DIR} COMPONENT DebugDevel ${NAMELINK_ONLY})
    endif()
  endif()
endmacro()

macro(install_pdb library)
  if(BUILD_SHARED_LIBS)
    if (MSVC)
      install(
        FILES          "$<TARGET_PDB_FILE:${library}>"
        DESTINATION    "${MDCM_INSTALL_BIN_DIR}"
        COMPONENT      DebugDevel
        CONFIGURATIONS Debug RelWithDebInfo)
    endif()
  endif()
endmacro()

macro(install_includes glob_expression)
  if(NOT MDCM_INSTALL_NO_DEVELOPMENT)
    file(GLOB header_files ${glob_expression} ${ARGN})
    install(FILES ${header_files} DESTINATION ${MDCM_INSTALL_INCLUDE_DIR} COMPONENT Headers)
  endif()
endmacro()
