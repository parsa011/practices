#include "token.h"
#include "data.h"
#include "decl.h"

// Parse a primary factor and return an
// AST node representing it.
static struct ASTnode *primary()
{
    struct ASTnode *n;
    // For an INTLIT token, make a leaf AST node for it
    // and scan in the next token. Otherwise, a syntax error
    // for any other token type.
    switch (Token.token) {
       case T_OPEN_PARENTHESIS :
           scan(&Token);
           n = binexpr(0);
           //scan(&Token);
           if (Token.token != T_CLOSE_PARENTHESIS) {
               printf("Unclosed Parenthesis\n");
               exit(0);
           }
           return n;
        case T_INTLIT :
            n = mkastleaf(A_INTLIT,Token.intvalue);
            scan(&Token);
            return n;
        default:
            fprintf(stderr, "syntax error on line %d, token %d\n", Line, Token.token);
            exit(1);
    }
}

// Convert a binary operator token into an AST operation.
int arithop(int tokentype) 
{
    switch (tokentype) {
        case T_PLUS:
            return (A_ADD);
        case T_MINUS:
            return (A_SUBTRACT);
        case T_STAR:
            return (A_MULTIPLY);
        case T_SLASH:
            return (A_DIVIDE);
        case T_OPEN_PARENTHESIS :
            return A_EXPR;
        default:
            fprintf(stderr, "syntax error on line %d, token %d\n", Line, tokentype);
            exit(1);
    }
}

// Operator precedence for each token
static int OpPrec[] = { 0, 10, 10, 20, 20, 20, 20, 0 };
//                     EOF  +   -   *  /   OP  CP  INTLIT

// Check that we have a binary operator and
// return its precedence.
static int op_precedence(int tokentype) 
{
    int prec = OpPrec[tokentype];
    printf("prec is %d\t%d\n", prec, tokentype);
    if (prec == 0) {
        fprintf(stderr, "syntax error on line %d, token %d\n", Line, tokentype);
        exit(1);
    }
    return (prec);
}

// Return an AST tree whose root is a binary operator.
// Parameter ptp is the previous token's precedence.
struct ASTnode *binexpr(int ptp) 
{
    struct ASTnode *left, *right;

    left = primary();

    int tokentype = Token.token;
    if (tokentype == T_EOF)
        return left;
    while (op_precedence(tokentype) > ptp) {
        scan(&Token);

        right = binexpr(OpPrec[tokentype]);

        left  = mkastnode(arithop(tokentype), left, right, 0);

        if ((tokentype = Token.token) == T_EOF)
            return left;
    }
    return left;
}
