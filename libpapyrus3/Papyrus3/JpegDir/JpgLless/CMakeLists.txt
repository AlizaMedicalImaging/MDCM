# JpgLless
set(SOURCES
	decompoptimise.c
	huffcoptimisebug.c
	huffdoptimise.c
	JPEGUTIL.C
	MCU.C
	pmreadoptimise.c
	pnmtoljpoptimisebug.c
	PREDICT.C
	READ.C
	WRITE.C
	)
set_source_files_properties(PROTO.H PROPERTIES LANGUAGE C)

add_library(JpgLless ${SOURCES})
set_source_files_properties(${SOURCES} PROPERTIES LANGUAGE C)
set_target_properties(JpgLless PROPERTIES LINKER_LANGUAGE C)
