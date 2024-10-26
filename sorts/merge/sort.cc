#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

void sort(int arr[], int len)
{
	if (len == 1)
		return;
    if (len == 2)
    {
        if (arr[0] > arr[1]) {
            int temp = arr[0];
            arr[0] = arr[1];
            arr[1] = temp;
        }
        return;
    }
    int left_len = floor(len / 2.0f);
    int left_arr[left_len];
	memcpy(left_arr, arr, left_len * sizeof(int));
	
	int right_len = round(len / 2.0);
	int right_arr[right_len];
	memcpy(right_arr, arr + left_len, right_len * sizeof(int));

	sort(left_arr, left_len);
	sort(right_arr, right_len);

	int l = 0, r = 0, i = 0;
	while (l < left_len || r < right_len) {
		if (l >= left_len) {
			arr[i] = right_arr[r++];
		} else if (r >= right_len) {
			arr[i] = left_arr[l++];
		} else {
			if (left_arr[l] < right_arr[r]) {
				arr[i] = left_arr[l++];
			} else
				arr[i] = right_arr[r++];
		}
		i++;
	}
}

int main()
{
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	int len = sizeof(arr) / sizeof(arr[0]);
    sort(arr, len);
	for (int i = 0; i < len; i++) {
		cout << arr[i] << '\t';
	}
	cout << endl;
    return 0;
}
