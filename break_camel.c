#include <stddef.h> // NULL
#include <stdlib.h>
#include <stdio.h>

int strlength(const char *s)
{
	const char *p = s;
	int res = 0;
	while (*p++)
		res++;
	return res;
}

#define IS_UPPER(c) (c >= 'A' && c <= 'Z')

//returned buffer should be dynamically allocated and will be freed by a caller
char* solution(const char *s) {
	if (s == NULL)
		return NULL;
	int len = strlength(s);
	const char *p = s;
	int upp_count = 0;
	while (*p) {
		if (IS_UPPER(*p++))
			upp_count++;
	}
	char *str = malloc((len + upp_count));
	char *sp = str;
	p = s;
	while (*p) {
		if (IS_UPPER(*p)) {
			*sp++ = ' ';
		}
		*sp++ = *p++;

	}
	return str;
}

int main()
{
	printf("%s\n", solution("fcegahEcdfgCcabBdcbefFghbCfebefAaDfbghdGeCgdaea"));
}
