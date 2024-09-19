#include <iostream>
#include <cmath>

using namespace std;

int digit_count(int n)
{
	return log10(n) + 1;
}

int main()
{
	int k;
	cin >> k;

	int generated_count = 0, dg = 0, res = 0;
	for (int i = 1; i < 5000; i++)
	{
		dg = digit_count(i);
		generated_count += dg;
		if (generated_count >= k)
		{
			int temp = i;
			while (generated_count >= k)
			{
				res = temp % 10;
				temp /= 10;
				generated_count--;
			}
			break;
		}
	}
	cout << res << endl;
	return 0;
}
