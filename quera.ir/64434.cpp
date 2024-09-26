#include <iostream>

using namespace std;

int main()
{
	int n, m, turn;
	char ch[2] = {'X', '.'};
	cin >> n >> m;

	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < n; k++)
		{
			turn = i % 2 == 0;
			for (int j = 0; j < m * 3; j++)
			{
				if (j % m == 0)
					turn ^= 1;
				cout << ch[turn];
			}
			cout << endl;
		}
	}
	return 0;
}
