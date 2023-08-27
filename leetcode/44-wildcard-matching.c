#include <stdio.h>
#include <stdbool.h>

bool match_next(char *str, char *pattern)
{
	if (*str == '\0' || *pattern == '\0')
		return false;
	return *(str + 1) == *(pattern + 1);
}

bool isMatch(char *str, char *pattern)
{
	if (*str == '\0' && *pattern == '\0')
		return true;
	if (*pattern == '*') {

		if (*(pattern + 1) == '*')
			pattern++;
		if (*str == '\0' && *(pattern + 1) == '\0')
			return true;
		printf("%c\t%c\n", *str, *pattern);
		if (!match_next(str, pattern))
			return isMatch(str + 1, pattern);
		return isMatch(str, pattern + 1);

	} else if (*pattern == '?') {

		if (*str == '\0')
			return false;
		return isMatch(str + 1, pattern + 1);

	} else if (*pattern != *str)
		return false;
	return isMatch(str + 1, pattern + 1);
}

int main()
{
	char *str1 = "adcebd";
	char *pattern1 = "*a*b";
	printf("first test : %d\n", isMatch(str1, pattern1));
	char *str2 = "aa";
	char *pattern2 = "*";
	printf("second test : %d\n", isMatch(str2, pattern2));
	char *str3 = "ac";
	char *pattern3 = "?c";
	printf("third test : %d\n", isMatch(str3, pattern3));
	return 0;
};
