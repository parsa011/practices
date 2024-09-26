#include <iostream>

using namespace std;

int main()
{
	int n, k, last = -1, res = 0;
	cin >> n;
	cin >> last;
	for (int i = 1; i < n; i++)
	{
		cin >> k;
		if (k != last)
			res++;
		last = k;
	}
	cout << res << endl;
	return 0;
}
