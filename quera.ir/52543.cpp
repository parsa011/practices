#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int head = 0, tail = n - 1;
	while (head < tail)
	{
		cout << arr[tail--] << ' ';
		cout << arr[head++] << ' ';
	}
	if (n % 2 == 1)
		cout << arr[head];
	cout << endl;
	return 0;
}
