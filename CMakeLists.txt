project("PokeClone 2 Engine" CXX)

cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug CACHE STRING "Type of build: release of debug")
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMakeInclude)
include(sources.cmake)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(Lua 5.2 REQUIRED)

# Para não compilar esses arquivos
set_source_files_properties(${JSON_FILES} PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties(${LUA_FILES} PROPERTIES HEADER_FILE_ONLY TRUE)


add_executable(game ${SRC_THIRDPARTIES}  ${SRC_FILES} ${JSON_FILES} ${LUA_FILES} )

include_directories(src/ ThirdParties/ ${SDL2_INCLUDE_DIR}
${SDL2_IMAGE_INCLUDE_DIR} ${SDL2TTF_INCLUDE_DIR} ${SDL2_MIXER_INCLUDE_DIR}
 ${LUA_INCLUDE_DIR} )

if( CMAKE_BUILD_TYPE STREQUAL "Release")
    add_definitions(-DRELEASE)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
else
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -rdynamic")

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Contents
DESTINATION ${CMAKE_BINARY_DIR} )

set(COMPILER_LIBS ${SDL2_LIBRARY} ${SDL2IMAGE_LIBRARY}
${SDL2TTF_LIBRARY} ${SDL2_MIXER_LIBRARIES} ${LUA_LIBRARY})

target_link_libraries(game ${COMPILER_LIBS})

