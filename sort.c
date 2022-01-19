#include <stdio.h>

#define ARRAY_LENGTH(n) (sizeof(n) / sizeof(n[0]))

int main(int argc,char *argv[]) {
	int numbers[] = 
		{123,234,32,5,654,12,4526,45,23,25,345
		,2345,346,34,4,23,5,3,34,34,34,2356,57,4345,
		23,34,34342,234,23,5,24,2352,243,
		234,234,234,2352,5,4,4,234,23,2523,24,4234,234,
		234,25,65,23,42,2323,42,6,345,234,12,3436,456,4
			,234,6534,53,4656,756,72,2,1,1,1,1,34,6,4545,6234,235,634,235,
		5324,5234,634,545,345489,9,120,10,20,23,4,2};
	int len = ARRAY_LENGTH(numbers);
	int i = 0;
	while (i < len - 1) {
		if (numbers[i + 1] < numbers[i]) {
			numbers[i + 1] += numbers[i];
			numbers[i] = numbers[i + 1] - numbers[i];
			numbers[i + 1] = numbers[i + 1] - numbers[i];
			i = 0;
		} else
			i++;
	}
	for (int i = 0;i < len;i++) {
		printf("%d\t",numbers[i]);
	}
	putchar('\n');
	return 0;
}
