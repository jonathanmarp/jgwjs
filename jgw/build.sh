# all script in app using format .cpp
# settings all variable in this
COMPILE="g++" # default compile: g++, support for clang (clang+)
NAME_OUTPUT="jgw"
FILES=("jgw.cpp" "app/worker/sound.cpp" "app/worker/fileshelp.cpp" \
	"app/worker/frequency.cpp")
FILES_NAME=("jgw" "sound" "fileshelp" "frequency")
# if you won't in release in mode remove -D_DEV in variable FLAGS_COMPILE_OUT
FLAGS_COMPILE_OUT="-I app/header -I src -D_DEV"
FLAGS_COMPILE_FINISH="`sdl2-config --cflags --libs`"
OUT_BINARY_SRC="out_src"
OUT_BINARY_FINISH="out"

# check its exist folder out_src
if [ -d "$OUT_BINARY_SRC" ] 
then
    rm -rf $OUT_BINARY_SRC
    mkdir $OUT_BINARY_SRC
else
    mkdir $OUT_BINARY_SRC
fi

# check its exist folder out
if [ -d "$OUT_BINARY_FINISH" ] 
then
    printf "Exist Folder: ${OUT_BINARY_FINISH}\n"
else
    mkdir $OUT_BINARY_FINISH
fi

# color in compile
GREEN="\033[0;32m"
NC="\033[0m"

# compile all files
for i in ${!FILES[@]}; do
	printf "[$i] ${GREEN}Compile: ${FILES[$i]}${NC}\n"
	${COMPILE} -c $FLAGS_COMPILE_OUT ${FILES[$i]}
done

# compile to binary
ALL_LIST_FILE=""
for i in ${!FILES_NAME[@]}; do
  ALL_LIST_FILE="${ALL_LIST_FILE} ${FILES_NAME[$i]}.o"
done

printf "[FINISH] ${GREEN}Compile: ${ALL_LIST_FILE}${NC} to: ${NAME_OUTPUT} Binary\n"
${COMPILE} -O3 -o $OUT_BINARY_FINISH/$NAME_OUTPUT $ALL_LIST_FILE $FLAGS_COMPILE_FINISH

# move all file to out_src
mv *.o $OUT_BINARY_SRC
