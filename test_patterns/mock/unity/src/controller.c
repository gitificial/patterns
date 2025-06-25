#include "hardware.h"

#define THRESHOLD 75.0f

void monitor_temperature(void) {
    float temp = read_temperature();
    if (temp >= THRESHOLD)
        fan_set_state(1);
    else
        fan_set_state(0);
}
