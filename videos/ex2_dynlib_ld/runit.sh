#!/bin/bash

echo "> ldd example2"
ldd ./example2

echo "> ./example2"

./example2

echo "> export LD_LIBRARY_PATH=\"./\""
export LD_LIBRARY_PATH="./"

echo "> ldd example2"

ldd ./example2

echo "> ./example2"

./example2

