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

int atoi(char *str)
{
	char *ptr = str;
}

int main()
{
	int input = 0;
	int len = int_len(input);
	printf("%d\n",len);
	return 0;
}
