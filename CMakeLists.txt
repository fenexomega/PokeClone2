project("PokeClone 2 Engine" CXX C)

cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug CACHE STRING "Type of build: release of debug")
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMakeInclude)
include(sources.cmake)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

add_executable(game ${SRC_THIRDPARTIES}  ${SRC_FILES} )

include_directories(src/ ThirdParties/ ${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2TTF_INCLUDE_DIR} ${SDL2_MIXER_INCLUDE_DIR} )

set(CMAKE_CXX_FLAGS "-Wall -std=c++11")

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Contents
DESTINATION ${CMAKE_BINARY_DIR} )

set(COMPILER_LIBS ${SDL2_LIBRARY} ${SDL2IMAGE_LIBRARY} ${SDL2TTF_LIBRARY} ${SDL2_MIXER_LIBRARIES})

target_link_libraries(game ${COMPILER_LIBS})

