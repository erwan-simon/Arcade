#!/bin/bash

echo "> ldd example3"
ldd ./example3

echo "> mv libkoala.so libkoala.so.old"
mv libkoala.so libkoala.so.old
echo "> ./example3"
./example3
echo "> mv libkoala.so.old libkoala.so"
mv libkoala.so.old libkoala.so
echo "> ./example3"
./example3
