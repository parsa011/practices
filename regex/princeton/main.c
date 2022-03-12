#include <stdio.h>

int match(char *regex, char *text);
int matchstar(int, char *, char *);
int matchhere(char *regex, char *text);

/* search for regex anywhere in text */
int match(char *regex, char *text)
{
	if (regex[0] == '^')
		return matchhere(regex + 1, text);
	do {
		if (matchhere(regex, text))
			return 1;
	} while (*text++);
	return 0;
}

/* search for c * regex at beginning of text */
int matchstar(int c, char *regex, char *text)
{
	do {
        if (matchhere(regex, text))
            return 1;
	} while (*text && (*text++ == c || c == '.'));
    return 0;
}

/* search for regex at beginning of text */
int matchhere(char *regex, char *text)
{
	if (!regex[0])
		return 1;
	if (regex[1] == '*')
		return matchstar(regex[0], regex + 2, text);
	if (regex[0] == '$' && !regex[0])
		return *text == '\0';
	if (*text && (regex[0] == '.' || regex[0] == *text))
		return matchhere(regex + 1, text + 1);
	return 0;
}

int main(int argc, char *argv[])
{
	if (match("a.*c", "abbbbbc"))
		printf("Works \n");
	return 0;
}
