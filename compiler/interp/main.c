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
#define CHR_T_INT(c) (c - '0')
void print_c_token();
void print_token_string(int);

// fp
void open_fp(char *);
char read_char();
void close_fp();
bool fp_exist(char *);

// lexer
// we have to pass lexer to each function , but this is simple program and we dont need 
char next_char();
void skip();
char skip_next();
void put_back(char);
void save_token();
void scan_ident(int);
int scan_const(int);
void scan_string();
int guess_string_type(char *);
bool lex();
void match(int, char *);
bool is_type_keyword(int);
bool is_type_keyword_string(char *);
int type_to_value_type(int);

// tree
struct ASTnode *mkastnode(int, struct ASTnode *, struct ASTnode *, int);
struct ASTnode *mkastleaf(int, int);
struct ASTnode *mkastunary(int, struct ASTnode *, int);

//parser
void semi();
void statements();
void print_statement();
void variable_decleration_statement();
void assigin_statement();
void print_ast(struct ASTnode *, int);
struct ASTnode *binary_expression(int);
int calculate_binary_tree(struct ASTnode *);

// declerations

enum TokenType {
	T_PLUS,
	T_DASH,
	T_SLASH,
	T_STAR,
	T_POW,

	T_OP,
	T_CP,

	T_INT,
	T_PRINT,
	T_STRING,
	T_IDENT,
	T_CONST,
	T_CHAR_ARRAY,
	T_SEMI,
	T_EQUAL,
	T_COMMA,

	T_BAD,
	T_EOI
};

char *Tokens_str[] = {
	"T_PLUS",
	"T_DASH",
	"T_SLASH",
	"T_STAR",
	"T_POW",

	"T_OP",
	"T_CP",

	"T_INT",
	"T_PRINT",
	"T_STRING",
	"T_IDENT",
	"T_CONST",
	"T_CHAR_ARRAY",
	"T_SEMI",
	"T_EQUAL",
	"T_COMMA",

	"T_BAD",
	"T_EOI"
};

char *Types_string_arr[] = {
	"string",
	"int",
	"char",
	"float",
	"bool",
	"double"
};

int Types_arr[] = {
	T_INT,
	T_STRING
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
	struct Token *save_token;
};

struct ASTnode {
	int op;
	struct ASTnode *left;
	struct ASTnode *right;
	int value;
};

enum ArithOp {
	A_ADD,
	A_SUB,
	A_MULTIPLY,
	A_DIVIDE,
	A_POW,
	A_CONST,
	A_IDENT
};

char *ArithOp_str[] = {
	"A_ADD",
	"A_SUB",
	"A_MULTIPLY",
	"A_DIVIDE",
	"A_POW",
	"A_CONST",
	"A_IDENT"
};

char Text[32];
int Text_len;

//var

#define VARIABLE_MAX_LENGTH 32
// now we just have int variables :)))))))))
struct Variable {
	void *value;
	char name[VARIABLE_MAX_LENGTH];
	int type;
	int index;
};

#define VARIABLES_BUF_SIZE 10
struct Variable **variables;
int variables_buf_count = 0;
int variables_count = 0;

void init_variables_table();
void increase_variables_table();
void check_variable_table();
struct Variable *create_var(char *, void *, int);
struct Variable *find_var(char *);

/* our globla lexer */
struct Lexer lexer;

bool interp_mode = false;

#define c_token (lexer.token)
#define set_c_token_type(t) (c_token.type = t)

// fp

bool fp_exist(char *f)
{
	return access(f, F_OK) == 0;
}

char read_char()
{
	return fgetc(lexer.fp);
}

void open_fp(char *f)
{
	if (!fp_exist(f)) {
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
		open_fp(argv[1]);
	} 
}

// var

void init_variables_table()
{
	variables = calloc(VARIABLE_MAX_LENGTH, sizeof(struct Variable));
}

