@echo off
REM Compile Default it's g++, support for clang (clang+)
set COMPILER=g++
set NAME_OUTPUT=jgw
set OUTPUT_FOLDER=out
set OUTPUT_SRC=out_src
REM if you won't in release mode remove -D_DEV
set FLAGS_COMPILE_OUT=-I app/header -I src -D_DEV
set LIST_FILE=jgw.cpp app/worker/sound.cpp app/worker/fileshelp.cpp app/worker/frequency.cpp app/worker/sound.cpp
set LIST_SRC=jgw.o fileshelp.o frequency.o sound.o

if exist %OUTPUT_FOLDER%\ (
  echo Folder %OUTPUT_FOLDER% it's exist
) else (
  mkdir %OUTPUT_FOLDER%
)

if exist %OUTPUT_SRC%\ (
  echo Folder %OUTPUT_SRC% it's exist
) else (
  mkdir %OUTPUT_SRC%
)

(for %%a in (%LIST_FILE%) do (
   echo Compile File: %%a
   %COMPILER% -c %FLAGS_COMPILE_OUT% %%a
))

echo Compile to binary name %OUTPUT_FOLDER%/%NAME_OUTPUT%.exe
%COMPILER% -O3 %LIST_SRC% -o %NAME_OUTPUT%.exe

move %NAME_OUTPUT%.exe %OUTPUT_FOLDER%
move *.o %OUTPUT_SRC%
