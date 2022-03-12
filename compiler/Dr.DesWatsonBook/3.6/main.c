#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

FILE *fp;
int lineno = 1;
int count = 0;

void open_file(char *name)
{
    fp = fopen(name, "r");
    if (!fp) {
        printf("File Not Found\n");
        exit(-1);
    }
}

char read_char()
{
    assert(fp);
    char c = fgetc(fp);
    if (c == '\n')
        lineno++;
    return c;
}

char skip()
{
    char c;
    while (isspace((c = read_char())))
        ;
    return c;
}

/*
 * we just tried to keep it simple as possible , we dont store any string (like keywords and ...)
 * if we found 'i' , we will be sensitive for next char , but consier that we have to check last char to be a white space
 * and if next char is 'f', so we have found if statement , but will have to be sure that next char is open parenthesis.
 * and we don check if we are int string or no, extra task :)))
 */
void count_if_statements()
{
    int found = 0;
    int c;
    do {
        c = skip();
        switch (c) {
            case '(' :
                if (found) {
                    count++;
                    found = 0;
                }
                break;
            case 'i' :
                /* be careful here, dont use of skip , because we have to care about whitespaces */
                c = read_char();
                if (c == EOF)
                    break;
                if (c == 'f')
                    found = 1;
                else
                    found = 0;
        }
    } while (c != EOF);
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Enter File name\n");
        exit(-1);
    }
    open_file(argv[1]);
    count_if_statements();
    printf("We have %d 'if' statement in '%s' file\n", count, argv[1]);
    fclose(fp);
    return 0;
}
