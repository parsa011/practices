#include <stdio.h>
#include <stdlib.h>

#define IS_LETTER(c) ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
#define IS_NUM(c) (c >= '0' && c <= '9')

int main(int argc,char *argv[])
{
	if (argc < 2) {
		printf("ENTER FILE NAME!!\n");
		return -1;
	}
	FILE *fp = fopen(argv[1],"r");
	if (!fp) {
		printf("FILE NOT FOUND!!\n");
		return -1;
	}
	int c = 0,indent = 0;
	int indented = 0;
	while ((c = fgetc(fp)) != EOF) {
    	if (IS_LETTER(c) || IS_NUM(c)) {
        	if (!indented) {
				indented = 1;
    			for (int i = 0;i < indent;i++) {
    				putchar('\t');
				}
        	}
			putchar(c);
    	} else if (c == '\n') {
			putchar(c);
			indented = 0;
		} else if (c == ':') {
			putchar(' ');
			putchar(':');
			putchar('\t');
		}
		else if (c == '{')
        	indent++;
    	else if (c == '}')
        	indent--;
	}
	return 0;
}
