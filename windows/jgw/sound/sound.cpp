#include <iostream>
#include "sound.h"

void tone(double Hz_S, int duration_S) {
    Beep((double)Hz_S, (int)duration_S * 10);
}