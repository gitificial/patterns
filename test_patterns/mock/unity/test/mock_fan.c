#include <stdio.h>
#include "hardware.h"

int last_fan_state = -1;
int fan_set_state_called = 0;

void fan_set_state(int on) {
    last_fan_state = on;
    fan_set_state_called++;
}

// Provide a test-controlled temperature
float test_temperature = 0.0;

float read_temperature(void) {
    return test_temperature;
}
