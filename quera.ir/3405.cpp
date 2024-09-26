#include <iostream>

using namespace std;

int main()
{
	int arr[1000];
	int top = 0;

	int c;
	while (true)
	{
		cin >> c;
		if (c == 0)
			break;
		arr[top++] = c;
	}

	for (int i = top - 1; i >= 0; i--)
	{
		cout << arr[i] << endl;
	}
	return 0;
}
