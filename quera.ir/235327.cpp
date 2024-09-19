#include <iostream>

using namespace std;

int main()
{
	int c;
	cin >> c;
	int a, b, h;
	for (int i = 0; i < c; i++)
	{
		cin >> a >> b >> h;
		int current = 0;
		int step = 0;
		while (true)
		{
			current += a;
			step++;
			if (current >= h)
				break;
			current -= b;
		}
		cout << step << endl;
	}
	return 0;
}
