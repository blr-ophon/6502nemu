#ifndef MEMORY_H
#define MEMORY_H
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct memory{
    uint8_t *memory;
    size_t size;
}Memory;

Memory *memory_init(size_t size);

void memory_free(Memory *memory);

uint8_t memory_read8(Memory *memory, uint16_t address);

uint16_t memory_read16(Memory *memory, uint16_t address);

void memory_write8(Memory *memory, uint16_t address, uint8_t value);

void memory_write16(Memory *memory, uint16_t address, uint16_t value);

void memory_clear(Memory *memory);

void memory_program_load(Memory *memory, uint8_t *buf, size_t size, uint16_t adr);

void memory_dump(Memory *memory, long size);

#endif
