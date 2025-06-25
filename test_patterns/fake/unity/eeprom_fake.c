#include "eeprom.h"

#define EEPROM_SIZE 128
static int eeprom_memory[EEPROM_SIZE];  // fake EEPROM

void eeprom_write(int address, int value) {
    if (address >= 0 && address < EEPROM_SIZE) {
        eeprom_memory[address] = value;
    }
}

int eeprom_read(int address) {
    if (address >= 0 && address < EEPROM_SIZE) {
        return eeprom_memory[address];
    }
    return -1; // indicate error
}
