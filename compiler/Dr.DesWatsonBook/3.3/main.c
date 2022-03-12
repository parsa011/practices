#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define IS_DIGIT(c) (c >= '0' && c <= '9')
#define CHAR_TO_DIGIT(c) (c - '0')

double lex_float(char *s)
{
    double val = 0.0, pow = 1.0;
    int sign;

    while (isspace(*s))
        s++;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
        s++;
    while (IS_DIGIT(*s)) {
        val = val * 10.0 + CHAR_TO_DIGIT(*s++);
    }
    if (*s == '.')
        s++;
    while (IS_DIGIT(*s)) {
        val = val * 10.0 + CHAR_TO_DIGIT(*s++);
        pow *= 10.0;
    }
    printf("%f \t %f\n", val, pow);
    return sign * val / pow;
}

int main(int argc, char *argv[])
{
    char s[] = "12934.99999";
    double f = lex_float(s);
    printf("%f\n", f);
    return 0;
}
