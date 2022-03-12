#include "statements.h"

#include "parser.h"
#include "ast.h"

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

void statements()
{
    struct ASTnode *n;

    while (1) {
        lex();
        if (c_token.kind == T_EOF)
            break;
		match(T_PRINT, "Print Token Expected");
		lex();
        n = bin_expression(0);
        int res = calc_tree(n);
        printf("Res of expr : %d\n", res);
        //if (c_token.kind == T_EOF)
          //  break;
    }
}
