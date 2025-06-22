#include "temp_sensor_proxy.h"
#include "temp_sensor.h" // Real subject

#include <time.h> // For simulating time-based caching

// Cached data and metadata
static float cached_temperature = 0.0;
static time_t last_read_time = 0;
static const int CACHE_TIMEOUT_SECONDS = 5; // Cache timeout duration

// Initialize the proxy and the real subject
bool temp_sensor_proxy_init(void) {
    return temp_sensor_init();
}

// Get temperature through the proxy
bool temp_sensor_proxy_get_temperature(float *temperature) {
    time_t current_time = time(NULL);

    // Check if cache is valid
    if (difftime(current_time, last_read_time) < CACHE_TIMEOUT_SECONDS) {
        *temperature = cached_temperature;
        return true; // Return cached value
    }

    // Cache expired or first read; fetch from the real subject
    if (temp_sensor_read_temperature(&cached_temperature)) {
        last_read_time = current_time;
        *temperature = cached_temperature;
        return true;
    }

    return false; // Failed to read from the real subject
}
