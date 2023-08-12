#include <iostream>
#include <cstring>

using namespace std;

int smallest_in_array(int arr[], int len)
{
	int smallest_index = 0;
	for (int i = 0; i < len; i++) {
		if (arr[smallest_index] > arr[i]) {
			smallest_index = i;
		}
	}
	return smallest_index;
}

void array_shift_left(int arr[], int len, int index)
{
	for (int i = index; i < len - 1; i++) {
		arr[i] = arr[i + 1];
	}
}

void selection_sort(int arr[], int len)
{
	// iterate over elements in arr
	// find smallest
	// add smallest to new_arr
	// remove smallest from arr(shifting array to left)
	int new_arr[len];
	for (int i = 0; i < len; i++) {
		int smallest_index = smallest_in_array(arr, len - i);
		new_arr[i] = arr[smallest_index];
		array_shift_left(arr, len - i, smallest_index);
	}
	memcpy(arr, new_arr, sizeof(int) * len);
}

void array_print(int arr[], int len)
{
	for (int i = 0; i < len; i++) {
		cout << i << '\t';
	}
	cout << endl;
}

int main()
{
	int arr[] = {3, 4, 1, 4, 9, 3, 2};
	int len = sizeof(arr) / sizeof(arr[0]);
	selection_sort(arr, len);
	array_print(arr, len);
	return 0;
}
