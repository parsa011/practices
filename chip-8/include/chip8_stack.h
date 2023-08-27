#ifndef _CHIP8_STACK
# define _CHIP8_STACK

#include "config.h"

struct chip8;

struct chip8_stack {
  unsigned short stack[CHIP8_TOTAL_STACK_DEPTH];
};

void chip8_stack_push(struct chip8 *chip, unsigned short value);
unsigned short chip8_stack_pop(struct chip8 *chip);

#endif
