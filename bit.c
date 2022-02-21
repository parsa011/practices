#include <stdio.h>

int main()
{
	int value=1; /* value to test, starts at first (lowest) bit */
	for (int bit=0;bit<100;bit++) {
		printf("at bit %d, value is %d\n", bit, value);
		value=value+value; /* moves over by one bit */
		if (value==0) break;
	}
	return 0;
}
