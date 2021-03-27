#include <stdio.h>
#include <unistd.h>
#include "loading.h"

void loading_I(int microsecond) {
	usleep(microsecond);
}

void loading_D(double seconds) {
	unsigned int microsecond = 1000000;
	usleep(seconds * microsecond);
}
