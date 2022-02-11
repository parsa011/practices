#include "token.h"
#define extern_
#include "data.h"
#undef extern_
#include "decl.h"

void usage(char *name)
{
    printf("Usage : %s filename\n",name + 2);
    exit(0);
}

void panic(char *msg)
{
    printf("%s\n",msg);
    exit(0);
}

void open_file(char *name)
{
    file = fopen(name,"r");
    if (!file) {
        panic("File not found");
    }
}

void close()
{
    fclose(file);
}

void init()
{
    Line = 1;
    Putback = 0;
}

void print_spaces(int n)
{
	while (n--) {
    	putchar(' ');
    }
}

char get_op_title(int i)
{
	switch(i) {
    	case A_MULTIPLY : 
        	return '*';
        case A_DIVIDE : 
        	return '/';
        case A_ADD : 
        	return '+';
        case A_SUBTRACT :
        	return '-';
    }
}

int calc_ast(struct ASTnode *n)
{
	int left, right;
    
    if (n->left) {
    	left = calc_ast(n->left);
    }
    if (n->right) {
    	right = calc_ast(n->right);
    }
    
    switch (n->op) {
    	case A_INTLIT:
        	return n->intvalue;
    	case A_ADD : 
        	return left + right;
        case A_SUBTRACT : 
        	return left  - right;
        case A_MULTIPLY :
        	return left * right;
        case A_DIVIDE : 
        	return left / right;
    }
}

void print_ast(struct ASTnode *n,int offset)
{
	print_spaces(offset);
	printf("%c\n",get_op_title(n->op));
    
    if (n->left->op == A_INTLIT) {
    	print_spaces(offset + 2);
        printf("%d\n",n->left->intvalue);
    } else {
    	print_ast(n->left,offset + 2);
    }
    
    if (n->right->op == A_INTLIT) {
    	print_spaces(offset + 2);
        printf("%d\n",n->right->intvalue);
    } else {
    	print_ast(n->right,offset + 2);
    }
}

int main(int argc,char *argv[])
{
    if (argc < 2)
        usage(argv[0]);
    init();
    open_file(argv[1]);
    scan(&Token);
    struct ASTnode *n = binexpr(0);
    print_ast(n,0);
    printf("result is %d\n",calc_ast(n));
	close();
	return 0;
}
