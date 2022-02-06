#include <stdio.h>
#include <stdlib.h>

typedef struct lexer_t {
	  FILE *file;
    int lineno;
    int offset;
    char *buf;  // current line
    size_t length; // current line length
} lexer;

typedef struct token_t {
	char value[32];
    int val;
    int type;
    int lineno;
    int len;
} token;

enum {
	OPEN_PARENTHESIS,
    CLOSE_PARENTHESIS,
    PLUS,
    MINUS,
    STAR,
    DIV,
    NUMBER,
    POW,
    BAD
};

void die(char *);
void open_file(char *);
int readl();

// current lexer and token
lexer *lex;
token *tok;

void die(char *msg)
{
  printf("%s\n",msg);
  exit(0);
}

void open_file(char *name)
{
  lex = malloc(sizeof(lexer));
  lex->file = fopen(name,"r");
  if (!lex->file) {
    die("file not found");
  }
}

int readl()
{
  if (!lex)
    die("first run a lexer");
  return getline(&lex->buf,&lex->length,lex->file) == EOF;
}

int main(int argc,char *argv[])
{
  if (argc < 2) {
    die("enter file name");
  }
  open_file(argv[1]);
  return 0;
}
