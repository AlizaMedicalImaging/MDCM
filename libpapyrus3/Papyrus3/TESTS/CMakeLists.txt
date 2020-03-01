# Tests
add_executable(TestRead TestRead.c)
target_link_libraries(TestRead Papyrus3)
set_source_files_properties(TestRead.c PROPERTIES LANGUAGE C)

#add_executable(TestWrite TestWrite.c)
#target_link_libraries(TestWrite Papyrus3)
#set_source_files_properties(TestWrite.c PROPERTIES LANGUAGE C)
