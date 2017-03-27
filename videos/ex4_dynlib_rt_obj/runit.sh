#!/bin/bash

echo "> ldd example4"
ldd ./example4

echo "> ./example4"
./example4

echo "> ./example4 ./libkoala.so"
./example4 ./libkoala.so

echo "> ./example4 ./libpanda.so"
./example4 ./libpanda.so
