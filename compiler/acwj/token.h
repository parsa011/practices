#ifndef _TOKEN_H
# define _TOKEN_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Token types
enum {
  T_EOF,                //0
  T_PLUS,               //1
  T_MINUS,              //2
  T_STAR,               //3
  T_SLASH,              //4
  T_OPEN_PARENTHESIS,   //5
  T_CLOSE_PARENTHESIS,  //6
  T_INTLIT              //7
};

// AST node types
enum {
  A_ADD,
  A_SUBTRACT,
  A_MULTIPLY,
  A_DIVIDE,
  A_EXPR,
  A_INTLIT
};

struct token {
    int token;
    int intvalue;
};

// Abstract Syntax Tree structure
struct ASTnode {
  int op;				// "Operation" to be performed on this tree
  struct ASTnode *left;			// Left and right child trees
  struct ASTnode *right;
  int intvalue;				// For A_INTLIT, the integer value
};

#endif
