# DicomDir
set(SOURCES
	 DicomDirDataSetRead.c
	 DicomDirDataSetWrite.c
	 DicomDirFiles.c
	 DicomDirInit.c
	 DicomDirInitRecords.c
 	 OGlobalDicomFunc.cpp
  )
#set_source_files_properties(OGlobalDicomFunc.cpp PROPERTIES LANGUAGE "C")

set(HEADERS
	DicomDir.h
	DicomDirEnumRecords.h
	DicomdirGlobalVar3.h
	DicomDirInitRecords.h
	DicomdirPrivFunctionDef3.h
	DicomdirPubFunctionDef3.h
	DicomdirTypeDef3.h
	OGlobalDicomFunc.h
  )

add_library(DicomDir ${SOURCES})
set_source_files_properties(${SOURCES} PROPERTIES LANGUAGE C)
set_target_properties(DicomDir PROPERTIES LINKER_LANGUAGE C)

#install(TARGETS Papyrus3
#  RUNTIME DESTINATION bin
#  LIBRARY DESTINATION lib
#  ARCHIVE DESTINATION lib
#  )
#
#install(FILES
#  DESTINATION include/Papyrus3
#  )
