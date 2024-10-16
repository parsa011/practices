#include <iostream>

using namespace std;

int main()
{
	int a, b, l;
	cin >> a >> b >> l;
	int half = l / 2;
	int res = a * half + b * half;
	if (l % 2 == 1)
	{
		res += a;
	}
	cout << res << endl;

	return 0;
}
