#include "lexer.h"

#include <ctype.h>

#include "file.h"

static int putback;

static void put_back(int c)
{
	putback = c;
}

static void skip()
{
	int c = next();
	while (isspace(c))
		c = next();
	put_back(c);
}

static int next()
{
	int c;
	if (putback) {
		c = putback;
		putback = 0;
	} else
		c = read_char();
	if (c == '\n')
		lexer.lineno++;
	return c;
}
