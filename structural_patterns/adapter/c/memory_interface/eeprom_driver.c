#include "eeprom_driver.h"
#include "stm32f7xx_hal.h"

extern I2C_HandleTypeDef hi2c1;  // I2C peripheral handle

bool eeprom_write(uint16_t addr, uint8_t *data, uint16_t len) {
    uint8_t buffer[len + 2];
    buffer[0] = (addr >> 8) & 0xFF;   // Upper byte of the address
    buffer[1] = addr & 0xFF;          // Lower byte of the address
    memcpy(&buffer[2], data, len);    // Copy data to buffer

    return HAL_I2C_Master_Transmit(&hi2c1, EEPROM_I2C_ADDRESS, buffer, len + 2, HAL_MAX_DELAY) == HAL_OK;
}

bool eeprom_read(uint16_t addr, uint8_t *data, uint16_t len) {
    uint8_t addr_buf[2] = {(addr >> 8) & 0xFF, addr & 0xFF};

    if (HAL_I2C_Master_Transmit(&hi2c1, EEPROM_I2C_ADDRESS, addr_buf, 2, HAL_MAX_DELAY) != HAL_OK) {
        return false;
    }

    return HAL_I2C_Master_Receive(&hi2c1, EEPROM_I2C_ADDRESS, data, len, HAL_MAX_DELAY) == HAL_OK;
}
