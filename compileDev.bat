@echo off

REM compile sound to library
cd sound
g++ -c sound.cpp -o libsound.o
ar rcs libsound.a libsound.o
move libsound.o bin
move libsound.a bin
cd ..

REM COMPILING TO BINARY

cd jgw
g++ -D_DEV -c jgw.cpp
g++ -o JGW.exe jgw.o -O3 -foptimize-sibling-calls -L../sound/bin -lsound
move jgw.o bin
move jgw.exe ..
cd ..

move JGW.exe bin
