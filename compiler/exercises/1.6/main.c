#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

void expression();
void expression_prime();
void term();
void term_prime();
void factor();
void next();

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
    OPEN_PARENTHESIS = 1,
    CLOSE_PARENTHESIS,
    PLUS,
    MINUS,
    STAR,
    DIV,
    NUMBER,
    POW,
    SEMI,
    WHITESPACE,
    BAD,
    EOI
};

void die(char *);
void open_file(char *);
int readl();

void reset_token();

// lexer stuff
void next();
bool match();

// current lexer and token
lexer *lex;
token *tok;

void next()
{
  reset_token();
  if (!lex->buf || lex->offset >= lex->length - 1) {
    lex->offset = 0;
    if (readl() == EOF) {
      tok->type = EOI;
      return;
    } 
  }
  char *p = lex->buf + lex->offset;
  if (*p) {
    tok->len = 1;
    tok->lineno = lex->lineno;

    while (isspace(*p)) {
      p++;
      lex->offset++;
    }

    tok->value[0] = *p;
    tok->value[1] = 0;
    switch (*p) {
      case ';' :
        tok->type = SEMI;
        break;
      case '(' :
        tok->type = OPEN_PARENTHESIS;
        break;
      case ')' :
        tok->type = CLOSE_PARENTHESIS;
        break;
      case '+' :
        tok->type = PLUS;
        break;
      case '-' :
        tok->type = MINUS;
        break;
      case '/' :
        tok->type = DIV;
        break;
      case '*' :
        tok->type = STAR;
        break;
      case '^' :
        tok->type = POW;
        break;
      case '\n':
      case '\t':
        tok->type = WHITESPACE;
        break;
      default :
        if (isdigit(*p)) {
          char temp[10];
          int index = 1;
          temp[0] = *p++;
          while (isdigit(*p)) {
            temp[index++] = *p++;
            lex->offset++;
          }
          temp[index] = 0;
          strcpy(tok->value,temp);
          tok->type = NUMBER;
          tok->val = atoi(temp);
          tok->len = strlen(temp);
        } else {
          tok->type = BAD;
        }
        break;
    }
  }
  lex->offset++;
}

bool match(int type)
{
  return tok->type == type;
}

void reset_token()
{
  tok->lineno = tok->len = tok->val = tok->type = 0;
  tok->value[0] = '\0';
}

void die(char *msg)
{
  printf("%s\n",msg);
  exit(0);
}

// actully this is a little startup for program XDD
void open_file(char *name)
{
  tok = malloc(sizeof(token));
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
  lex->lineno++;
  int read = getline(&lex->buf,&lex->length,lex->file);
  lex->length = strlen(lex->buf);
  return read;
}

void expression()
{
    term();
    expression_prime();
}

void expression_prime()
{
    if (match(PLUS)) {
        factor();
        expression_prime();
    }
}

void term()
{
    factor();
    term_prime();
}

void term_prime()
{
    if (match(STAR)) {
        factor();
        term_prime();
    }
}

void factor()
{
    next();
    if (match(NUMBER)) {
        next();
    } else if (match(OPEN_PARENTHESIS)) {
        expression();
        if (match(CLOSE_PARENTHESIS))
            next();
        else
            printf("%d : Unclosed Parenthesis\n",lex->lineno);
    } else
        printf("%d : Number or Expression expected <'%s'>\n",lex->lineno,tok->value);
}

void parse()
{
    expression();
    if (match(SEMI))
        next();
    else
        printf("%d : Missed semi\n",lex->lineno);
    if (!match(EOI))
        parse();
}

int main(int argc,char *argv[])
{
  if (argc < 2) {
    die("enter file name");
  }
  open_file(argv[1]);
  parse();
  //do {
  //    next();
  //    printf("<'%s'>\n",tok->value);
  //} while (!match(EOI));
  return 0;
}
