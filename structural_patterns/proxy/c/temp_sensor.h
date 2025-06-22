#ifndef TEMP_SENSOR_H
#define TEMP_SENSOR_H

#include <stdint.h>
#include <stdbool.h>

// Real subject API
bool temp_sensor_init(void);                // Initialize the sensor
bool temp_sensor_read_temperature(float *temperature); // Read temperature

#endif // TEMP_SENSOR_H