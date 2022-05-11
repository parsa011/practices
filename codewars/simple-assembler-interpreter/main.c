#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STR_EQ(s, t) (strcmp(s, t) == 0)

const char *source;     // our source code as string
char current_char; // current char that readed from file
char put_back;     // put back character
int offset;       // how many char readed in file
int lineno;       // current line number
int colno;        // column number from start of line

// token
enum {
    T_IDENT, T_COMMA, T_COLON, T_ADD, T_INC, T_INTLIT,
    T_MOV, T_SUB, T_END, T_RET, T_MUL,
    T_JMP, T_MSG, T_JG, T_CALL, T_DEC,
    T_DIV, T_CMP, T_JNE, T_JE, T_JGE,
    T_JLE, T_LE, T_JL, T_EOF, T_BAD
};
int tokentype;
#define BUFFER_SIZE 64
char buffer[BUFFER_SIZE];
int bufp;
int intvalue;

// lexer
char next();
char skip();
void lex();
void putback(char);

char next()
{
	if (put_back) {
		current_char = put_back;
		put_back = 0;
		return current_char;
	}
	current_char = *source++;
	offset++;
	colno++;
	if (current_char == '\n') {
		lineno++;
		colno = 0;
	}
	return current_char;
}

char skip()
{
	char c;
	do {
		c = next();
	} while (isspace(c));
	return c;
}

void putback(char ch)
{
	put_back = ch;
}

int guess_text_type(char *text) 
{
	if (STR_EQ(text, "mov"))
		return T_MOV;
	else if (STR_EQ(text, "inc"))
		return T_INC;
	else if (STR_EQ(text, "dec"))
		return T_DEC;
	else if (STR_EQ(text, "add"))
		return T_ADD;
	else if (STR_EQ(text, "sub"))
		return T_SUB;
	else if (STR_EQ(text, "mul"))
		return T_MUL;
	else if (STR_EQ(text, "div"))
		return T_DIV;
	else if (STR_EQ(text, "jmp"))
		return T_JMP;
	else if (STR_EQ(text, "cmp"))
		return T_CMP;
	else if (STR_EQ(text, "jne"))
		return T_JNE;
	else if (STR_EQ(text, "je"))
		return T_JE;
	else if (STR_EQ(text, "jge"))
		return T_JGE;
	else if (STR_EQ(text, "jg"))
		return T_JG;
	else if (STR_EQ(text, "jle"))
		return T_JLE;
	else if (STR_EQ(text, "jl"))
		return T_JL;
	else if (STR_EQ(text, "call"))
		return T_CALL;
	else if (STR_EQ(text, "ret"))
		return T_RET;
	else if (STR_EQ(text, "msg"))
		return T_MSG;
	return T_IDENT;
}

void lex()
{
	int c = skip();
	bufp = 0;
	buffer[bufp] = 0;
	switch (c) {

		case 0 :
		case EOF :
			tokentype = T_EOF;
			break;

		case ',' :
			tokentype = T_COMMA;
			break;

		case ':' :
			tokentype = T_COLON;
			break;

		case ';' :
			do {
				c = next();
			} while (c != '\n');
			putback(c);
			lex();
			break;

		default :
			if (isdigit(c) || c == '-') {
				int sign = 1;
				if (c == '-') {
					c = next();
					sign = -1;
				}
				tokentype = T_INTLIT;
				int res = c - '0';
				c = next();
				while (isdigit(c)) {
					res = res * 10 + (c - '0');
					c = next();
				}
				intvalue = res * sign;
				putback(c);
				break;
			} else if (isalpha(c) || c == '_') {
				buffer[bufp++] = c;
				c = next();
				while (isalpha(c) || c == '_') {
					buffer[bufp++] = c;
					c = next();
				}
				putback(c);
				buffer[bufp] = 0;
				tokentype = guess_text_type(buffer);
				break;
			}
			tokentype = T_BAD;
	}
}

// parser

void init(const char *input)
{
	current_char = put_back = lineno = colno = offset = 0;
	source = input;
}

char* assembler_interpreter(const char* program) 
{
    init(program);
	lex();

	while (tokentype != T_EOF) {

		switch (tokentype) {

			case T_MOV :
				//move_instruction();
				break;

		}

		lex();
	}
}

int main(int argc, char **argv)
{
	assembler_interpreter("\
mov   a, 81         ; value1\n\
mov   b, 153        ; value2\n\
call  init\n\
call  proc_gcd\n\
call  print\n\
end\n\
\n\
proc_gcd:\n\
    cmp   c, d\n\
    jne   loop\n\
    ret\n\
\n\
loop:\n\
    cmp   c, d\n\
    jg    a_bigger\n\
    jmp   b_bigger\n\
\n\
a_bigger:\n\
    sub   c, d\n\
    jmp   proc_gcd\n\
\n\
b_bigger:\n\
    sub   d, c\n\
    jmp   proc_gcd\n\
\n\
init:\n\
    cmp   a, 0\n\
    jl    a_abs\n\
    cmp   b, 0\n\
    jl    b_abs\n\
    mov   c, a            ; temp1\n\
    mov   d, b            ; temp2\n\
    ret\n\
\n\
a_abs:\n\
    mul   a, -1\n\
    jmp   init\n\
\n\
b_abs:\n\
    mul   b, -1\n\
    jmp   init\n\
\n\
print:\n\
    msg   'gcd(', a, ', ', b, ') = ', c\n\
    ret\n\
");

	return 0;
}
