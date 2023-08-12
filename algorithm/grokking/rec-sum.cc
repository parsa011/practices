#include <iostream>

using namespace std;

int sum(int arr[], int len)
{
	if (len == 0)
		return 0;
	return arr[0] + sum(arr + 1, len - 1);
}

int main()
{
	cout << sum(new int[]{1, 2, 3, 4, 5}, 5) << endl;
	return 0;
}
