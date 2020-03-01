# Define the srcs for Data Structure and Encoding Definitions
# DSED

# dual compilation (namespace mdcm_ns), all the following either directly
# reference code using MDCM_SUPPORT_BROKEN_IMPLEMENTATION or indirectly
set(DSED2_SRCS
  mdcmByteValue.cxx
  mdcmDataElement.cxx
  mdcmDataSet.cxx
  mdcmExplicitDataElement.cxx
  mdcmFile.cxx # FileMeta is class member
  mdcmFileMetaInformation.cxx # subclass of DataSet
  mdcmFragment.cxx
  mdcmImplicitDataElement.cxx
  mdcmMediaStorage.cxx # SetFromModality takes a DataSet
  mdcmPrivateTag.cxx
  mdcmReader.cxx
  mdcmSequenceOfFragments.cxx
  mdcmSequenceOfItems.cxx
  mdcmValue.cxx # friend decl
  )
# need to prepare duplicate files to help cmake handle setting compile
# definitions (cmake cannot handle duplicate source file in same target).
# this trick allows us to avoid a static compilation which may not be portable
foreach(src ${DSED2_SRCS})
  configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/${src}
    ${CMAKE_CURRENT_BINARY_DIR}/strict_${src}
    COPYONLY
    )
  list(APPEND DSED3_SRCS
    ${CMAKE_CURRENT_BINARY_DIR}/strict_${src}
    )
  set_property(
    SOURCE ${CMAKE_CURRENT_BINARY_DIR}/strict_${src}
    PROPERTY COMPILE_DEFINITIONS "MDCM_OVERRIDE_BROKEN_IMPLEMENTATION" "mdcm_ns=mdcmstrict"
    )
endforeach()

# the following source code do not need a duplicate compilation to handle
# MDCM_SUPPORT_BROKEN_IMPLEMENTATION
set(DSED_SRCS
  ${DSED2_SRCS}
  mdcmReader.strict.cxx # hook to call mdcmstrict API
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
  mdcmVR16ExplicitDataElement.cxx
  )

# Add the include paths
include_directories(
  # Bin:
  "${MDCM_BINARY_DIR}/Source/Common"
  # src:
  "${MDCM_SOURCE_DIR}/Source/Common"
  "${MDCM_SOURCE_DIR}/Source/DataDictionary"
  "${MDCM_SOURCE_DIR}/Source/DataStructureAndEncodingDefinition/"
  "${MDCM_SOURCE_DIR}/Utilities"
 )

if(NOT MDCM_USE_SYSTEM_ZLIB)
  include_directories(
    "${MDCM_BINARY_DIR}/Utilities/mdcmzlib"
    )
endif()

add_library(mdcmDSED ${DSED_SRCS} ${DSED3_SRCS})
target_link_libraries(mdcmDSED LINK_PUBLIC mdcmCommon)
# zlib stuff are actually included (template) so we need to link them here.
target_link_libraries(mdcmDSED LINK_PRIVATE ${MDCM_ZLIB_LIBRARIES})
set_target_properties(mdcmDSED PROPERTIES ${MDCM_LIBRARY_PROPERTIES})

