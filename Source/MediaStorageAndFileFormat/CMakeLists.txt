# Define the srcs for Media Storage And FileFormat
# MSFF
set(MSFF_SRCS
  mdcmFileStreamer.cxx
  mdcmIconImageFilter.cxx
  mdcmIconImageGenerator.cxx
  mdcmDICOMDIRGenerator.cxx
  mdcmFileExplicitFilter.cxx
  mdcmFileDerivation.cxx
  mdcmImageFragmentSplitter.cxx
  mdcmTagPath.cxx
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
  mdcmSorter.cxx
  mdcmIPPSorter.cxx
  mdcmSplitMosaicFilter.cxx
  mdcmUIDGenerator.cxx
  mdcmUUIDGenerator.cxx
  mdcmScanner.cxx
  mdcmStrictScanner.cxx
  mdcmPixmapReader.cxx
  mdcmImageReader.cxx
  mdcmPixmapWriter.cxx
  mdcmImageWriter.cxx
  mdcmStringFilter.cxx
  mdcmImageHelper.cxx
  mdcmValidate.cxx
  mdcmImage.cxx
  mdcmImageConverter.cxx
  mdcmImageCodec.cxx
  mdcmJPEG12Codec.cxx
  mdcmRLECodec.cxx
  mdcmJPEG16Codec.cxx
  mdcmJPEGLSCodec.cxx
  mdcmJPEG8Codec.cxx
  mdcmJPEGCodec.cxx
  mdcmPVRGCodec.cxx
  mdcmKAKADUCodec.cxx
  mdcmPNMCodec.cxx
  mdcmPGXCodec.cxx
  mdcmRAWCodec.cxx
  mdcmLookupTable.cxx
  mdcmOverlay.cxx
  mdcmCurve.cxx
  mdcmPhotometricInterpretation.cxx
  mdcmPixelFormat.cxx
  mdcmSegmentedPaletteColorLookupTable.cxx
  mdcmStreamImageReader.cxx
  #mdcmImageRegionReader.cxx
  mdcmDirectoryHelper.cxx
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
  mdcmSerieHelper.cxx
  )

  list(APPEND MSFF_SRCS
    ${MDCM_SOURCE_DIR}/Utilities/mdcmrle/rle.cxx
    ${MDCM_SOURCE_DIR}/Utilities/mdcmrle/info.cxx
    ${MDCM_SOURCE_DIR}/Utilities/mdcmrle/io.cxx
  )

if(NOT BUILD_SHARED_LIBS)
  set_source_files_properties(mdcmJPEG2000Codec.cxx
                            PROPERTIES
                            COMPILE_FLAGS -DOPJ_STATIC
                            )
  set_source_files_properties(mdcmJPEGLSCodec.cxx
                            PROPERTIES
                            COMPILE_DEFINITIONS CHARLS_STATIC
                            )
else()
  set_source_files_properties(mdcmJPEGLSCodec.cxx
                              PROPERTIES
                              COMPILE_FLAGS -DCHARLS_DLL
                              )
endif()

# Add the include paths
include_directories(
  "${MDCM_SOURCE_DIR}/Source/Common"
  "${MDCM_BINARY_DIR}/Source/Common"
  "${MDCM_SOURCE_DIR}/Source/DataStructureAndEncodingDefinition"
  "${MDCM_SOURCE_DIR}/Source/DataDictionary"
  "${MDCM_SOURCE_DIR}/Source/InformationObjectDefinition"
  ${CMAKE_CURRENT_SOURCE_DIR}

  # FIXME:
  "${MDCM_SOURCE_DIR}/Utilities"
  "${MDCM_BINARY_DIR}/Utilities"
  )

# CharLS
if(MDCM_USE_SYSTEM_CHARLS)
  include_directories(${CHARLS_INCLUDE_DIRS} )
else()
  include_directories(
  "${MDCM_BINARY_DIR}/Utilities/mdcmcharls"
    )
