#include "tint.h"

#include <stdio.h>
#include <stdarg.h>

#include "file.h"

struct lexer_t lexer;

void die(char *msg, ...)
{
	char buf[256];
	va_list ap;
	va_start(ap, msg);
	vsprintf(buf, msg, ap);
	va_end(ap);
	fprintf(stderr, "%s\n", buf);
	exit(2);
}

void usage(char *program_name)
{
	printf("Program Usage : %s filename\n",program_name);
	exit(0);
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		usage(argv[0]);
	}
	open_file(argv[1]);
	do {
		lex();
		printf("%d\n", c_token.kind);
	} while (c_token.kind != T_EOF);
	return 0;
}
