#ifndef _CHIP8_H
# define  _CHIP8_H

#include "config.h"
#include "chip8_registers.h"
#include "chip8_memory.h"
#include "chip8_stack.h"
#include "chip8_keyboard.h"
#include "chip8_screen.h"

struct chip8 {
  struct chip8_memory memory;
  struct chip8_registers registers;
  struct chip8_stack stack;
  struct chip8_keyboard keyboard;
  struct chip8_screen screen;
};

void chip8_init(struct chip8 *ochip8);

#endif
