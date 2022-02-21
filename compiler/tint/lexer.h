#ifndef _LEXER_H
# define _LEXER_H

#include "tint.h"
#include "token.h"

struct lexer_t {
	FILE *fp;
	char *filename;
	short offset;
	int lineno;
	struct token_t tok;
};

/* get current token */
#define c_token (lexer.tok)

static int putback;

static void put_back(int); 

/* scan int */
static int scan_int(int);

/* scan identifier */
static int scan_ident(int, char *, int);

/* skipe whitespaces */
static void skip();

/* get next char from lexer file */
static int next();

int lex(struct token_t *tok);

#endif
