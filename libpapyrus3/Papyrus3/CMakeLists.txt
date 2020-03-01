# Copyright Mathieu Malaterre <malat@debian.org>
# LGPL-2.1
cmake_minimum_required(VERSION 2.8)
project(Papyrus3 C)

set(JPEGDIRLL JpegDir/JpgLless)
set(JPEGDIRLY JpegDir/JpgLossy)
set(DICOMDIR  DicomDir)

#set(BUILD_SHARED_LIBS ON)

include_directories(
  ${JPEGDIRLL}
  ${JPEGDIRLY}
  ${DICOMDIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  )

set(SOURCES
  PapyVars3.c
  PapyConvertFile3.c
  PapyError3.c
  PapyFiles3.c
  PapyGetGlobalVar3.c
  PapyInit3.c
  PapyInitGroups3.c
  PapyInitModules3.c
  PapyRead3.c
  PapyDataSetRead3.c
  PapyList3.c
  PapyWrite3.c
  PapyDataSetWrite3.c
  PapyWild3.c
  PapyWildexit3.c
  PapyUtils3.c
  )
set(HEADERS
  PapyEalloc3.h
  PapyEnumGroups3.h
  PapyEnumImageGroups3.h
  PapyEnumImagesModules3.h
  PapyEnumMiscGroups3.h
  PapyEnumMiscModules3.h
  PapyEnumModules3.h
  PapyError3.h
  PapyErrorMacros3.h
  PapyFileSystem3.h
  PapyGlobalVar3.h
  PapyInitModules3.h
  PapyPrivFunctionDef3.h
  PapyPubFunctionDef3.h
  Papyrus3.h
  PapyTypeDef3.h
  PapyWild3.h
  )
if(UNIX)
  list(APPEND SOURCES PapyFileSystemUnix3.c PapyEallocUnix3.c)
endif()
if(WIN32)
  list(APPEND SOURCES PapyFileSystemPC3.c PapyEallocPC3.c)
endif()

list(APPEND SOURCES
  DicomDir/DicomDirDataSetRead.c
  DicomDir/DicomDirDataSetWrite.c
  DicomDir/DicomDirFiles.c
  DicomDir/DicomDirInit.c
  DicomDir/DicomDirInitRecords.c
  DicomDir/OGlobalDicomFunc.cpp
  )
list(APPEND HEADERS
  DicomDir/DicomDir.h
  DicomDir/DicomDirEnumRecords.h
  DicomDir/DicomdirGlobalVar3.h
  DicomDir/DicomDirInitRecords.h
  DicomDir/DicomdirPrivFunctionDef3.h
  DicomDir/DicomdirPubFunctionDef3.h
  DicomDir/DicomdirTypeDef3.h
  DicomDir/OGlobalDicomFunc.h
  )
list(APPEND SOURCES
  JpegDir/JpgLless/decompoptimise.c
  JpegDir/JpgLless/huffcoptimisebug.c
  JpegDir/JpgLless/huffdoptimise.c
  JpegDir/JpgLless/JPEGUTIL.C
  JpegDir/JpgLless/MCU.C
  JpegDir/JpgLless/pmreadoptimise.c
  JpegDir/JpgLless/pnmtoljpoptimisebug.c
  JpegDir/JpgLless/PREDICT.C
  JpegDir/JpgLless/READ.C
  JpegDir/JpgLless/WRITE.C
  )
set_source_files_properties(
  JpegDir/JpgLless/IO.H
  JpegDir/JpgLless/JPEG.H
  JpegDir/JpgLless/JPEGLESS.H
  JpegDir/JpgLless/MCU.H
  JpegDir/JpgLless/PREDICT.H
  JpegDir/JpgLless/PROTO.H
  PROPERTIES LANGUAGE C)

list(APPEND SOURCES
  JpegDir/JpgLossy/JCAPIMIN.C
  JpegDir/JpgLossy/JCAPISTD.C
  JpegDir/JpgLossy/JCCOEFCT.C
  JpegDir/JpgLossy/JCCOLOR.C
  JpegDir/JpgLossy/JCDCTMGR.C
  JpegDir/JpgLossy/JCHUFF.C
  JpegDir/JpgLossy/JCINIT.C
  JpegDir/JpgLossy/JCMAINCT.C
  JpegDir/JpgLossy/JCMARKER.C
  JpegDir/JpgLossy/JCMASTER.C
  JpegDir/JpgLossy/JCOMAPI.C
  JpegDir/JpgLossy/JCPARAM.C
  JpegDir/JpgLossy/JCPHUFF.C
  JpegDir/JpgLossy/JCPREPCT.C
  JpegDir/JpgLossy/JCSAMPLE.C
  JpegDir/JpgLossy/JCTRANS.C
  JpegDir/JpgLossy/JDAPIMIN.C
  JpegDir/JpgLossy/JDAPISTD.C
  JpegDir/JpgLossy/JDATADST.C
  JpegDir/JpgLossy/JDATASRC.C
  JpegDir/JpgLossy/JDCOEFCT.C
  JpegDir/JpgLossy/JDCOLOR.C
  JpegDir/JpgLossy/JDDCTMGR.C
  JpegDir/JpgLossy/JDHUFF.C
  JpegDir/JpgLossy/JDINPUT.C
  JpegDir/JpgLossy/JDMAINCT.C
  JpegDir/JpgLossy/JDMARKER.C
  JpegDir/JpgLossy/JDMASTER.C
  JpegDir/JpgLossy/JDMERGE.C
  JpegDir/JpgLossy/JDPHUFF.C
  JpegDir/JpgLossy/JDPOSTCT.C
  JpegDir/JpgLossy/JDSAMPLE.C
  JpegDir/JpgLossy/JDTRANS.C
  JpegDir/JpgLossy/JERROR.C
  JpegDir/JpgLossy/JFDCTFLT.C
  JpegDir/JpgLossy/JFDCTFST.C
  JpegDir/JpgLossy/JFDCTINT.C
  JpegDir/JpgLossy/JIDCTFLT.C
  JpegDir/JpgLossy/JIDCTFST.C
  JpegDir/JpgLossy/JIDCTINT.C
  JpegDir/JpgLossy/JIDCTRED.C
  JpegDir/JpgLossy/jmemmgr.c
  JpegDir/JpgLossy/JMEMNOBS.C
  JpegDir/JpgLossy/JQUANT1.C
  JpegDir/JpgLossy/JQUANT2.C
  JpegDir/JpgLossy/JUTILS.C
  JpegDir/JpgLossy/RDBMP.C
  JpegDir/JpgLossy/RDCOLMAP.C
  JpegDir/JpgLossy/RDGIF.C
  JpegDir/JpgLossy/RDPPM.C
  JpegDir/JpgLossy/RDRLE.C
  JpegDir/JpgLossy/RDSWITCH.C
  JpegDir/JpgLossy/RDTARGA.C
  JpegDir/JpgLossy/WRRLE.C
  )

add_library(Papyrus3 ${SOURCES})
# http://bugs.debian.org/728108
set_target_properties(Papyrus3 PROPERTIES COMPILE_FLAGS "-x c")
set_source_files_properties(${SOURCES} PROPERTIES LANGUAGE C)
set_target_properties(Papyrus3 PROPERTIES LINKER_LANGUAGE C)

add_subdirectory(TESTS)

install(TARGETS Papyrus3
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  )

install(FILES
  ${HEADERS}
  DESTINATION include/Papyrus3
  )
