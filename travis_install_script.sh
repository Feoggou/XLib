#!/bin/bash

echo "user=$USER"
gcc --version
g++ --version

set -ev
wget http://www.cmake.org/files/v3.1/cmake-3.1.3.tar.gz
tar -zxf cmake-3.1.3.tar.gz
export CXX=g++
cd cmake-3.1.3
./bootstrap && make && sudo make install
cmake --version