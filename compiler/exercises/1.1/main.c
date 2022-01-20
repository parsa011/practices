#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *buf;
int length = 0;

/* current token (no struct :) )*/
char token[32];
int type;

int getl(char *);
int readl();

/* also we can use enums */
#define EOI			0
#define SEMI		1
#define	PLUS		2
#define	TIMES		3
#define	LP			4
#define RP			5
#define	NUM_OR_ID	6
#define BADTOKEN	7
const char *token_names[]  = {
	"End of Input",
	"Semicolon",
	"Plus",
	"Times",
	"Left Parenthesis",
	"Right Parenthesis",
	"Number Or Id"
};

/* lexer */
int lookahead = -1;
int match(int);
void advance();
int next();

/* parser */
void parse();

int main(int argc,char *argv[])
{
	buf = (char *)malloc(20);

	do {
		readl();
		type = next();
		printf("current token is %d and text is : %s\n",type,token);
	} while (!match(EOI));

	return 0;
}

int readl()
{
	printf(">>> ");
	length = getl(buf);
}

int getl(char *line)
{
	int i = 0;
	int c;
	while ((c = getchar()) != EOF) {
		if (c == '\n')
			break;
		line[i++] = c;
	}
	line[i] = 0;
	return i;
}

int next()
{
	static int offset = 0;
	if (offset == length) {
		offset = 0;
		token[offset] = 0;
		return EOI;
	}
	char *p = buf + offset;
	char *tokenp = token;
	while (*p) {
			*tokenp++ = *p;
			*tokenp++ = 0;
			length = 1;
			switch (*p) {
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
					if (!isalnum(*p)) {
						fprintf(stderr,"Ignoring illegal input <%c>\n", *p);
						*token = 0;
						type = BADTOKEN;
					}
					else {
						tokenp--;
						while (isalnum(*p)) {
							p++;
							*tokenp++ = *p;
						}
						length = p - buf;
						*tokenp++ = 0;
						return NUM_OR_ID;
					}
					break;			
		}
		p++;
	}
}

int match(int token)
{
	if (lookahead == -1)
		lookahead = next();
	return lookahead == token;
}

void advance()
{
	lookahead = next();
}
