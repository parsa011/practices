#include <iostream>

using namespace std;

int binary_search(int arr[], int len, int x)
{
	int low = 0, high = len - 1, mid, index = -1, bf = 0;
	while (low <= high && !bf)
	{
		mid = (low + high) / 2;
		if (arr[mid] > x) {
			high = mid;
		} else if (arr[mid] < x) {
			low = mid + 1;
		} else {
			index = mid;
			bf = 1;
		}
	}
	return index;
}

int main()
{
	int arr[] = { 10, 20, 30, 40, 50 };
	int dest = 50;
	int dest2 = 30;
	int index = binary_search(arr, 5, dest);
	int index2 = binary_search(arr, 5, dest2);	
	cout << "index is : " << index << endl;
	cout << "index is : " << index2 << endl;
	return 0;
}
