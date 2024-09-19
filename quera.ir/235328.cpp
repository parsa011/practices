#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	int arr[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int current = 0;
	int people = 0;
	for (int i = 0; i < n; i++)
	{
		if (current + 1 + arr[i] > k)
			break;
		current += 1 + arr[i];
		people++;
	}
	cout << people << endl;

	return 0;
}
