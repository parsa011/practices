#ifndef _TINT_H
# define _TINT_H

#include <stdio.h>
#include <stdlib.h>

#define public
#define private extern

#include "lexer.h"

/* global function and variables */
void die(char *,...);

extern struct lexer_t lexer;

#endif
