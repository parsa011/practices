#include <iostream>

using namespace std;

#define max(a, b) a > b ? a : b

int main()
{
	int t, n, res = 0;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		res = max(n, res);
	}
	cout << res << endl;
}
