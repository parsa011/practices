#include <stdio.h>

void sort(int array[], int len)
{
	int i = 0;
	while (i < len - 1) {
		if (array[i + 1] < array[i]) {
			array[i + 1] += array[i];
			array[i] = array[i + 1] - array[i];
			array[i + 1] = array[i + 1] - array[i];
			i = 0;
		} else
			i++;
	}
}

int min_sum(int passed[], int length)
{
	sort(passed, length);
	for (int i = 0; i < 4; i++) {
		printf("%d\n", passed[i]);
	}
	int res = 0;
	for (int i = 0, j = length - 1; i < j; i++, j--) {
		printf("%d * %d\n", passed[i], passed[j]);
		res += passed[i] * passed[j];
	}
	return res; 
}

int main()
{
	int arr[] = { 5, 4, 2, 3};
	printf("%d\n", min_sum(arr, 4));
	return 0;
}
