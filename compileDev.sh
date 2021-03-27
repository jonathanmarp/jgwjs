# compile sound to library
cd sound
g++ -c sound.cpp -o libsound.o
ar rcs libsound.a libsound.o
mv libsound.o bin
mv libsound.a bin
cd ..

# compile to executable
cd src
g++ -D_DEV -c jgw.cpp
g++ -o JGW jgw.o -O3 -foptimize-sibling-calls -L../sound/bin -lsound `sdl2-config --cflags --libs`
mv jgw.o bin
mv JGW ..
cd ..

mv JGW bin
