#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[])
{
    FILE *fp = fopen(argv[1],"r");
    if (!fp) {
		fprintf(stderr,"File not found\n");
		return 0;
    }
	char *line = NULL;
	char *text = argv[2];
	int text_len = strlen(text);
	size_t len = 0;
	size_t read = 0;
	int linen = 1; // line number
	while ((read = getline(&line,&len,fp)) != EOF) {
    	char *pos = strstr(line,text);
    	if (pos) {
			printf("%d  ",linen);
        	while (*line) {
				// highlight first letter of word
            	if (pos == line) {
					printf("\x1b[31m%c\x1b[0m",*line);
            	} else {
              		putchar(*line);
                }
                line++;
        	}
    	}
		linen++;
	}
}
