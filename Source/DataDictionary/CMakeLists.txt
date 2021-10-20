include_directories(
  "${MDCM_SOURCE_DIR}/Source/Common"
  "${MDCM_BINARY_DIR}/Source/Common"
  "${MDCM_SOURCE_DIR}/Source/DataStructureAndEncodingDefinition"
  "${MDCM_SOURCE_DIR}/Source/DataDictionary")

set(DICT_SRCS
  mdcmDicts.cxx
  mdcmDefaultDicts.cxx
  mdcmPrivateDefaultDicts.cxx
  mdcmGlobal.cxx
  mdcmUIDs.cxx
  mdcmCSAHeaderDefaultDicts.cxx)

add_library(mdcmdict ${DICT_SRCS})
target_link_libraries(mdcmdict LINK_PRIVATE mdcmdsed)
set_target_properties(mdcmdict PROPERTIES ${MDCM_LIBRARY_PROPERTIES})

install_library(mdcmdict)
install_pdb(mdcmdict)
install_includes("*.h")
