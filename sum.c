#include <stdio.h>

long sum(long n)
{
	return (n + 1) * n / 2;
}

long recursion(int n)
{
	if (n == 1 || n == 0)
		return n;
	return n + recursion(n - 1);
}

long loop(long n)
{
	long res = 0;
	for (long i = 1; i <= n; i++)
		res += i;
	return res;
}

int main()
{
	printf("%ld\n", sum(5));
	return 0;
}
