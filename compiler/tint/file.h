#ifndef _FILE_H
# define _FILE_H

#include "tint.h"

/*
 *	open file into lexer , name should be full name , with path
 */
void open_file(char *);

/*
 *	close current lexer file 
 */
void close_file();

/*
 *	read one char from lexer file
 */
char read_char();

#endif
