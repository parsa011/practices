#include "tint.h"
#include <assert.h>

void open_file(char *name)
{
	lexer.fp = fopen(name, "r");
	if (!lexer.fp) {
		die("File %s Not Found", name);
	}
}

void close_file()
{
	assert(lexer.fp);
	if (lexer.fp) {
		fclose(lexer.fp);
	}
}

char read_char()
{
	assert(lexer.fp);

}
