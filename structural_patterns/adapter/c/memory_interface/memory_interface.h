#ifndef MEMORY_INTERFACE_H
#define MEMORY_INTERFACE_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    bool (*write)(uint16_t addr, uint8_t *data, uint16_t len);   // Function pointer for writing data
    bool (*read)(uint16_t addr, uint8_t *data, uint16_t len);    // Function pointer for reading data
} MemoryInterface;

#endif
