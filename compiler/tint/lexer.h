#ifndef _LEXER_H
# define _LEXER_H

#include "tint.h"
#include "token.h"

struct lexer_t {
	FILE *fp;
	char *filename;
	short offset;
	int lineno;
	struct token_t token;
};

/* get current token */
#define c_token (lexer.token)

private int putback;

private void put_back(int); 

/* scan int */
private int scan_int(int);

/* scan identifier */
private void scan_ident(int);

/* skipe whitespaces */
private int skip();

/* get next char from lexer file */
private int next();

public int lex();

public void set_token_kind(int);

public void match(int, char *);

#endif
