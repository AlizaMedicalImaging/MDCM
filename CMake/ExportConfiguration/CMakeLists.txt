configure_file(MDCMConfig.cmake.in
  ${MDCM_BINARY_DIR}/MDCMConfig.cmake
  @ONLY)
install(FILES ${MDCM_BINARY_DIR}/MDCMConfig.cmake
  DESTINATION ${MDCM_INSTALL_PACKAGE_DIR} COMPONENT Headers)

configure_file(MDCMConfigVersion.cmake.in
  ${MDCM_BINARY_DIR}/MDCMConfigVersion.cmake
  @ONLY)
install(FILES ${MDCM_BINARY_DIR}/MDCMConfigVersion.cmake
  DESTINATION ${MDCM_INSTALL_PACKAGE_DIR} COMPONENT Headers)

configure_file(UseMDCM.cmake.in
  ${MDCM_BINARY_DIR}/UseMDCM.cmake
  @ONLY)
install(FILES ${MDCM_BINARY_DIR}/UseMDCM.cmake
  DESTINATION ${MDCM_INSTALL_PACKAGE_DIR} COMPONENT Headers)

install(EXPORT ${MDCM_TARGETS_NAME} DESTINATION ${MDCM_INSTALL_PACKAGE_DIR} COMPONENT Headers)

set(targets
  mdcmCommon
  mdcmDICT
  mdcmDSED
  mdcmMSFF
  mdcmjpeg8
  mdcmjpeg12
  mdcmjpeg16
  mdcmopenjp2
  mdcmcharls
  mdcmzlib
  mdcmuuid)

file(WRITE ${MDCM_BINARY_DIR}/MDCMExports.cmake "")

foreach(target ${targets})
  if(TARGET ${target})
    export(TARGETS ${target} FILE ${MDCM_BINARY_DIR}/MDCMExports.cmake APPEND)
  endif()
endforeach()
