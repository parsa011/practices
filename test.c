#include <stdio.h>
#include <math.h>
#include <limits.h>


int rev(int n)
{
	int res = 0;
	while (n) {
		if (((long)res * 10 + (n % 10) > INT_MAX))
			return -1;
		res = res * 10 + (n % 10);
		n /= 10;
	}
	return res;
}

int main()
{
	printf("%d\n", rev(1221));
	return 0;
}
