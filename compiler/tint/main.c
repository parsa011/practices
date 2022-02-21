#include "tint.h"

#include <stdio.h>
#include <stdarg.h>

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

int main(int arvc, char *argv[])
{
	printf("WORKING\n");
	return 0;
}
