#include "tint.h"

#include <stdio.h>
#include <stdarg.h>

#include "file.h"
#include "parser.h"

struct lexer_t lexer;

void die(char *msg, ...)
{
	char buf[256];
	va_list ap;
	va_start(ap, msg);
	vsprintf(buf, msg, ap);
	va_end(ap);
	fprintf(stderr, "%s\n", buf);
	exit(2);
}

void usage(char *program_name)
{
	printf("Program Usage : %s filename\n",program_name);
	exit(0);
}

int calc_tree(struct ASTnode *n)
{
    int left, right;
    if (n->left)
        left = calc_tree(n->left);
    if (n->right) 
        right = calc_tree(n->right);

    switch (n->kind) {
        case A_INTLIT :
            return n->intvalue;
        case A_MULTIPLY :
            return left * right;
        case A_DIVIDE :
            return left / right;
        case A_ADD :
            return left + right;
        case A_SUBTRACT :
            return left - right;
    }
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		usage(argv[0]);
	}
	open_file(argv[1]);
	lex();
	struct ASTnode *n = statements(0);
	int res = calc_tree(n);
	printf("Result is %d\n", res);
	//do {
		//lex();
		//if (c_token.kind == T_INTLIT)
			//printf("int literal : %d\n", c_token.value);
		//else 
			//printf("operand : %d\n", c_token.kind);
	//} while (c_token.kind != T_EOF);
	return 0;
}
