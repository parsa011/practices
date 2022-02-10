#ifndef _DATA_H
# define _DATA_H

#ifndef extern_
 #define extern_ extern
#endif

#include "token.h"

extern_ int Line;
extern_ int Putback;
extern_ FILE *file;
extern_ struct token Token;

#endif
