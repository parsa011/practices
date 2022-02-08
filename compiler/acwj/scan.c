#include "defs.h"
#include "data.h"

// Putback an unwantd character
static void putback(int c)
{
    Putback = c;
}

// Get the next character from the input file.
static int next()
{
    int c;
    if (Putback) {
        c = Putback;
        Putback = 0;
        return c;
    }

    c  = fgetc(Infile);
    if (c == '\n')
        Line++;
    return c;
}

// Return the position of character c
// in string s, or -1 if c not found
static int chrpos(char *s, int c) {
  char *p;

  p = strchr(s, c);
  return (p ? p - s : -1);
}

// Skip past input that we don't need to deal with, 
// i.e. whitespace, newlines. Return the first
// character we do need to deal with.
static int skip()
{
    int c;
    do
        c = next();
    while (isspace(c));
    return c;
}

// Scan and return an integer literal
// value from the input file. Store
// the value as a string in Text.
static int scanint(int c) {
  int k, val = 0;

  // Convert each character into an int value
  while ((k = chrpos("0123456789", c)) >= 0) {
    val = val * 10 + k;
    c = next();
  }

  // We hit a non-integer character, put it back.
  putback(c);
  return val;
}

int scan(struct token *t)
{
    int c;
    c = skip();
    // Determine the token based on
    // the input character
    switch (c) {
        case EOF:
          return (0);
        case '+':
          t->token = T_PLUS;
          break;
        case '-':
          t->token = T_MINUS;
          break;
        case '*':
          t->token = T_STAR;
          break;
        case '/':
          t->token = T_SLASH;
          break;
        default:
            // If it's a digit, scan the
            // literal integer value in
            if (isdigit(c)) {
              t->intvalue = scanint(c);
              t->token = T_INTLIT;
              break;
            }

            printf("Unrecognised character %c on line %d\n", c, Line);
            exit(1);    
    }
    // We found a token
    return (1);
}
