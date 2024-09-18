#include <iostream>

using namespace std;

int main()
{
	int c;
	cin >> c;
	for (int i = 1; i <= c; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cout << i * j << ' ';
		}
		cout << endl;
	}
	return 0;
}
