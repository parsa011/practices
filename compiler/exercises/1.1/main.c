#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char buf[128];
int length = 0;
int lineno = 0;

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
#define WHITESPACE	8
#define EQAUL		9
#define COMMA		10

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
void next();

/* parser */
void parse();
void type_decl();
void get_type();
void get_name();

/* utils */
int istype();

int main(int argc,char *argv[])
{
	while (1) {
		readl();
		printf("\t\t%s\n",buf);
		//parse();
		do {
			advance();
		} while (!match(EOI));
	}

	return 0;
}

void parse()
{
	type_decl();
}

void type_decl()
{
}

void get_type()
{
}

void get_name()
{

}

int readl()
{
	printf(">>> ");
	length = getl(buf);
	lineno++;
}

int getl(char *line)
{
	int i = 0;
	int c;
	while ((c = getchar()) != EOF && c != '\n') {
		line[i++] = c;
	}
	line[i] = 0;
	return i;
}

int offset = 0;
void next()
{
	if (offset >= length) {
		offset = 0;
		token[0] = 0;
		type = EOI;
		return;
	}
	char *p = buf + offset;
	char *tokenp = &token[0];
	if (*p) {
		offset++;
		while (isspace(*p)) {
			offset++;
			p++;
		}
		*tokenp++ = *p;
		*tokenp++ = 0;
		switch (*p) {
			case '=' :
				type = EQAUL;
				break;
			case '+' : 
				type = PLUS;
				break;
			case '*' : 
				type = TIMES;
				break;
			case '(' : 
				type = LP;
				break;
			case ')' : 
				type = RP;
				break;
			case ';' :
				type = SEMI;
				break;
			case ',' :
				type = COMMA;
				break;
			case '\n' :
			case '\t' :
			case ' '  :
				type = WHITESPACE;
				break;
			default :
				p++;
				if (!isalnum(*p)) {
					fprintf(stderr,"Ignoring illegal input <%c> offset is %d , length : %d\n", *p,offset,length);
					type = BADTOKEN;
					break;
				}
				else {
					tokenp--;
					while (isalnum(*p)) {
						++offset;
						*tokenp++ = *p++;
					}
					
					*tokenp = 0;
					type = NUM_OR_ID;
				}
				break;			
		}
		p++;
	}
}

int match(int token)
{
	if (lookahead == -1)
		advance();
	return lookahead == token;
}

void advance()
{
	next();
	lookahead = type;
	printf("token is <'%s'> \t %d\n",token,type);
}

/* simple check for given text */
int istype(char *text)
{
	if (strcmp(text,"int") == 0) {
		return 1;
	} else if (strcmp(text,"float") == 0)
		return 1;
	return 0;
}
