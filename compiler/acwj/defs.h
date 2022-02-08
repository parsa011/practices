#ifndef _DEFS_H
# define _DEFS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct token {
    int token;
    int intvalue;
};

enum {
    T_PLUS,
    T_MINUS, 
    T_STAR, 
    T_SLASH, 
    T_INTLIT
};

#endif
