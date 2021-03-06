#include "lexer.h"

#include <ctype.h>

#include "file.h"

int putback;

public char Text[31];
public int Text_len = 0;

private void put_back(int c)
{
	putback = c;
}

private int skip()
{
	int c;
	do {
		c = next();
	} while (isspace(c));
	return c;
}

private int next()
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

private int scan_int(int c)
{
	int n = 0;
	do {
		n = n * 10 + (c - '0');
		c = next();
	} while (isdigit(c));
	put_back(c);
	return n;
}

private void scan_ident(int c)
{
	do {
		Text[Text_len++] = c;
		c = read_char();
	} while (isalpha(c) || c == '_');
	put_back(c);
}

public void set_token_kind(int kind)
{
	lexer.token.kind = kind;
}

public int lex() {
	int c = skip();
	c_token.value = 0;
	if (!c) {
		return 0;
	}
	switch (c) {
		case EOF :
			set_token_kind(T_EOF);
			break;
		case ';' :
		    set_token_kind(T_SEMI);
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
			} else if (isalpha(c) || c == '_') {
				scan_ident(c);
				set_token_kind(T_PRINT);
				break;
			}
			die("Unreconized Character : %c\n", c);
	}
	return 1;
}

public void match(int kind, char *msg)
{
	if (c_token.kind != kind)
		die(msg);
}
