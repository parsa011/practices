#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int lineno = 1;
int tokentype = -1;
int value = 0; 
int offset = 0;
char ch = 0;
int res = 0;

char text[16];
char text_len;

enum {
	T_ADD,
	T_SUB,
	T_MULTI,
	T_DIVIDE,
	T_SEMI,
	T_OP,
	T_CP,
	T_INTLIT,
	T_ERROR,
	T_SIN,
	T_COS,
	T_BAD,
	T_EOI
};

FILE *fp;
int putback = 0;

void show_error_location();

void open_file(char *name)
{
	fp = fopen(name, "r");
	if (!fp) {
		fprintf(stderr, "File Not Found : %s\n", name);
		exit(-1);
	}
}

char read_char()
{
	int c;
	if (putback) {
		c = putback;
		putback = 0;
		return c;
	}
	c = fgetc(fp);
	offset++;
	if (c == '\n')
		lineno++;
	return c;
}

void put_back(char c)
{
	putback = c;
}

void skip()
{
	int c;
	do {
		c = read_char();
	} while (isspace(c));
	put_back(c);
}

char skip_read()
{
	skip();
	return (ch = read_char());
}

void scan_int(int c)
{
	int res = 0;
	do {
		res = res * 10 + (c - '0');
		c = read_char();
	} while (isdigit(c));
	put_back(c);
	value = res;
}

void scan_func(int c)
{
	text_len = 0;
	text[text_len++] = c;
	c = read_char();
	while (isalpha(c)) {
		text[text_len++] = c;
		c = read_char();
	}
	text[text_len] = 0;
	put_back(c);
}

int guess_func_type()
{
	if (strcmp(text, "sin") == 0) {
		return T_SIN;
	} else if (strcmp(text, "cos") == 0) {
		return T_COS;
	}
	return T_BAD;
}

int is_func()
{
	if (strcmp(text, "sin") == 0 || strcmp(text, "cos") == 0)
		return 1;
	return 0;
}

int lex()
{
	int c = skip_read();
	switch (c) {
		case EOF :
			tokentype = T_EOI;
			return 0;
		case '+' :
			tokentype = T_ADD;
			break;
		case '*' :
			tokentype = T_MULTI;
			break;
		case '(' :
			tokentype = T_OP;
			break;
		case ')' :
			tokentype = T_CP;
			break;
		case ';' :
			tokentype = T_SEMI;
			break;
		default :
			if (isdigit(c)) {
				tokentype = T_INTLIT;
				scan_int(c);
				break;
			} else if (isalpha(c)) {
				scan_func(c);
				tokentype = guess_func_type(text);
				break;
			}
			fprintf(stderr, "Bad Token %c\n", c);
			exit(0);
	}
	return 1;
}

// parser
void expression();
void addictive();

void match(int type, char *msg)
{
	if (tokentype != type) {
		fprintf(stderr, "%s\n", msg);
		exit(0);
	}
}

void unclosed_parenthesis_error()
{
	fprintf(stderr, "Unclosed Parenthesis\n");
	show_error_location();
	exit(0);
}

int eof()
{
	return tokentype == T_EOI;
}

void show_error_location()
{
	size_t len;
	char *buf = NULL;
	for (int i = 0; i < offset; i++)
		fp->_IO_read_ptr--;
	getline(&buf, &len, fp);
	puts(buf);
	for (int i = 0; i < offset - 1; i++)
		putchar(' ');
	putchar('|');
	putchar('\n');
	exit(0);
}

void factor()
{
	if (tokentype == T_INTLIT)
		lex();
	else if (tokentype == T_OP) {
		lex();
		addictive();
		if (tokentype == T_CP) {
			lex();
		} else {
			unclosed_parenthesis_error();
		}
	} else {
		fprintf(stderr, "Int Literal Expected , But Was <'%c'>\n", ch);
		show_error_location();
	}
}

void multi_prime()
{
	if (tokentype == T_MULTI) {
		// eat * token
		lex();
		res *= value;
		factor();
		multi_prime();
	}
}

void multi()
{
	factor();
	multi_prime();
}

void addictive_prime()
{
	if (tokentype == T_ADD) {
		// eat + token
		lex();
		res += value;
		multi();
		addictive_prime();
	}
}

void addictive()
{
	multi();
	addictive_prime();
}


void expression()
{
	addictive();
}

void state()
{
	expression();
	if (tokentype != T_SEMI) {
		printf("Missed Semi :)\n");
		show_error_location();
	}
}

int main(int argc, char *argv[])
{
	open_file(argv[1]);
	lex();
	res = value;
	state();
	printf("result is : %d\n", res);
	//do {
	//	lex();
	//	printf("%d\n", tokentype);
	//} while (tokentype != T_EOI);
	fclose(fp);
	return 0;
}
