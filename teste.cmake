macro(add_test FILE_NAME)
    add_executable(${FILE_NAME} src/Tests/${FILE_NAME}.cpp)
    target_link_libraries(${FILE_NAME} VacilationEngine)
endmacro()
