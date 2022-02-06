#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

char buf[128];
int length = 0;
int lineno = 0;

/* current token (no struct :) )*/
char token[32];
int type;

int getl(char *);
int readl();

char *keywords[] = {
    "[Not Valid]",
    "char",
    "float",
    "int",
    "const",
    "static"
};

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
int offset = 0;
int lookahead = -1;
int match(int);
void advance();
void next();
void pushback();
bool iseoi();

/* parser */
void parse();

void type_decl();
void type_qualifier();
void type_specifier();
void type_name();


/* utils */
int istype(char *);
int isqualifier(char *);

float calc_matching(char *,char *);
int get_same_token_name_index(char *);
int get_lcs(char *,char *);

int main(int argc,char *argv[])
{
	while (1) {
		readl();
		parse();
		//do {
		//	advance();
		//	printf("token <'%s'>\n",token);
		//} while (!match(EOI));
	}

	return 0;
}

void parse()
{
	type_decl();
	advance();
	if (match(SEMI)) {
		advance();
	} else {
		fprintf(stderr,"%d : Missed Semicolon\n",lineno);
	}
}

void type_decl()
{
	type_specifier();
}

void type_specifier()
{

}

int readl()
{
	printf(">>> ");
	length = getl(buf);
	lineno++;
	offset = 0;
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

bool iseoi()
{
    return offset == strlen(buf) - 1;
}

void next()
{
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
				if (!isalnum(*p)) {
					fprintf(stderr,"Ignoring illegal input <%c>\n", *p);
					type = BADTOKEN;
					break;
				}
				else {
					p++;
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
	} else {
		offset = 0;
		token[0] = 0;
		type = EOI;
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
}

void pushback()
{
    int len = strlen(token);
    offset -= len;
}


int get_lcs(char *s1,char *s2)
{
	int res = 0;
	int s1_bigger = strlen(s1) > strlen(s2);
	char *longer = s1_bigger ? s1 : s2,*less = !s1_bigger ? s1 : s2;
	int temp = 0;
	while (*longer) {
		if (tolower(*longer++) == tolower(*less++))
			temp++;
		else {
			res += temp;
			temp = 0;
		}
	}
	if (temp > 0)
    	res += temp;
	return res;
}

float calc_matching(char *s1,char *s2)
{
	int lcs = get_lcs(s1,s2);
	return lcs * 2.0f / (strlen(s1) + strlen(s2));
}

int get_same_token_name_index(char *token)
{
    int len = sizeof(keywords) / sizeof(keywords[0]);
	int matched = 0;
	float last_percent = 0;
    for (int i = 0; i < len; i++) {
        float current = calc_matching(token,keywords[i]);
        if (current >= last_percent) {
            matched = i;
            last_percent = current;
        }
	}    
	return matched;
}
/* simple check for given text */
int istype(char *text)
{
	if (strcmp(text,"int") == 0 || strcmp(text,"float") == 0 || strcmp(text,"char") == 0)
		return 1;
	return 0;
}

int isqualifier(char *text)
{
	if (strcmp(text,"const") == 0 || strcmp(text,"static") == 0)
		return 1;
	return 0;

}
