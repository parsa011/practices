#ifndef _TOKEN_H
# define _TOKEN_H

struct token_t {
	int kind;
	int value;
};

enum token_kind{
	T_EOF,
	T_INTLIT,
	T_PLUS,
	T_DASH,
	T_STAR,
	T_SLASH
};

#endif
