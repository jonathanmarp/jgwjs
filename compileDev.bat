@echo off

REM compile sound to library
g++ -c jgwjs/sound/sound.cpp -o jgwjs/sound/libsound.o
ar rcs jgwjs/sound/libsound.a jgwjs/sound/libsound.o
move jgwjs/sound/libsound.o jgwjs/sound/bin
move jgwjs/sound/libsound.a jgwjs/sound/bin

REM COMPILING TO BINARY

cd jgw
g++ -D_DEV -c jgwjs/src/jgw.cpp -o jgwjs/src/jgw.o
g++ -o jgwjs/src/JGW.exe jgwjs/src/jgw.o -O3 -foptimize-sibling-calls -Ljgwjs/sound/bin -lsound
move jgwjs/src/jgw.o jgwjs/src/bin

move jgwjs/src/JGW.exe jgwjs/bin