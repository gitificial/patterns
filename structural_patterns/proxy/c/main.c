#include <stdio.h>
#include "temp_sensor_proxy.h"

int main(void) {
    float temperature;

    // Initialize the proxy
    if (!temp_sensor_proxy_init()) {
        printf("Failed to initialize temperature sensor proxy!\n");
        return -1;
    }

    // Fetch temperature multiple times
    for (int i = 0; i < 3; i++) {
        if (temp_sensor_proxy_get_temperature(&temperature)) {
            printf("Temperature: %.2f°C\n", temperature);
        } else {
            printf("Failed to get temperature!\n");
        }

        // Simulate a delay between reads
        sleep(2);
    }

    return 0;
}
