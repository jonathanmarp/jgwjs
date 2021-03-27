@echo off

REM compile sound to library
cd sound
g++ -c sound.cpp -o libsound.o
ar rcs libsound.a libsound.o
move libsound.o bin
move libsound.a bin
cd ..

REM compile frequency to library
cd frequency
g++ -c frequency.cpp -o libfrequency.o
ar rcs libfrequency.a libfrequency.o
move libfrequency.o bin
move libfrequency.a bin
cd ..

REM compile loading to library
cd loading
g++ -c loading.cpp -o libloading.o
ar rcs libloading.a libloading.o
move libloading.o bin
move libloading.a bin
cd ..

REM compile getFile to library
cd getFile
g++ -c getFile.cpp -o libgetFile.o
ar rcs libgetFile.a libgetFile.o
move libgetFile.o bin
move libgetFile.a bin
cd ..

REM COMPILING TO BINARY

cd jgw
g++ -c jgw.cpp
g++ -o JGW.exe jgw.o -O3 -foptimize-sibling-calls -L../sound/bin -lsound -L../getFile/bin -lgetFile
move jgw.o bin
move jgw.exe ..
cd ..

cd jgw_compile
g++ -c jgw_compile.cpp
g++ -o JGW_COMPILE.exe jgw_compile.o -O3 -foptimize-sibling-calls -L../getFile/bin -lgetFile -L../frequency/bin -lfrequency -L../loading/bin -lloading
move jgw_compile.o bin
move jgw_compile.exe ..
cd ..

cd wav
g++ -c wav.cpp
g++ -c prt.cpp
g++ -o JGW_WAV_COMPILE wav.o prt.o
move wav.o bin
move prt.o bin
move JGW_WAV_COMPILE ..
cd ..

move JGW.exe bin
move JGW_COMPILE.exe bin
move JGW_WAV_COMPILE bin
