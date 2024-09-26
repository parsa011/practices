#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	while (n % m != 0)
	{
		n++;
	}
	cout << n / m << endl;
	return 0;
}
