#include <stdio.h>

#define NAME_LEN 80

int read_line(char *buffer, int max)
{
	char *ptr = buffer;
	int len = 0;
	char c = getchar();
	while (len <= max && c != 0 && c != '\n') {
		*(ptr + len++) = c;
		c = getchar();
	}
	return len;
}

int main()
{
	char name[NAME_LEN];
	int len = read_line(name, NAME_LEN);
	printf("%s : %d\n", name, len);
	return 0;
}
