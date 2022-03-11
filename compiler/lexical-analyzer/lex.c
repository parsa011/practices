#include "lex.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>

FILE *fp;

struct Token token;

char lookahead = 0;

int putback;
int lineno = 0;

int read_char()
{
	if (putback) {
		lookahead = putback;
		putback = 0;
		return lookahead;
	}
	lookahead = fgetc(fp);
	if (lookahead == '\n')
		lineno++;
	return lookahead;
}

void put_back(int c)
{
	putback = c;
}

int skip()
{
	int c;
	while (isspace((c = read_char())))
		;
	return c;
}

int scan_int(int c)
{
	int res = c;
	while (isdigit(c = skip())) {
		res = res * 10 + (c - '0');
	}
	put_back(c);
	return res;
}

int lex()
{
	int c = skip();
	bool incomment = false;
	switch (c) {
		case EOF :
			token.type = T_EOF;
			break;
		case ';' :
			token.type = T_SEMI;
			break;
		case '+' :
			token.type = T_PLUS;
			break;
		case '-' :
			token.type = T_DASH;
			break;
		case '/' :
			c = read_char();
			if (c == '/') {
				while ((c = read_char()) != '\n')
					;
				token.type = T_ONELINE_COMMENT;
				break;
			} else if (c == '*') {
				incomment = true;
				do {
					c = read_char();
					switch (c) {
						case EOF :
							printf("Syntax Error One Line : %d, EOF in Comment Block\n", lineno);
							exit(0);
						case '*' :
							c = read_char();
							if (c == '/')
								incomment = false;
					}
				} while (incomment);
				token.type = T_MULTYLINE_COMMENT;
				break;

			} else {
				put_back(c);
			}
			token.type = T_SLASH;
			break;
		case '*' :
			token.type = T_STAR;
			break;
		case '(' :
			token.type = T_OPEN_PARENTHESIS;
			break;
		case ')' :
			token.type = T_CLOSE_PARENTHESIS;
			break;
		case '{' :
			token.type = T_OPEN_CURLYB;
			break;
		case '}' :
			token.type = T_CLOSE_CURLYB;
			break;
		default :
			if (isdigit(c)) {
				token.type = T_INTLIT;
				token.value = scan_int(c);
				break;
			}
			printf("unreconized character : %c\n", c);
			exit(0);

	}
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Enter file name\n");
        exit(-1);
    }
    if ((fp = fopen(argv[1], "r")) == NULL) {
        printf("File Not Found : %s\n", argv[1]);
        exit(-1);
    }
    do {
        lex();
		printf("%d %s\n", lookahead, Token_name[token.type]);
    } while (token.type != T_EOF);
	printf("INT MAX : %ld\n", LONG_MAX);
    return 0;
}
