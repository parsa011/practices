#include <stdio.h>
#include <stdlib.h>

// S ::= Az | z
// A ::= xA | B
// B ::= y

// x*y?z regex :)))))

/*
  this is our lookahead character, when we run program, each time it 
  contains our next character :0
 */
char ch;

void error(char *msg)
{
  printf("Error - found character %c - %s\n", ch, msg);
  exit(1);
}

void b()
{
  if (ch == 'y')
    ch = getchar();
  else
    error("y expected");
}

void a()
{
  if (ch == 'x') {
    ch = getchar();
    a();
  }
  else
    b();
}

void s()
{
  if (ch == 'z')
    ch = getchar();
  else {
    a();
    if (ch != 'z')
      error("z expected");
  }
  printf("Success\n");
}

int main()
{
  ch = getchar();
  s();
  return 0;
}
