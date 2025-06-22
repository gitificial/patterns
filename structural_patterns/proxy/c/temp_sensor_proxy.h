#ifndef TEMP_SENSOR_PROXY_H
#define TEMP_SENSOR_PROXY_H

#include <stdint.h>
#include <stdbool.h>

// Proxy API
bool temp_sensor_proxy_init(void);
bool temp_sensor_proxy_get_temperature(float *temperature);

#endif // TEMP_SENSOR_PROXY_H