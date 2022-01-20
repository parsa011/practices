#include <stdio.h>
#include <string.h>
#include "lex.h"
#include "parser.h"

int main(int argc,char *argv[])
{ 
	//int c = lex();
	//while (c != EOI) {
	//	printf("=========\nline : %d \ntext : %stype : %s\n=========\n",lineno,text,token_names[c]);
	//	c = lex();
	//}
	statements();
	return 0;
}
