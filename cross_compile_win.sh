#!/bin/bash
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=/home/jordy/Projects/Cpp/mingw/Toolchain-mingw-i686.cmake -DSDL2_INCLUDE_DIR=/home/jordy/Projects/Cpp/mingw/usr/include/SDL2

