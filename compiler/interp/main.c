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
int guess_string_type(char *);
bool lex();

// tree
struct ASTnode *mkastnode(int, struct ASTnode *, struct ASTnode *, int);
struct ASTnode *mkastleaf(int, int);
struct ASTnode *mkastunary(int, struct ASTnode *, int);

//parser
void match(int, char *);
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
	T_IDENT,
	T_CONST,
	T_SEMI,
	T_EQUAL,

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
	"T_IDENT",
	"T_CONST",
	"T_SEMI",
	"T_EQUAL",

	"T_BAD",
	"T_EOI"
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
	int value;
	char name[VARIABLE_MAX_LENGTH];
};

#define VARIABLES_BUF_SIZE 10
struct Variable **variables;
int variables_buf_count = 0;
int variables_count = 0;

void init_variables_table();
void increase_variables_table();
void check_variable_table();
struct Variable *create_var(char *, int);
int find_var(char *);

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

struct Variable *create_var(char *name, int value)
{
	check_variable_table();
	struct Variable *v = malloc(sizeof(struct Variable));
	int name_len = strlen(name);
	if (name_len > VARIABLE_MAX_LENGTH) {
		panic("Variable Name <'%s'> Should be Less than %d character", name, VARIABLE_MAX_LENGTH, name);
	}
	strcpy(v->name, name);
	v->value;
	variables[variables_count++] = v;
	return v;
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

int guess_string_type(char *s)
{
	if (strcmp("int", s) == 0)
		return T_INT;
	else if (strcmp("print", s) == 0)
		return T_PRINT;
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
int find_var(char *name)
{
	for (int i = 0; i < variables_count; i++) {
		if (strcmp(name, variables[i]->name) == 0)
			return i;
	}
	return -1;
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
	struct ASTnode *n = binary_expression(0);
	eat_close_parenthesis();
	semi();
	int result = calculate_binary_tree(n);
	printf("%d\n", result);
}

void assigin_statement()
{
	char *name = Text;
	match(T_IDENT, "Token Must Be Idenifier");
	int index = find_var(name);
	if (index == -1) {
		panic("Variable <'%s'> Not Found", name);
	}
	match(T_EQUAL, "We Need '=' in assignment");
	struct ASTnode *n = binary_expression(0);
	variables[index]->value = calculate_binary_tree(n);
	semi();
}

void variable_decleration_statement()
{
	match(T_INT, "Int Keywork Expected");
	char *name = Text;
	match(T_IDENT, "Not Valid Variable Name");
	struct Variable *v = create_var(name,0);
	if (c_token.type == T_EQUAL) {
		lex();
		struct ASTnode *n = binary_expression(0);
		v->value = calculate_binary_tree(n);
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
}

const int OpPrec[] = {
	10, 10, 20, 20, 20,

	0, 0,

	0, 0, 10, 10, 0,

	0, 0
};

struct ASTnode *primary()
{
	struct ASTnode *n;
	int index = -1;
	switch (c_token.type) {
		case T_CONST :
			n = mkastleaf(A_CONST, c_token.value);
			lex();
			return n;
		case T_IDENT :
			index = find_var(Text);
			if (index == -1)
				panic("Variable '%s' not found", Text);
			n = mkastleaf(A_IDENT, index);
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
	if (tokentype == T_SEMI || tokentype == T_CP) {
		return left;
	}

	while (op_precedence(tokentype) > ptp) {
		lex();
		right = binary_expression(OpPrec[tokentype]);
		left = mkastnode(arithop(tokentype), left, right, 0);
		tokentype = c_token.type;
		if (tokentype == T_SEMI || tokentype == T_CP) {
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
			return variables[n->value]->value;
	}
}

void print_ast(struct ASTnode *n, int depth)
{
	for (int i = 1; i <= depth; i++) {
		putchar(' ');
	}
	printf("%s", ArithOp_str[n->op]);
	if (n->op == A_CONST) {
		printf(" : %d", n->value);
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
	lex();
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
	} else if (c_token.type == T_IDENT) {
		printf(" : %s", Text);
	}
	putchar('\n');
}
