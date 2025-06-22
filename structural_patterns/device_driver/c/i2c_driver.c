#include "i2c_driver.h"
#include <stdio.h> // For simulation purposes

// Simulated I2C initialization
bool i2c_init(void) {
    printf("I2C Initialized.\n");
    return true; // Assume success
}

// Simulated I2C read
bool i2c_read(uint8_t device_addr, uint8_t reg_addr, uint8_t *data, uint8_t len) {
    printf("I2C Read: Device 0x%02X, Register 0x%02X, Length %d\n", device_addr, reg_addr, len);

    // Simulate reading temperature data
    if (device_addr == TEMP_SENSOR_I2C_ADDRESS && reg_addr == TEMP_SENSOR_REG_TEMP) {
        data[0] = 0x1A; // Example MSB
        data[1] = 0xC0; // Example LSB
        return true;
    }

    return false;
}

// Simulated I2C write
bool i2c_write(uint8_t device_addr, uint8_t reg_addr, const uint8_t *data, uint8_t len) {
    printf("I2C Write: Device 0x%02X, Register 0x%02X, Length %d\n", device_addr, reg_addr, len);
    return true; // Assume success
}
