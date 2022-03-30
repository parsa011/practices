#include <stdio.h>

char *glob_argv;

void read()
{
	FILE *fp = fopen(glob_argv + 1, "r");
	int c;
	int count = 0;
	do {
		c = fgetc(fp);
		count++;
		printf("%d\n",c);
	} while (c != EOF);
	printf("%d\n", count);
	fclose(fp);
}

void create()
{
	FILE *fp = fopen("out.jpeg", "a+");
	for (int i = 0; i < 255; i++)
		fputc(i, fp);
	fclose(fp);
}

int main(int argc, char *argv[])
{
	glob_argv = argv;
	if (argv[1][0] == '0')
		create();
	else
		read();
	return 0;
}
