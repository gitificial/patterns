#include <stdio.h>
#include "temp_sensor.h"

int main(void) {
    float temperature;

    // Initialize the temperature sensor
    if (!temp_sensor_init()) {
        printf("Failed to initialize temperature sensor!\n");
        return -1;
    }

    // Read the temperature
    if (temp_sensor_read_temperature(&temperature)) {
        printf("Temperature: %.2f°C\n", temperature);
    } else {
        printf("Failed to read temperature!\n");
    }

    return 0;
}
