#include <iostream>

using namespace std;

int main()
{
	int c;
	cin >> c;
	int arr[100] { 0 };
	int temp;
	for (int i = 0; i < c; i++)
	{
		cin >> temp;
		arr[temp - 1]++;
	}
	bool any = false;
	int res = 0;
	for (int i = 0; i < 100; i++)
	{
		if (arr[i] == 1)
		{
			res ^= (i + 1);
			any = true;
		}
	}
	cout << (any ? res : 0) << endl;
	return 0;
}
