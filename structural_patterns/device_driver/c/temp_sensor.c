#include "temp_sensor.h"
#include "i2c_driver.h" // Low-level I2C driver

// Register addresses for the temperature sensor
#define TEMP_SENSOR_REG_TEMP 0x00

// Initialize the temperature sensor
bool temp_sensor_init(void) {
    // Example: No specific initialization required for this sensor
    // Ensure the I2C bus is initialized
    return i2c_init();
}

// Read the temperature from the sensor
bool temp_sensor_read_temperature(float *temperature) {
    uint8_t temp_data[2] = {0};

    // Read 2 bytes from the temperature register
    if (!i2c_read(TEMP_SENSOR_I2C_ADDRESS, TEMP_SENSOR_REG_TEMP, temp_data, 2)) {
        return false; // I2C read failed
    }

    // Convert the raw data to temperature
    int16_t raw_temp = (temp_data[0] << 8) | temp_data[1];
    *temperature = raw_temp * 0.0078125; // Sensor-specific conversion

    return true;
}
