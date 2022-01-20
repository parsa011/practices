#include "parser.h"
#include <stdio.h>
#include <stdarg.h>
#include "lex.h"

#define MAXFIRST 16
#define SYNCH SEMI

extern char* newname();
extern void freename();

int legal_lookahead(int first_arg,...)
{
	va_list args;
	int tok;
	int lookaheads[MAXFIRST], *p = lookaheads, *current;
	int error_printed = 0;
	int rval = 0;

	va_start(args,first_arg);
	if (!first_arg) {
		if (match(EOI))
			rval = 1;
	} else {
		*p++ = first_arg;
		while (tok = va_arg(args,int) && p < &lookaheads[MAXFIRST])
			*++p = tok;
		while (!match(SYNCH)) {
			for (current = lookaheads; current < p; ++current) {
				if (match(*current)) {
					rval = 1;
					goto exit;
				}
			}
			if (!error_printed) {
				fprintf(stderr,"Line %d : Syntax error\n",lineno);
				error_printed = 1;
			}
			advance();
		}
	}
exit:
	va_end(args);
	return rval;
}

void statements()
{
	char *tempvar;
	while (!match(EOI)) {
		tempvar = expression();
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
		printf(" %s += %s\n", tempvar, tempvar2);
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
		printf ("%s *= %s\n", tempvar, tempvar2 );
		freename(tempvar2);
	}
	return tempvar;
}

char *factor()
{
	char *tempvar;
	if (match(NUM_OR_ID)) {
		printf(" %s %0.*s\n", tempvar = newname(), length, text);
		advance();
	}
	else if (match(LP)) {
		advance();
		tempvar = expression();
		if (match(RP))
			advance();
		else
			fprintf(stderr,"%d : Mismatched Parenthesis\n",lineno);
	} else
		fprintf(stderr,"%d : Number or Identifier Expected\n",lineno);
	return tempvar;
}
