#include <stdio.h>

int get_pow(int n)
{
	int t = 1;
	while (1) {
		t *= 2;
		if (t > n) {
			t /= 2;
			return t;
		}
	}
}

void binary(int n)
{
	int pow = get_pow(n);
	while (pow > 0) {
		if (pow > n)
			putchar('0');
		else {
			putchar('1');
			n -= pow;
		}
		pow /= 2;
	}
	putchar('\n');
}

int main()
{	
	int c;
    while (scanf("%d", &c) != EOF)
    	binary(c);
	return 0;
}
