#include "sensor.h"

// Global variable to control the return value of the stub
float test_temperature = 25.0f;

float read_temperature(void) {
    return test_temperature;
}
