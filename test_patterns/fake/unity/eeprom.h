#ifndef EEPROM_H
#define EEPROM_H

void eeprom_write(int address, int value);
int  eeprom_read(int address);

#endif
