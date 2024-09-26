#include <iostream>

using namespace std;

bool is_equal(int i, int j, int b, int y)
{
	if (i < 3)
	{
		return i * j == b && y == 0;
	}
	return ((i - 2) * (j - 2)) == y;
}

int main()
{
	int b, y, sum;
	cin >> b >> y;
	sum = b + y;
	bool founded = false;
	int res[2];
	for (int i = 0; i < sum; i++)
	{
		if (founded)
			break;
		for (int j = 0; j < sum / 2; j++)
		{
			if (i * j > sum)
				break;
			if (is_equal(i, j, b, y))
			{
				res[0] = i;
				res[1] = j;
				founded = true;
			}
		}
	}
	cout << res[1] << ' ' << res[0] << endl;
	return 0;
}
