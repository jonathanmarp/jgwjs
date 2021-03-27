# compile sound to library
cd sound
g++ -c `sdl2-config --cflags --libs` sound.cpp -o libsound.o
ar rcs libsound.a libsound.o
mv libsound.o bin
mv libsound.a bin
cd ..

# compile frequency to library
cd frequency
g++ -c frequency.cpp -o libfrequency.o
ar rcs libfrequency.a libfrequency.o
mv libfrequency.o bin
mv libfrequency.a bin
cd ..

# compile loading to library
cd loading
g++ -c loading.cpp -o libloading.o
ar rcs libloading.a libloading.o
mv libloading.o bin
mv libloading.a bin
cd ..

# compile getFile to library
cd getFile
g++ -c getFile.cpp -o libgetFile.o
ar rcs libgetFile.a libgetFile.o
mv libgetFile.o bin
mv libgetFile.a bin
cd ..

# compile to executable
cd src
g++ -D_DEV -c jgw.cpp
g++ -D_DEV -c compile.cpp
g++ -o JGW_COMPILE compile.o -O3 -foptimize-sibling-calls -L../getFile/bin -lgetFile -L../frequency/bin -lfrequency -L../loading/bin -lloading 
g++ -o JGW jgw.o -O3 -foptimize-sibling-calls -L../sound/bin -lsound -L../getFile/bin -lgetFile `sdl2-config --cflags --libs`
mv jgw.o bin
mv compile.o bin
mv JGW ..
mv JGW_COMPILE ..
cd ..

cd wav
g++ -c wav.cpp
g++ -c prt.cpp
g++ -o JGW_WAV_COMPILE wav.o prt.o
mv wav.o bin
mv prt.o bin
mv JGW_WAV_COMPILE ..
cd ..

mv JGW_COMPILE bin
mv JGW bin
mv JGW_WAV_COMPILE bin

rm -rf bin/jgw bin/jgw_compile
