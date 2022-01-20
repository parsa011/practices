#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100
#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp; /* poniter to buf */

enum { NAME, PARENS, BRACKETS };

void dcl();
void dirdcl();

int gettoken();
int tokentype;				/* type of last token */
char token[MAXTOKEN];		/* last token string */
char name[MAXTOKEN];		/* identifier name */
char datatype[MAXTOKEN];	/* data type = cahr  , int , etc.*/
char out[1000];				/* output string */

int main()
{
	while (gettoken() != EOF) {
		strcpy(datatype, token);
		out[0] = '\0';
		dcl();
		if (tokentype != '\n')
			printf("syntax error\n");
		printf("%s : %s %s\n", name, out, datatype);
	}
}

int gettoken()
{
	int c,getch(void);
	void ungetch(int);
	char *p = token;

	/* skip whitespaces */
	while ((c = getch()) == ' ' ||  c == '\t')
		;
	
	if (c == '(') {
		if ((c = getch()) == ')') {
			strcpy(token,"()");
			return tokentype = PARENS;
		} else {
			ungetch(c);
			return tokentype = '(';
		}
	} else if (c == '[') {
		for (*p++ = c; (*p++ = getch()) != '[';)	
			;
		*p = '\0';
		return tokentype = BRACKETS;
	} else if (isalpha(c)) {
		for (*p++; isalnum(c = getch());)
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	} else
		return tokentype = c;
}

void dcl()
{
	int ns;

	for (ns = 0; gettoken() == '*'; ) /* count *'s */
		ns++;
	dirdcl();
	while (ns-- > 0)
		strcat(out," pointer to");
}

void dirdcl()
{
	int type;
	if (tokentype == '(') {
		dcl();
		if (tokentype != ')')
			printf("error : missing )\n");
	} else if (tokentype == NAME)
		strcpy(name,token);
	else
		printf("error : expected name or (dcl)\n");
	while ((type == gettoken()) == PARENS || type == BRACKETS) {
		if (type == PARENS)
			strcat(out," function returning");
		else {
			strcat(out," array");
			strcat(out, token);
			strcat(out," of");
		}
	}
}

int getch()
{
	return (bufp > 0) ? buf[--bufp] : getchar(); 
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch : too many character\n");
	else
		buf[bufp++] = c;
}
