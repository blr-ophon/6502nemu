#ifndef FLAGS_H
#define FLAGS_H
#include <stdint.h>
#include <stdbool.h>

typedef struct flags{
    uint8_t cy:1; //carry
    uint8_t z:1; //zero 
    uint8_t i:1; //Interrupt disable (disable when set)
    uint8_t d:1; //decimal
    uint8_t v:1; //overflow
    uint8_t n:1; //negative
    //TODO: B flag
}Flags;

//TODO: decimal flag test
//
void test_normal_flags(Flags *flags, uint8_t result);

void test_carry_flag8(Flags *flags, uint16_t result);

void test_carry_flag16(Flags *flags, uint32_t result);

void test_flag_v(Flags *flags, uint8_t value, uint8_t operand, uint8_t carry);

uint8_t flags_load_byte(Flags *flags);

void flags_sta_byte(Flags *flags, uint8_t flags_reg);

#endif
