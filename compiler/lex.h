#ifndef _LEX_H
# define _LEX_H

#define EOI			0
#define SEMI		1
#define	PLUS		2
#define	TIMES		3
#define	LP			4
#define RP			5
#define	NUM_OR_ID	6

extern const char *token_names[];

extern char *text;
extern int length;
extern int lineno;

int lex();
void advance();
int match(int);

#endif
