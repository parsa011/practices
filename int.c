#include <stdio.h>

int int_len(int n)
{
	if (n < 0)
		n = -n;
	int len = 1;
	while (n / 10) {
		n /= 10;
		len++;
	}
	return len;
}

/*
 * Assume given string is valid int string
 */
int atoi(char *str)
{
	char *ptr = str;
	int sign = 1;
	if (*ptr == '-') {
		sign = -1;
		ptr++;
	}
	int res = 0;
	while (*ptr) {
		res = res * 10 + (*ptr++ - '0');
	}
	return res * sign;
}

int main()
{
	int input = 0;
	int len = int_len(input);
	printf("%d\n",len);
	char *int_str = "-123";
	printf("%d\n", atoi(int_str));
	return 0;
}
