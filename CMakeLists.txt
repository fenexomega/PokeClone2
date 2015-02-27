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
####################################################################################
####################################################################################
# Verificar se é Release
if( CMAKE_BUILD_TYPE STREQUAL "Release")
    add_definitions(-DRELEASE)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -rdynamic")
####################################################################################
####################################################################################

include_directories(src/Engine ThirdParties/ ${SDL2_INCLUDE_DIR}
${SDL2_IMAGE_INCLUDE_DIR} ${SDL2TTF_INCLUDE_DIR} ${SDL2_MIXER_INCLUDE_DIR}
 ${LUA_INCLUDE_DIR} )

set(COMPILER_LIBS ${SDL2_LIBRARY} ${SDL2IMAGE_LIBRARY}
${SDL2TTF_LIBRARY} ${SDL2_MIXER_LIBRARIES} ${LUA_LIBRARY})

####################################################################################
# Para não compilar esses arquivos
set_source_files_properties(${JSON_FILES} PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties(${LUA_FILES} PROPERTIES HEADER_FILE_ONLY TRUE)

####################################################################################
# Adiciona a biblioteca para compilar, estática
add_library(VacilationEngine STATIC ${SRC_THIRDPARTIES}  ${ENGINE_SRC_FILES})

add_executable(game ${SRC_FILES} ${JSON_FILES} ${LUA_FILES})


target_link_libraries(VacilationEngine ${COMPILER_LIBS})
target_link_libraries(game VacilationEngine)
####################################################################################
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Contents
DESTINATION ${CMAKE_BINARY_DIR} )
####################################################################################
include(teste.cmake)

add_test(Physics_Test)

