#!/bin/bash
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=/home/jordy/Projects/Cpp/mingw/config.cmake 
make game 
