#include <iostream>

using namespace std;

bool contains(int arr[], int len, int n)
{
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == n)
			return true;
	}
	return false;
}

int main()
{
	int c;
	cin >> c;

	int fib[c];
	int cur = 1, last = 0;
	for (int i = 0; i < c; i++)
	{
		int temp = cur;
		cur += last;
		last = temp;
		fib[i] = cur;
	}

	for (int i = 1; i <= c; i++)
	{
		if (contains(fib, c, i))
			cout << '+';
		else
			cout << '-';
	}
	
	cout << endl;
	return 0;
}
