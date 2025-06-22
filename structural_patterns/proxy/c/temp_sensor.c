#include "temp_sensor.h"
#include "i2c_driver.h" // Low-level I2C driver

#define TEMP_SENSOR_I2C_ADDRESS 0x48
#define TEMP_SENSOR_REG_TEMP 0x00

bool temp_sensor_init(void) {
    return i2c_init(); // Initialize I2C bus
}

bool temp_sensor_read_temperature(float *temperature) {
    uint8_t temp_data[2] = {0};

    // Read 2 bytes from the temperature register
    if (!i2c_read(TEMP_SENSOR_I2C_ADDRESS, TEMP_SENSOR_REG_TEMP, temp_data, 2)) {
        return false; // I2C read failed
    }

    // Convert raw data to temperature
    int16_t raw_temp = (temp_data[0] << 8) | temp_data[1];
    *temperature = raw_temp * 0.0078125; // Sensor-specific conversion

    return true;
}