endif()
if(MDCM_USE_SYSTEM_OPENJPEG)
  include_directories(${OPENJPEG_INCLUDE_DIRS} )
message(STATUS "OpenJPEG include dir: " ${OPENJPEG_INCLUDE_DIRS})
else()
  include_directories(
  "${MDCM_BINARY_DIR}/Utilities/mdcmopenjpeg"
  "${MDCM_BINARY_DIR}/Utilities/mdcmopenjpeg/src/lib/openjp2"
    )
endif()
if(MDCM_USE_SYSTEM_LJPEG)
  include_directories(${LJPEG_INCLUDE_DIRS} )
endif()
if(NOT MDCM_USE_SYSTEM_ZLIB)
  include_directories(
    "${MDCM_BINARY_DIR}/Utilities/mdcmzlib"
  )
endif()
if(MDCM_USE_SYSTEM_UUID)
  include_directories(
    ${UUID_INCLUDE_DIR}
  )
  set(MDCMUUID ${UUID_LIBRARIES})
else()
  include_directories(
    "${MDCM_BINARY_DIR}/Utilities/mdcmuuid" # uuid_mangle.h
  )
  set(MDCMUUID mdcmuuid)
endif()

add_library(mdcmMSFF ${MSFF_SRCS})
# mdcmPVRGCodec calls mdcmjpeg
if(MDCM_USE_PVRG)
  if(NOT MDCM_USE_SYSTEM_PVRG)
    add_dependencies(mdcmMSFF mdcmjpeg)
  endif()
endif()

# main libs:
target_link_libraries(mdcmMSFF LINK_PUBLIC mdcmDSED mdcmDICT)
target_link_libraries(mdcmMSFF LINK_PRIVATE ${MDCM_LJPEG_LIBRARIES} ${MDCM_OPENJPEG_LIBRARIES})
if(MDCM_USE_JPEGLS)
  target_link_libraries(mdcmMSFF LINK_PRIVATE ${MDCM_CHARLS_LIBRARIES})
endif()

if(CMAKE_COMPILER_IS_GNUCXX AND MINGW)
  # I am getting:
# CMakeFiles/mdcmMSFF.dir/mdcmScanner.obj(.text$_ZN4mdcm6ReaderC1Ev[mdcm::Reader::Reader()]+0x3a):mdcmScanner.cxx: variable 'vtable for mdcm::Reader' can't be auto-imported. Please read the documentation for ld's --enable-auto-import for details.
# CMakeFiles/mdcmMSFF.dir/mdcmImageReader.obj(.text$_ZN4mdcm6ReaderC2Ev[mdcm::Reader::Reader()]+0x3a):mdcmImageReader.cxx: variable 'vtable for mdcm::Reader' can't be auto-imported. Please read the documentation for ld's --enable-auto-import for details.
# CMakeFiles/mdcmMSFF.dir/mdcmImageWriter.obj(.text$_ZN4mdcm6WriterC2Ev[mdcm::Writer::Writer()]+0x3a):mdcmImageWriter.cxx: variable 'vtable for mdcm::Writer' can't be auto-imported. Please read the documentation for ld's --enable-auto-import for details.

  set_target_properties(mdcmMSFF PROPERTIES LINK_FLAGS "-Wl,--enable-runtime-pseudo-reloc")
endif()
#if(HAVE_UUIDCREATE)
if(WIN32)
  # For UuidCreate
  # http://msdn.microsoft.com/en-us/library/aa379205(VS.85).aspx
  target_link_libraries(mdcmMSFF LINK_PRIVATE rpcrt4)
#endif()
else()
  target_link_libraries(mdcmMSFF LINK_PRIVATE ${MDCMUUID})
endif()
# handling of static lib within shared is a mess:
#target_link_libraries(mdcmMSFF mdcmrle)
set_target_properties(mdcmMSFF PROPERTIES ${MDCM_LIBRARY_PROPERTIES})

