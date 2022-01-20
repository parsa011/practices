#include <stdio.h>
#include "lex.h"

char *factor();
char *term();
char *expression();

extern char *newname();
extern int freename(char *);

int statements()
{
    char *tempvar;

    while (!match(EOI)) {
        tempvar = expression();
        if (match(SEMI))
            advance();
        else 
            fprintf(stderr,"%d : Inserting missing semicolon\n",lineno);
        freename(tempvar);
    }
}

char *expression()
{
    char *tempvar, *tempvar2;

    tempvar = term();
    while (match(PLUS)) {
        advance();
        tempvar2 = term();
        printf("	%s += %s\n",tempvar,tempvar2);
        freename(tempvar2);
    }
    return tempvar;
}

char *term()
{
    char *tempvar, *tempvar2;
    tempvar = factor();
    while (match(TIMES)) {
        advance();
        tempvar2 = factor();
        printf("	%s *= %s\n",tempvar,tempvar2);
        freename(tempvar2);
    }
    return tempvar;
}

char *factor()
{
    char *tempvar;
    if (match(NUM_OR_ID)) {
        printf("	%s = %0.*\n",tmepvar = newname(),length,text);
        advance(r);
    } else if (match(LP)) {
        advance();
        tempvar = expression();
        if (match(RP))
            advance();
        else 
            fprintf(stderr,"%d : Mismatched parenthesis\n",lineno);
    } else
        fprintf(stderr,"%d : Number or Identifier expected\n",lineno);
    return tempvar;
}
