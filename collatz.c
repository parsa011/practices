#include <stdio.h>

int main(int argc, char *argv[])
{
   int number;
   scanf("%d", &number);
   
   while (number > 1) {
     if (number % 2 == 0) {
       number = number / 2;
     } else
       number = number * 3 + 1;
     printf("%d\n", number);
   }
   
   return 0;
}
