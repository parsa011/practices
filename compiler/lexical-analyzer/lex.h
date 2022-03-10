#include <stdio.h>

FILE *fp;

enum {
    T_INTLIT,
    T_STAR,
    T_SLASH,
    T_PLUS,
    T_DASH,
    T_GREATER,
    T_LOWER,
    T_GREATER_EQAUL,
    T_LOWER_EQAUL,
    T_NOT_EQUAL,
	T_OPEN_PARENTHESIS,
	T_CLOSE_PARENTHESIS,
	T_OPEN_CURLYB,
	T_CLOSE_CURLYB,
	T_SEMI,
	T_ONELINE_COMMENT,
	T_MULTYLINE_COMMENT,
    T_EOF
} Token_Type;

const char *Token_name[] = {
    "Int Literal",
    "Star",
    "Slash",
    "Plus",
    "Dash",
    "Greater",
    "Lower",
    "Greater Or Equal",
    "Lower Or Equal",
    "Not Equal",
	"Open Parenthesis",
	"Close Parenthesis",
	"Open Curly Braces",
	"Close Curly Braces",
	"Semicolon",
	"One Line Comment",
	"Multy Line Comment",
    "Enf Of File"
};

struct Token{
    int type;
    int value;
};

struct Token token;

int lex();
