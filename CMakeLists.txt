project("PokeClone 2 Engine")

cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug CACHE STRING "Type of build: release of debug")
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMakeInclude)
set(BUILD_NAME "PokeClone")

set(CMAKE_SWIG_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "-Wall -std=c++11")

include(sources.cmake)

find_package(SWIG REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(PythonLibs REQUIRED)

set(COMPILER_LIBS ${SDL2_LIBRARY} ${SDL2IMAGE_LIBRARY}
${SDL2TTF_LIBRARY} ${SDL2_MIXER_LIBRARIES} ${PYTHON_LIBRARIES})

include(${SWIG_USE_FILE})


# Para não compilar esses arquivos
set_source_files_properties(${JSON_FILES} PROPERTIES HEADER_FILE_ONLY TRUE)


#add_executable(game ${SRC_THIRDPARTIES}  ${SRC_FILES} ${JSON_FILES} )

include_directories(src/ ThirdParties/  ${PYTHON_INCLUDE_PATH}  ${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2TTF_INCLUDE_DIR} ${SDL2_MIXER_INCLUDE_DIR} )

set_source_files_properties(${INTERFACES} PROPERTIES CPLUSPLUS ON)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Contents
DESTINATION ${CMAKE_BINARY_DIR} )

swig_add_module(${BUILD_NAME} python ${INTERFACES} ${SRC_FILES} ${SRC_THIRDPARTIES} )
swig_link_libraries(${BUILD_NAME} ${COMPILER_LIBS})
