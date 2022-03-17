#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdarg.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// global
void panic(char *, ...);

// file
void open_file(char *);
char read_char();
void close_file();
bool file_exist(char *);

// lexer
// we have to pass lexer to each function , but this is simple program and we dont need 
char next_char();
void skip();
char skip_next();
void put_back(char);
void lex();

//parser


// declerations

enum TokenType{
	T_PLUS,
	T_MINUS,
	T_SLASH,
	T_STAR,
	T_POW,
	T_OP,
	T_CP,
	T_INT,
	T_IDENT,
	T_SEMI,
	T_BAD,
	T_EOI
};

struct Token {
	int type;
	union {
		int value;
		int var_id;		/* variable id (index) in variables table */
	};
};

struct Lexer {
	FILE *fp;
	int lineno;
	struct Token token;
	int ch;
	int putback;
};

//var
struct Variable *create_var(char *, int);
struct Variable *find_var(int);

#define VARIABLE_MAX_LENGTH 32
// now we just have int variables :)))))))))
struct Variable {
	int value;
	char name[VARIABLE_MAX_LENGTH];
};

#define VARIABLES_BUF_SIZE 10
struct Variable **variables;
int variables_buf_count = 0;
int variables_count = 0;

void init_variables_table();
void increase_variables_table();

void init_variables_table()
{
	variables = calloc(VARIABLE_MAX_LENGTH, sizeof(struct Variable));
}

void increase_variables_table()
{
	variables_buf_count += VARIABLE_MAX_LENGTH;
	variables = realloc(variables, variables_buf_count * sizeof(struct Variable));
}

/* our globla lexer */
struct Lexer lexer;

bool interp_mode = false;

#define c_token (lexer.token)
#define set_c_token_type(t) (c_token.type = t)

// file

bool file_exist(char *f)
{
	return access(f, F_OK) == 0;
}

char read_char()
{
	return fgetc(lexer.fp);
}

void open_file(char *f)
{
	if (!file_exist(f)) {
		panic("File %s, Dosnt Exist", f);
	}
	lexer.fp = fopen(f, "r");
}

void set_program_mode(int argc, char *argv[])
{
	if (argc == 1) {
		interp_mode = true;
		lexer.fp = stdin;
	} else {
		open_file(argv[1]);
	} 
}

// lexer
char next_char()
{
	int c;
	if (lexer.putback) {
		c = lexer.putback;
		lexer.putback = 0;
		return c;
	}
	c = read_char();
	if (c == '\n')
		lexer.lineno++;
	return c;
}

void put_back(char c)
{
	lexer.putback = c;
}

/* skip whitespaces and stop in first of non-space char */
void skip()
{
	int c;
	do {
		c = next_char();
	} while (isspace(c));
	put_back(c);
}

char skip_next()
{
	skip();
	return next_char();
}

int main(int argc, char **argv)
{
	init_variables_table();
	set_program_mode(argc, argv);
	char c;
	do { 
		c = skip_next();
		printf("%c\n", c);
	} while (c != EOF);
	return 0;
}

void panic(char *msg, ...)
{
	char buf[256];
	va_list ap;
	va_start(ap, msg);
	vsprintf(buf, msg, ap);
	va_end(ap);
	fprintf(stderr, "%s\n", buf);
	exit(1);
}
