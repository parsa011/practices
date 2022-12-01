#include "array.h"

void sort(int arr[], int arr_len)
{
	int j = 0;
	for (int i = 0; i < arr_len; i++) {
		j = i;
		while (j > 0 && arr[j - 1] > arr[j]) {
			swap(&arr[j], &arr[j - 1]);
			j--;
		}
	}
}

int main()
{
	sort(arr, len);
	print_array();
	return 0;
}
