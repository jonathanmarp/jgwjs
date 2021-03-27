#include <stdio.h>
#include "loading.h"

#ifdef WIN32
#include <windows.h>

void loading_I(int microsecond) {
	Sleep(microsecond);
}

void loading_D(double seconds) {
	unsigned int microsecond = 1000000;
	Sleep(seconds * microsecond);
}
#else
#include <unistd.h>

void loading_I(int microsecond) {
	usleep(microsecond);
}

void loading_D(double seconds) {
	unsigned int microsecond = 1000000;
	usleep(seconds * microsecond);
}
#endif