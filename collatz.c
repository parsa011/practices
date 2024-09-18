sdf#include <stdio.h>

int main(int argc, char *argv[])
{
   long number;
   scanf("%ld", &number);
   
   while (number > 1) {
     if (number % 2 == 0) {
       number = number / 2;
     } else
       number = number * 3 + 1;
     printf("%ld\n", number);
   }
   
   return 0;
}