void increase_variables_table()
{
	variables_buf_count += VARIABLE_MAX_LENGTH;
	variables = realloc(variables, variables_buf_count * sizeof(struct Variable));
}

void check_variable_table()
{
	if (variables_count == variables_buf_count - 1)
		increase_variables_table();
}

struct Variable *create_var(char *name, void *value, int type)
{
	check_variable_table();
	struct Variable *v = malloc(sizeof(struct Variable));
	int name_len = strlen(name);
	if (name_len > VARIABLE_MAX_LENGTH) {
		panic("Variable Name <'%s'> Should be Less than %d character", name, VARIABLE_MAX_LENGTH, name);
	}
	strcpy(v->name, name);
	v->value = value;
	v->type = type;
	v->index = variables_count;
	variables[variables_count++] = v;
	return v;
}

// lexer

int type_to_value_type(int token)
{
	switch (token) {
		case T_INT :
			return T_CONST;
		case T_STRING :
			return T_CHAR_ARRAY;
	}
  return -1;
}

bool is_unary(struct Token token)
{
	if (token.type == T_CONST)
		return true;
	if (token.type == T_IDENT) {
		struct Variable *v = find_var(Text);
		print_token_string(v->type);
		if (v->type == T_CONST)
			return true;
	}
	return false;
}

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

