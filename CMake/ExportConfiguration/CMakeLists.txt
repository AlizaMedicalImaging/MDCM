configure_file( MDCMConfig.cmake.in
  ${MDCM_BINARY_DIR}/MDCMConfig.cmake
  @ONLY
)

configure_file( MDCMConfigVersion.cmake.in
  ${MDCM_BINARY_DIR}/MDCMConfigVersion.cmake
  @ONLY
)

configure_file( UseMDCM.cmake.in
  ${MDCM_BINARY_DIR}/UseMDCM.cmake
  @ONLY
)

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
  mdcmuuid
  )
file(WRITE ${MDCM_BINARY_DIR}/MDCMExports.cmake "")
foreach(target ${targets})
  if(TARGET ${target})
    export(TARGETS ${target} FILE ${MDCM_BINARY_DIR}/MDCMExports.cmake APPEND)
  endif()
endforeach()
