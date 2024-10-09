#include <iostream>

using namespace std;

int linear_search(int arr[], int len, int x)
{
	int index = -1, bf = 0, i = 0;
	while (i < len && !bf)
	{
		if (arr[i] == x) {
			index = i;
			bf = 1;
		}
		i++;
	}
	return index;
}

int main()
{
	int arr[] = { 10, 20, 30 };
	int dest = 20;
	int index = linear_search(arr, 3, dest);
	cout << "index is : " << index << endl;
	return 0;
}
