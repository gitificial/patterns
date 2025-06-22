#ifndef I2C_DRIVER_H
#define I2C_DRIVER_H

#include <stdint.h>
#include <stdbool.h>

// Low-level I2C driver API
bool i2c_init(void); // Initialize the I2C peripheral
bool i2c_read(uint8_t device_addr, uint8_t reg_addr, uint8_t *data, uint8_t len);
bool i2c_write(uint8_t device_addr, uint8_t reg_addr, const uint8_t *data, uint8_t len);

#endif // I2C_DRIVER_H
