#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

struct cpu6502;


void instruction_add(struct cpu6502 *cpu, uint8_t reg_x);

void instruction_adc(struct cpu6502 *cpu, uint8_t reg_x);

void instruction_sub(struct cpu6502 *cpu, uint8_t reg_x);

void instruction_sbb(struct cpu6502 *cpu, uint8_t reg_x);

void instruction_ana(struct cpu6502 *cpu, uint8_t reg_x);

void instruction_xra(struct cpu6502 *cpu, uint8_t reg_x);

void instruction_ora(struct cpu6502 *cpu, uint8_t reg_x);

void instruction_cmp(struct cpu6502 *cpu, uint8_t reg_x);

#endif

