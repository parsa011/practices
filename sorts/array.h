#include <stdio.h>

#define LEN(arr) (sizeof(arr) / sizeof(arr[0]))

static int arr[] = {1,4,5,6,9,8,2,3,12,7,19};
static int len = sizeof(arr) / sizeof(arr[0]);

static void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

static void print_array()
{
	printf("[");
	for (int i = 0; i < len; i++) {
		printf("\"%d\"", arr[i]);
		if (i + 1< len)
			printf(" ,");
	}
	printf("]\n");
}
