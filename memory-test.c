#include <stdlib.h> 

int main()
{
	int i = 0;
	for (; i < 1000000; i++)
		malloc(32);
	return 0;
}
