#!/bin/bash
rm -rf build output
mkdir build
mkdir output
cd build
cmake ..
cmake --build .
clear
./proj2 --help