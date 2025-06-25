#include <stdio.h>
#include "sensor.h"

const float OVERHEAT_THRESHOLD = 75.0;

int check_overheat(void) {
    float temp = read_temperature();  // real or stubbed
    return temp >= OVERHEAT_THRESHOLD;
}