void save_token()
{
	lexer.save_token = &c_token;
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

int scan_const(int c)
{
	int res = CHR_T_INT(c);
	while (isdigit((c = next_char()))) {
		res = res * 10 + CHR_T_INT(c);
	}
	put_back(c);
	return res;
}

void scan_ident(int c)
{
	Text_len = 0;
	Text[Text_len++] = c;
	while (isalnum((c = next_char())) || c == '_') {
		Text[Text_len++] = c;
	}
	Text[Text_len] = 0;
	put_back(c);
}

void scan_string()
{
	Text_len = 0;
	int c = read_char();
	while (1) {
		Text[Text_len++] = c;
		c = read_char();
		if (c == '"' || c == EOF)
			break;
	}
	Text[Text_len] = 0;
	if (c != '"')
		panic("Unclosed String");
}

int guess_string_type(char *s)
{
	if (strcmp("int", s) == 0)
		return T_INT;
	else if (strcmp("print", s) == 0)
		return T_PRINT;
	else if (strcmp("string", s) == 0)
		return T_STRING;
	return T_IDENT;
}

bool lex()
{
	if (lexer.save_token != 0) {
		c_token = *lexer.save_token;
		lexer.save_token = 0;
		return true;
	}
	int c = skip_next();
	switch (c) {
		case EOF :
			set_c_token_type(T_EOI);
			return false;
		case '+' :
			set_c_token_type(T_PLUS);
			break;
		case '-' :
			set_c_token_type(T_DASH);
			break;
		case '/' :
			c = next_char();
			if (c == '/') {
				do {
					c = next_char();
				} while (c != '\n');
				lex();
				break;
			}
			put_back(c);
			set_c_token_type(T_SLASH);
			break;
		case '*' :
			set_c_token_type(T_STAR);
			break;
		case '^' :
			set_c_token_type(T_POW);
			break;
		case '(' :
			set_c_token_type(T_OP);
			break;
		case ')' :
			set_c_token_type(T_CP);
			break;
		case ';' :
			set_c_token_type(T_SEMI);
			break;
		case '=' :
			set_c_token_type(T_EQUAL);
			break;
		case '"' :
			set_c_token_type(T_CHAR_ARRAY);
			scan_string();
			break;
		case ',' :
			set_c_token_type(T_COMMA);
			break;
		default : 
			if (isdigit(c)) {
				set_c_token_type(T_CONST);
				c_token.value = scan_const(c);
				break;
			} else if (isalpha(c) || c == '_') {
				scan_ident(c);
				set_c_token_type(guess_string_type(Text));
				break;
			}
			printf("Bad Token <'%c'> \n", c);
	}
  return true;
}

bool is_type_keyword(int n)
{
	int *p = Types_arr;
	while (*p) {
		if (n == *p)
			return true;
		p++;
	}
	return false;
}

bool is_type_keyword_string(char *s)
{
	char *p = Types_string_arr[0];
	while (*p) {
		if (strcmp(p, s) == 0)
			return true;
		p++;
	}
	return false;
}

// AST
struct ASTnode *mkastnode(int op, struct ASTnode *left, struct ASTnode *right, int value)
{
	struct ASTnode *n = malloc(sizeof(struct ASTnode));
	if (!n) {
		panic("Can't Allocate Memroy, in mkastnode()");
	}

	n->op = op;
	n->left = left;
	n->right = right;
	n->value = value;

	return n;
}

struct ASTnode *mkastleaf(int op, int value)
{
	return mkastnode(op, NULL, NULL, value);
}

struct ASTnode *mkastunary(int op, struct ASTnode *left, int value)
{
	return mkastnode(op, left, NULL, value);
}

// variables
struct Variable *find_var(char *name)
{
	for (int i = 0; i < variables_count; i++) {
		if (strcmp(name, variables[i]->name) == 0)
			return variables[i];
	}
	return NULL;
}

// parser
void match(int type, char *msg)
{
	if (c_token.type != type)
		panic("Error In Line %d : %s", lexer.lineno, msg);
	lex();
}

void semi()
{
	match(T_SEMI, "Mised Semicolon");
}

void statements()
{
	while (c_token.type != T_EOI) {
		switch (c_token.type) {
			case T_INT :
			case T_STRING :
				variable_decleration_statement();
				break;
			case T_IDENT :
				assigin_statement();
				break;
			case T_PRINT :
				print_statement();
				break;
			default :
				panic("Error On line %d : Bad Token\n", lexer.lineno);
		}
	}
}

void eat_open_parenthesis()
{
	match(T_OP, "Missed Open Parenthesis");
}

void eat_close_parenthesis()
{
	match(T_CP, "Missed Close Parenthesis");
}

void print_statement()
{
	match(T_PRINT, "Print Expected");
	eat_open_parenthesis();
	printf("%s\n", Tokens_str[c_token.type]);
	if (is_unary(lexer.token)) {
		struct ASTnode *n = binary_expression(0);
		if (!n)
			return;
		print_ast(n, 0);
		int result = calculate_binary_tree(n);
		printf("%d\n", result);
	} else {
		lex();
	}
	eat_close_parenthesis();
	semi();
}

void assigin_statement()
{
	char *name = Text;
	match(T_IDENT, "Token Must Be Idenifier");
	struct Variable *v = find_var(name);
	if (v == NULL) {
		panic("Variable <'%s'> Not Found", name);
	}
	match(T_EQUAL, "We Need '=' in assignment");
	struct ASTnode *n = binary_expression(0);
	int res = calculate_binary_tree(n);
	v->value = &res;
	semi();
}

void variable_decleration_statement()
{
	if (!is_type_keyword(c_token.type)) {
		panic("Invalied Type : <'%s'>", Text);
	}
	lex();
decl:
	match(T_IDENT, "Not Valid Variable Name");
	if (c_token.type == T_EQUAL) {
		lex();
		switch (c_token.type) {
			case T_CONST :
				{
					struct ASTnode *n = binary_expression(0);
					int res = calculate_binary_tree(n);
					create_var(Text, &res, type_to_value_type(c_token.type));
					break;
				}
			case T_CHAR_ARRAY :
				create_var(Text, Text, type_to_value_type(c_token.type));
				lex();
				break;
		}
	}
	if (c_token.type == T_COMMA) {
		lex();
		goto decl;
	}
	semi();
}

int arithop(int type)
{
	switch (type) {
		case T_PLUS :
			return A_ADD;
		case T_DASH :
			return A_SUB;
		case T_SLASH :
			return A_DIVIDE;
		case T_STAR :
			return A_MULTIPLY;
		case T_POW :
			return A_POW;
		case T_CONST :
			return A_CONST;
	}
	panic("Invalid Arithmetic Operation %s", Tokens_str[type]);
  return -1;
}

const int OpPrec[] = {
	10, 10, 20, 20, 20,

	0, 0,

	0, 0, 10, 10, 0,

	0, 0
};

struct ASTnode *primary()
{
	struct ASTnode *n = NULL;
	struct Variable *v;
	switch (c_token.type) {
		case T_CONST :
			n = mkastleaf(A_CONST, c_token.value);
			lex();
			return n;
		case T_IDENT :
			v = find_var(Text);
			if (v == NULL)
				panic("Variable '%s' not found", Text);
			n = mkastleaf(A_IDENT, v->index);
			lex();
			return n;
		case T_OP :
			lex();
			n = binary_expression(0);
			match(T_CP, "Unclosed Parenthesis");
			return n;
	}
	return n;
}

int op_precedence(int tokentype) 
{
	int prec = OpPrec[tokentype];
	if (prec == 0)
		panic("Syntax error, token %d", tokentype);
	return (prec);
}

struct ASTnode *binary_expression(int ptp)
{
	struct ASTnode *left, *right;
	int tokentype;

	left = primary();

	tokentype = c_token.type;
	if (tokentype == T_SEMI || tokentype == T_CP || tokentype == T_COMMA) {
		return left;
	}

	while (op_precedence(tokentype) > ptp) {
		lex();
		right = binary_expression(OpPrec[tokentype]);
		left = mkastnode(arithop(tokentype), left, right, 0);
		tokentype = c_token.type;
		if (tokentype == T_SEMI || tokentype == T_CP || tokentype == T_COMMA) {
			break;	
		}
	}
	return left;
}

int calculate_binary_tree(struct ASTnode *n)
{
	int left, right;
	if (n->left)
		left = calculate_binary_tree(n->left);
	if (n->right)
		right = calculate_binary_tree(n->right);
	switch (n->op) {
		case A_ADD :
			return left + right;
		case A_SUB :
			return left - right;
		case A_MULTIPLY :
			return left * right;
		case A_DIVIDE :
			return left / right;
		case A_CONST :
			return n->value;
		case A_IDENT :
			{
				struct Variable *v = variables[n->value];
				if (v->type != T_CONST)
					panic("Invalid Var in unary Tree : %s", v->name);
				return *((int *)v->value);
			}
	}
  return -1;
}

void print_ast(struct ASTnode *n, int depth)
{
	for (int i = 1; i <= depth; i++) {
		putchar(' ');
	}
	printf("%s", ArithOp_str[n->op]);
	if (n->op == A_CONST) {
		printf(" : %d", n->value);
	} else if (n->op == A_IDENT) {
		struct Variable *v = variables[n->value];
		if (v->type == T_CHAR_ARRAY) {
			printf(" : %s", ((char *)v->value));
		} else if (v->type == T_CONST) {
			printf(" : %d", *((int *)v->value));
		}
	}
	putchar('\n');
	if (n->left) {
		print_ast(n->left, depth + 4);
	}
	if (n->right) {
		print_ast(n->right, depth + 4);
	}
}

// main

int main(int argc, char **argv)
{
	lexer.lineno = 1;
	init_variables_table();
	set_program_mode(argc, argv);
	while (c_token.type != T_EOI) {
		print_c_token();
		lex();
	}
	statements();
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

void print_c_token()
{
	printf("%s", Tokens_str[c_token.type]);
	if (c_token.type == T_CONST) {
		printf(" : %d", c_token.value);
	} else if (c_token.type == T_IDENT || c_token.type == T_CHAR_ARRAY) {
		printf(" : %s", Text);
	}
	putchar('\n');
}

void print_token_string(int n)
{
	printf("%s\n", Tokens_str[n]);
}
