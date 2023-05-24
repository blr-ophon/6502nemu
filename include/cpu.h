#ifndef CPU_H
#define CPU_H 

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "./stack.h"
#include "./memory.h"
#include "./flags.h"
#include "./registerbank.h"
#include "./instructions.h"
#include "./config.h"

typedef struct cpu6502{
    uint8_t reg_A;
    uint8_t reg_X;
    uint8_t reg_Y;

    uint16_t PC;
    uint16_t SP;

    uint8_t data_bus;
    uint16_t address_bus;

    Memory *memory;
    Flags flags;

    //pins
    bool IRQ_pin:1;   //active low
    bool NMI_pin:1;   //active low
    bool RW_pin:1;    //read(1) or write(0)
                      
    //for timing/debugging purposes
    uint32_t step_count;
} Cpu6502;

uint16_t cpu_GetLIWord(Cpu6502 *cpu);

void cpu_init(Cpu6502 *cpu, Memory *memory);

void cpu_fetch_execute(Cpu6502 *cpu);

void cpu_exec_instruction(Cpu6502 *cpu, uint8_t *opcode);

#endif
