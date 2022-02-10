#include "token.h"
#define extern_
#include "data.h"
#undef extern_
#include "decl.h"

void usage(char *name)
{
    printf("Usage : %s filename\n",name + 2);
    exit(0);
}

void panic(char *msg)
{
    printf("%s\n",msg);
    exit(0);
}

void open_file(char *name)
{
    file = fopen(name,"r");
    if (!file) {
        panic("File not found");
    }
}

void close()
{
    fclose(file);
}

void init()
{
    Line = 1;
    Putback = 0;
}

int main(int argc,char *argv[])
{
    if (argc < 2)
        usage(argv[0]);
    init();
    open_file(argv[1]);
    do {
        scan(&Token);
        printf("%d\n",Token.intvalue);
    } while (Token.token != T_EOF);
    struct ASTnode *n = binexpr(0);
	close();
	return 0;
}

