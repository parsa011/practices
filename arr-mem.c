#include <stdio.h>

int main()
{
	long ages[5] = { 10, 11, 12, 13, 14 };
	printf("age is %d\n", *(ages + 3));
	for (int i = 0; i < 5; i++) {
		printf("0x%x\n", ages + i);
	}
	return 0;
}
