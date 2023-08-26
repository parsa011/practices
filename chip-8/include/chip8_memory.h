#ifndef _CHIP8_MEMORY_H
# define _CHIP8_MEMORY_H

#include "config.h"

struct chip8_memory {
  unsigned char memory[CHIP8_MEMORY_SIZE];
};

void chip8_memory_set(struct chip8_memory *memory,int index, unsigned char value);
unsigned char chip8_memory_get(struct chip8_memory *memory, int index);

#endif
