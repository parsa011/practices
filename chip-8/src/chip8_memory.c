#include <assert.h>
#include "chip8_memory.h"

static void chip8_is_memory_in_bound(int index)
{
  assert(index >= 0 && index < CHIP8_MEMORY_SIZE);
}

void chip8_memory_set(struct chip8_memory *memory,int index, unsigned char value)
{
  chip8_is_memory_in_bound(index);
  memory->memory[index] = value;
}
unsigned char chip8_memory_get(struct chip8_memory *memory, int index)
{
  chip8_is_memory_in_bound(index);
  return memory->memory[index];
}
