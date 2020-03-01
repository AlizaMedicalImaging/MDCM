include_directories(
  "${MDCM_SOURCE_DIR}/Source/Common"
  "${MDCM_BINARY_DIR}/Source/Common"
  "${MDCM_SOURCE_DIR}/Source/DataStructureAndEncodingDefinition"
  "${MDCM_SOURCE_DIR}/Source/DataDictionary"
  )

set(DICT_SRCS
  mdcmDicts.cxx
  mdcmDictEntry.cxx
  mdcmDefaultDicts.cxx
  mdcmPrivateDefaultDicts.cxx
  mdcmGlobal.cxx
  mdcmGroupDict.cxx
  mdcmDefaultGroupNames.cxx
  mdcmUIDs.cxx
  mdcmCSAHeaderDefaultDicts.cxx
  )

add_library(mdcmDICT ${DICT_SRCS})
target_link_libraries(mdcmDICT LINK_PRIVATE mdcmDSED)
set_target_properties(mdcmDICT PROPERTIES ${MDCM_LIBRARY_PROPERTIES})

