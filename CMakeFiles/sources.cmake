file(GLOB_RECURSE ENGINE_SRC_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/Engine/*.cpp src/Engine/*.h)

file(GLOB_RECURSE SRC_THIRDPARTIES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
src/ThirdParties/*.cpp src/ThirdParties/*.h src/ThirdParties/*.hpp src/ThirdParties/*.cxx)

file(GLOB_RECURSE JSON_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} Contents/*.json)

file(GLOB_RECURSE LUA_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} Contents/*.lua)

set(SRC_FILES
    src/Main.cpp
)


