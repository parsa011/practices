#include "lexer.h"

#include <ctype.h>

#include "file.h"

static int putback;

static void put_back(int c)
{
	putback = c;
}

static int skip()
{
	int c;
	do {
		c = next();
	} while (isspace(c));
	return c;
}

static int next()
{
	int c;
	if (putback) {
		c = putback;
		putback = 0;
		return c;
	} else
		c = read_char();
	if (c == '\n')
		lexer.lineno++;
	return c;
}

static int scan_int(int c)
{
	int n = 0;
	do {
		n = n * 10 + (c - '0');
		c = next();
	} while (isdigit(c));
	put_back(c);
	return n;
}

void set_token_kind(int kind)
{
	lexer.token.kind = kind;
}

int lex()
{
	int c = skip();
	c_token.value = 0;
	if (!c) {
		return 0;
	}
	switch (c) {
		case EOF :
			set_token_kind(T_EOF);
			break;
		case '+' :
			set_token_kind(T_PLUS);
			break;
		case '-' :
			set_token_kind(T_DASH);
			break;
		case '/' :
			set_token_kind(T_SLASH);
			break;
		case '*' :
			set_token_kind(T_STAR);
			break;
		default :
			if (isdigit(c)) {
				set_token_kind(T_INTLIT);
				c_token.value = scan_int(c);
				break;
			}
			die("unreconized character : %c\n", c);
	}
	return 1;
}
