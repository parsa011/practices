#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "def.h"

#define PROMPT ">>"

void write_prompt();

int main()
{
	statements();
	return 0;
}

void write_prompt()
{
	printf("%s ",PROMPT);
}
