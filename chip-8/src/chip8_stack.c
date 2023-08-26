#include "chip8.h"
#include "chip8_stack.h"
#include <assert.h>

static void chip8_stack_in_bounds(struct chip8 *chip)
{
  assert(chip->registers.SP < sizeof(chip->stack.stack));
}

void chip8_stack_push(struct chip8 *chip, unsigned short value)
{
  chip->registers.SP += 1;
  chip8_stack_in_bounds(chip);
  chip->stack.stack[chip->registers.SP] = value;
}

unsigned short chip8_stack_pop(struct chip8 *chip)
{
  chip8_stack_in_bounds(chip);
  unsigned short result = chip->stack.stack[chip->registers.SP];
  chip->registers.SP  -= 1;
  return result;
}
