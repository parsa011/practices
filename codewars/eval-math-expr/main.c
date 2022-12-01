#include <stdio.h>
#include <ctype.h>

const char *buf;
const char *ptr;

double const_value;

enum {
	TOKEN_PLUS,
	TOKEN_MINUS,
	TOKEN_STAR,
	TOKEN_SLASH,
	TOKEN_CONST,
	TOKEN_OPEN_PAREN,
	TOKEN_CLOSE_PAREN,
	TOKEN_BAD,
	TOKEN_EOF
};

void putback()
{
	if (ptr > buf)
		ptr--;
}

void next()
{
	if (!ptr)
		ptr = buf;
	else
		ptr++;
}

void init_lexer(const char *input)
{
	buf = input;
}

void scan_const()
{
#define CHAR_TO_INT(c) (c - '0')
	double res = 0;
	double pow = 1;
	double floating_point = 0;
	int is_float = 0;
	while (isdigit(*ptr)) {
		if (is_float) {
			pow *= 10;
			floating_point = floating_point * 10 + CHAR_TO_INT(*ptr);
		} else
			res = res * 10 + CHAR_TO_INT(*ptr);
		next();
		if (*ptr == '.') {
			is_float = 1;
			next();
		}
	}
	putback();
	const_value = res + floating_point / pow;
#undef CHAR_TO_INT
}

int lex()
{
	next();
	switch (*ptr) {
	case '\0' :
		return TOKEN_EOF;
	case '-' :
		next();
		if (isdigit(*ptr)) {
			scan_const();
			const_value *= -1;
			return TOKEN_CONST;
		}
		putback();
		return TOKEN_MINUS;
	case '+' :
		return TOKEN_PLUS;
	case '*' :
		return TOKEN_STAR;
	case '/' :
		return TOKEN_SLASH;
	case '(' :
		return TOKEN_OPEN_PAREN;
	case ')' :
		return TOKEN_CLOSE_PAREN;
	case ' ' :
	case '\n' :
	case '\r' :
		return lex();
	default :
		if (isdigit(*ptr)) {
			scan_const();
			return TOKEN_CONST;
		}
	}
	return TOKEN_BAD;
}

double calculate(const char *expression)
{
	init_lexer(expression);
	int type;
	int depth = 0;
#define token() (type = lex())
#define STACK_MAX 32
	double stack[STACK_MAX];
	double *stack_ptr = stack;
#define push() {										\
		*stack_ptr++ = const_value;						\
	}
	token();
	while (type != TOKEN_EOF) {
		switch (type) {
		case TOKEN_OPEN_PAREN :
			token();
			depth++;
		case TOKEN_CONST :
			push();
		}
		token();
	}
#undef push
#undef STACK_MAX
#undef token
	return 0;
}

int main(int argc, char *argv[])
{
	printf("2 / (2 + 3) * 4.33 - -6 => %f\n", calculate("2 / (2 + 3) * 4.33 - -6"));
	/* printf("12*-1 => %f\n", calculate("12*-1")); */
	return 0;
}
