set(MSFF_SRCS
  mdcmIconImageFilter.cxx
  mdcmDICOMDIRGenerator.cxx
  mdcmFileExplicitFilter.cxx
  mdcmImageFragmentSplitter.cxx
  mdcmSimpleSubjectWatcher.cxx
  mdcmPixmap.cxx
  mdcmBitmap.cxx
  mdcmRescaler.cxx
  mdcmImageToImageFilter.cxx
  mdcmBitmapToBitmapFilter.cxx
  mdcmPixmapToPixmapFilter.cxx
  mdcmImageChangeTransferSyntax.cxx
  mdcmImageApplyLookupTable.cxx
  mdcmApplySupplementalLUT.cxx
  mdcmFileDecompressLookupTable.cxx
  mdcmOrientation.cxx
  mdcmDataSetHelper.cxx
  mdcmImageChangePlanarConfiguration.cxx
  mdcmDirectionCosines.cxx
  mdcmSplitMosaicFilter.cxx
  mdcmUIDGenerator.cxx
  mdcmUUIDGenerator.cxx
  mdcmScanner.cxx
  mdcmPixmapReader.cxx
  mdcmImageReader.cxx
  mdcmPixmapWriter.cxx
  mdcmImageWriter.cxx
  mdcmStringFilter.cxx
  mdcmImageHelper.cxx
  mdcmImage.cxx
  mdcmImageCodec.cxx
  mdcmJPEG12Codec.cxx
  mdcmRLECodec.cxx
  mdcmJPEG16Codec.cxx
  mdcmJPEGLSCodec.cxx
  mdcmJPEG8Codec.cxx
  mdcmJPEGCodec.cxx
  mdcmPVRGCodec.cxx
  mdcmKAKADUCodec.cxx
  mdcmRAWCodec.cxx
  mdcmLookupTable.cxx
  mdcmOverlay.cxx
  mdcmCurve.cxx
  mdcmPhotometricInterpretation.cxx
  mdcmPixelFormat.cxx
  mdcmSegmentedPaletteColorLookupTable.cxx
  mdcmSegment.cxx
  mdcmSurface.cxx
  mdcmMeshPrimitive.cxx
  mdcmSegmentWriter.cxx
  mdcmSurfaceWriter.cxx
  mdcmSegmentReader.cxx
  mdcmSurfaceReader.cxx
  mdcmSurfaceHelper.cxx
  mdcmSegmentHelper.cxx
  mdcmJPEG2000Codec.cxx
  mdcmrle/rle.cxx
  mdcmrle/info.cxx
  mdcmrle/io.cxx)

if(NOT MDCM_USE_SYSTEM_OPENJPEG)
  if(NOT BUILD_SHARED_LIBS)
    set_source_files_properties(mdcmJPEG2000Codec.cxx
      PROPERTIES
      COMPILE_FLAGS -DOPJ_STATIC)
  endif()
endif()

#FIXME
if(NOT BUILD_SHARED_LIBS)
  set_source_files_properties(mdcmJPEGLSCodec.cxx
    PROPERTIES
    COMPILE_DEFINITIONS CHARLS_STATIC)
else()
  set_source_files_properties(mdcmJPEGLSCodec.cxx
    PROPERTIES
    COMPILE_FLAGS -DCHARLS_DLL)
endif()
#

#FIXME
include_directories(
  "${MDCM_SOURCE_DIR}/Source/Common"
  "${MDCM_BINARY_DIR}/Source/Common"
  "${MDCM_SOURCE_DIR}/Source/DataStructureAndEncodingDefinition"
  "${MDCM_SOURCE_DIR}/Source/DataDictionary"
  ${CMAKE_CURRENT_SOURCE_DIR}
  "${MDCM_SOURCE_DIR}/Utilities"
  "${MDCM_BINARY_DIR}/Utilities")

if(MDCM_USE_SYSTEM_CHARLS)
  include_directories(${CHARLS_INCLUDE_DIRS})
else()
  include_directories("${MDCM_BINARY_DIR}/Utilities/mdcmcharls")
endif()

if(MDCM_USE_SYSTEM_OPENJPEG)
  include_directories(${OPENJPEG_INCLUDE_DIRS})
else()
  include_directories(
    "${MDCM_BINARY_DIR}/Utilities/mdcmopenjpeg"
    "${MDCM_BINARY_DIR}/Utilities/mdcmopenjpeg/src/lib/openjp2")
endif()

if(MDCM_USE_SYSTEM_LJPEG)
  include_directories(${LJPEG_INCLUDE_DIRS})
endif()

if(NOT MDCM_USE_SYSTEM_ZLIB)
  include_directories("${MDCM_BINARY_DIR}/Utilities/mdcmzlib")
endif()

if(MDCM_USE_SYSTEM_UUID)
  include_directories(${UUID_INCLUDE_DIR})
  set(MDCMUUID ${UUID_LIBRARIES})
else()
  include_directories("${MDCM_BINARY_DIR}/Utilities/mdcmuuid")
  set(MDCMUUID mdcmuuid)
endif()

add_library(mdcmmsff ${MSFF_SRCS})
# PVRG codec calls mdcmpvrg executable
if(MDCM_USE_PVRG)
  if(NOT MDCM_USE_SYSTEM_PVRG)
    add_dependencies(mdcmmsff mdcmpvrg)
  endif()
endif()

target_link_libraries(mdcmmsff LINK_PUBLIC mdcmdsed mdcmdict)
target_link_libraries(mdcmmsff LINK_PRIVATE ${MDCM_LJPEG_LIBRARIES} ${MDCM_OPENJPEG_LIBRARIES})
target_link_libraries(mdcmmsff LINK_PRIVATE ${MDCM_CHARLS_LIBRARIES})

if(CMAKE_COMPILER_IS_GNUCXX AND MINGW)
  # not tested
  set_target_properties(mdcmmsff PROPERTIES LINK_FLAGS "-Wl,--enable-runtime-pseudo-reloc")
endif()

if(WIN32)
  # For UuidCreate
  # http://msdn.microsoft.com/en-us/library/aa379205(VS.85).aspx
  target_link_libraries(mdcmmsff LINK_PRIVATE rpcrt4)
else()
  target_link_libraries(mdcmmsff LINK_PRIVATE ${MDCMUUID})
endif()

set_target_properties(mdcmmsff PROPERTIES ${MDCM_LIBRARY_PROPERTIES})

install_library(mdcmmsff)
install_pdb(mdcmmsff)
install_includes("*.h" "*.txx")
