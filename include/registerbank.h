#ifndef REGISTERBANK_H
#define REGISTERBANK_H
#include <stdint.h>

typedef struct cpu6502 Cpu6502;


void write_reg_BC(Cpu6502 *cpu, uint16_t value);

uint16_t read_reg_BC(Cpu6502 *cpu);

void write_reg_DE(Cpu6502 *cpu, uint16_t value);

uint16_t read_reg_DE(Cpu6502 *cpu);

void write_reg_HL(Cpu6502 *cpu, uint16_t value);

uint16_t read_reg_HL(Cpu6502 *cpu);

#endif
