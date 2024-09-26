#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int);
void create(int, int);
int int_len(int);

bool is_prime(int n)
{
	for (int i = 2; i <= n / 2; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

void create(int n, int len)
{
	if (!is_prime(n))
		return;
	if (int_len(n) == len)
	{
		cout << n << endl;
		return;
	}

	create(n * 10 + 1, len);
	create(n * 10 + 3, len);
	create(n * 10 + 5, len);
	create(n * 10 + 7, len);
	create(n * 10 + 9, len);
}

int int_len(int n)
{
	return log10(n) + 1;
}

int main()
{	
	int c;
	cin >> c;

	create(2, c);
	create(3, c);
	create(5, c);
	create(7, c);
	create(9, c);
					
	
	return 0;
}
