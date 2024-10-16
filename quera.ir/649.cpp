#include <iostream>

using namespace std;

bool is_prime(int n)
{
	for (int i = 2; i <= n / 2; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int n, b;
	cin >> n >> b;
	bool print_comma = false;
	for (int i = n + 1; i < b; i++)
	{
		if (is_prime(i))
		{
			if (print_comma)
				cout << ",";
			cout << i;
			print_comma = true;
		}
	}
	cout << endl;
	return 0;
}
