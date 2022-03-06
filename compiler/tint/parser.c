#include "parser.h"

#include "tint.h"
#include "lexer.h"

int OpPrec[] = { 0, 0, 10, 10, 20, 20 };

private int operand_precedence(int tokentype)
{
    int prec = OpPrec[tokentype];
    if (prec == 0) {
        die("Operand expected");
    }
    return prec;
}

private struct ASTnode *primary()
{
    struct ASTnode *n;

    // For an INTLIT token, make a leaf AST node for it
    // and scan in the next token. Otherwise, a syntax error
    // for any other token type.
    switch (c_token.kind) {
        case T_INTLIT:
            n = mkastleaf(A_INTLIT, c_token.value);
            lex();
            return (n);
        default:
            die("Int literal expected");
    }

}
// Convert a binary operator token into an AST operation.
private int arithop(int tokentype) 
{
    switch (tokentype) {
        case T_PLUS:
            return (A_ADD);
        case T_DASH:
            return (A_SUBTRACT);
        case T_STAR:
            return (A_MULTIPLY);
        case T_SLASH:
            return (A_DIVIDE);
        default:
            die("Invalid Airthmetic operand");
    }
}

public struct ASTnode *statements(int ptp)
{
    struct ASTnode *left, *right;

    left = primary();

    int tokentype = c_token.kind;

    if (tokentype == T_EOF)
        return left;

    while (operand_precedence(tokentype) > ptp) {
        /* fetch next int literal */
        lex();

        // Recursively call binexpr() with the
        // precedence of our token to build a sub-tree
        right = statements(OpPrec[tokentype]);

        // Join that sub-tree with ours. Convert the token
        // into an AST operation at the same time.
        left = mkastnode(arithop(tokentype), left, right, 0);

        // Update the details of the current token.
        // If no tokens left, return just the left node
        tokentype = c_token.kind;
        if (tokentype == T_EOF)
            return (left);

    }

    return left;
}
