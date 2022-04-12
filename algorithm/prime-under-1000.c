#include <stdio.h>

#define N 1000
int main()
{
	int i, j, n[N + 1];
    for (n[1] = 0, i = 2; i <= N; i++)
    	n[i] = 1;
    for (i = 2; i <= N / 2; i++) {
    	for (j = 2; j <= N / i; j++)
        	n[i * j] = 0;
    }
    for (i = 1; i <= N; i++)
    	if (n[i])
        	printf("%4d\t", i);
    putchar('\n');
	return 0;
}
