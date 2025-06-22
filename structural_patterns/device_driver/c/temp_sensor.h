#ifndef TEMP_SENSOR_H
#define TEMP_SENSOR_H

#include <stdint.h>
#include <stdbool.h>

// Define the I2C address of the temperature sensor
#define TEMP_SENSOR_I2C_ADDRESS 0x48

// Driver API
bool temp_sensor_init(void);                // Initialize the sensor
bool temp_sensor_read_temperature(float *temperature); // Read temperature

#endif // TEMP_SENSOR_H
