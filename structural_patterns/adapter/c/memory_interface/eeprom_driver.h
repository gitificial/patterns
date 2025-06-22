#ifndef EEPROM_DRIVER_H
#define EEPROM_DRIVER_H

#include <stdint.h>
#include <stdbool.h>

bool eeprom_write(uint16_t addr, uint8_t *data, uint16_t len);    // Writes data to EEPROM
bool eeprom_read(uint16_t addr, uint8_t *data, uint16_t len);     // Reads data from EEPROM

#endif
