#!/bin/bash
# Bash script to run the test cases for the `smath` library

mkdir -p bin

make clean 2>/dev/null
make
./main
