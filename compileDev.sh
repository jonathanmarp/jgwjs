# compile sound to library
g++ -c jgwjs/sound/sound.cpp -o jgwjs/sound/libsound.o
ar rcs jgwjs/sound/libsound.a jgwjs/sound/libsound.o
mv jgwjs/sound/libsound.o jgwjs/sound/bin
mv jgwjs/sound/libsound.a jgwjs/sound/bin

# compile to executable
g++ -D_DEV -c jgwjs/src/jgw.cpp -o jgwjs/src/jgw.o
g++ -o jgwjs/src/JGW jgwjs/src/jgw.o -O3 -foptimize-sibling-calls -Ljgwjs/sound/bin -lsound `sdl2-config --cflags --libs`
mv jgwjs/src/jgw.o jgwjs/src/bin

mv jgwjs/src/JGW jgwjs/bin