set(DSED_SRCS
  mdcmByteValue.cxx
  mdcmDataElement.cxx
  mdcmDataSet.cxx
  mdcmExplicitDataElement.cxx
  mdcmFile.cxx
  mdcmFileMetaInformation.cxx
  mdcmFragment.cxx
  mdcmImplicitDataElement.cxx
  mdcmMediaStorage.cxx
  mdcmPrivateTag.cxx
  mdcmReader.cxx
  mdcmSequenceOfFragments.cxx
  mdcmSequenceOfItems.cxx
  mdcmValue.cxx
  mdcmTag.cxx
  mdcmTagToVR.cxx
  mdcmCodeString.cxx
  mdcmFileSet.cxx
  mdcmByteSwapFilter.cxx
  mdcmUNExplicitImplicitDataElement.cxx
  mdcmWriter.cxx
  mdcmCSAHeader.cxx
  mdcmMrProtocol.cxx
  mdcmTransferSyntax.cxx
  mdcmVM.cxx
  mdcmVR.cxx
  mdcmPreamble.cxx
  mdcmUNExplicitDataElement.cxx
  mdcmCP246ExplicitDataElement.cxx
  mdcmExplicitImplicitDataElement.cxx
  mdcmVR16ExplicitDataElement.cxx)

# Add the include paths
include_directories(
  "${MDCM_BINARY_DIR}/Source/Common"
  "${MDCM_SOURCE_DIR}/Source/Common"
  "${MDCM_SOURCE_DIR}/Source/DataDictionary"
  "${MDCM_SOURCE_DIR}/Source/DataStructureAndEncodingDefinition/"
  "${MDCM_SOURCE_DIR}/Utilities")

if(NOT MDCM_USE_SYSTEM_ZLIB)
  include_directories("${MDCM_BINARY_DIR}/Utilities/mdcmzlib")
endif()

add_library(mdcmdsed ${DSED_SRCS})
target_link_libraries(mdcmdsed LINK_PUBLIC mdcmcommon)
# zlib stuff are actually included (template) so we need to link them here.
target_link_libraries(mdcmdsed LINK_PRIVATE ${MDCM_ZLIB_LIBRARIES})
set_target_properties(mdcmdsed PROPERTIES ${MDCM_LIBRARY_PROPERTIES})

install_library(mdcmdsed)
install_pdb(mdcmdsed)
install_includes("*.h" "*.txx")
