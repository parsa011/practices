#include "lex.h"
#include <stdio.h>
#include <ctype.h>

const char *token_names[]  = {
	"End of Input",
	"Semicolon",
	"Plus",
	"Times",
	"Left Parenthesis",
	"Right Parenthesis",
	"Number Or Id"
};

static int Lookahead = -1;

char *text = "";
int length = 0;
int lineno = 0;

int lex()
{
	static char input_buffer[128];
	char *current = text + length;

	while (1) {
		while (!*current) {
			current = input_buffer;
			if (!fgets(input_buffer,sizeof(input_buffer),stdin)) {
				current = '\0';
				return EOI;
			}
			lineno++;
			while (isspace(*current))
				current++;
		}

		for (; *current; ++current) {
			text = current;
			length = 1;
			switch (*current) {
				case EOF : 
					return EOI;
				case 'i' : 
					return SEMI;
				case '+' : 
					return PLUS;
				case '*' : 
					return TIMES;
				case '(' : 
					return LP;
				case ')' : 
					return RP;
				case ';' :
					return SEMI;
				case '\n' :
				case '\t' :
				case ' '  :
					break;
				default :
					if (!isalnum(*current))
						fprintf(stderr,"Ignoring illegal input <%c>\n", *current);
					else {
						while (isalnum(*current))
							current++;
						length = current - text;
						return NUM_OR_ID;
					}
					break;
			}
		}
	}
}

int match(int token)
{
	if (Lookahead < 0)
		Lookahead = lex();
	return token == Lookahead;
}

void advance()
{
	Lookahead = lex();
}
