#ifndef _AST_H
# define _AST_H

// AST node types
enum {
  A_ADD, A_SUBTRACT, A_MULTIPLY, A_DIVIDE, A_INTLIT
};

struct ASTnode {
	int kind;
	struct ASTnode *left;
	struct ASTnode *right;
	int intvalue;
};

struct ASTnode *mkastnode(int, struct ASTnode *, struct ASTnode *, int);
struct ASTnode *mkastleaf(int, int);
struct ASTnode *mkastunary(int, struct ASTnode *, int);

#endif
