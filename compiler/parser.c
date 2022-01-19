#include "parser.h"
#include <stdio.h>
#include "lex.h"

extern char* newname();
extern void freename();

void statements()
{
	expression();
	if (match(SEMI))
		advance();
	else
		fprintf(stderr,"%d : Missed semicolon\n",lineno);
	if (!match(EOI))
		statements();
}

void expression()
{
	term();
	exp_prime();
}

void exp_prime()
{
	if (match(PLUS)) {
		advance();
		term();
		exp_prime();
	}
}

void term()
{
	factor();
	term_prime();
}

void term_prime()
{
	if (match(TIMES)) {
		advance();
		factor();
		term_prime();
	}
}

void factor()
{
	if (match(NUM_OR_ID))
		advance();
	else if (match(LP)) {
		advance();
		expression();
		if (match(RP))
			advance();
		else
			fprintf(stderr,"%d : Mismatched parenthesis\n",lineno);
	} else
		fprintf(stderr,"%d : Number or Identifier expected\n",lineno);
}
