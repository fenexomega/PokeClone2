macro(add_test FILE_NAME)
    add_executable(${FILE_NAME} src/Tests/${FILE_NAME}.cpp)
    target_link_libraries(${FILE_NAME} VacilationEngine)
endmacro()

macro(add_game FOLDER_NAME)
    file(GLOB_RECURSE SRC_FILES RELATIVE
        ${CMAKE_CURRENT_SOURCE_DIR} src/${FOLDER_NAME}/*.cpp
        src/${FOLDER_NAME}/*.h src/${FOLDER_NAME}/*.hpp)
    include_directories(src/${FOLDER_NAME})
    add_executable(${FOLDER_NAME} ${SRC_FILES}
                   ${JSON_FILES} ${LUA_FILES} )
    target_link_libraries(${FOLDER_NAME} VacilationEngine)
endmacro()
