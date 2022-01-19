#include "def.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

static int Lookahead = -1;

char *text = "";
int lineno = 0;
int length = 0;

int next()
{
	static char input_buffer[128];
	char *current = text + length;
	while (1) {
		if (!*current) {
			current = input_buffer;
			if (!fgets(input_buffer,sizeof(input_buffer),stdin)) {
				current = '\0';
				return EOI;
			}
			lineno++;
			while (isspace(*current))
				current++;
		}
		while (*current) {
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
	if (Lookahead == -1)
		Lookahead = next();
	return Lookahead == token;
}

void advance()
{
	Lookahead = next();
}
