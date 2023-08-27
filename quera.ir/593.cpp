#include <iostream>

using namespace std;

int digit_sum(int n)
{
	int res = 0;
	while (n > 0) {
		res += n % 10;
		n /= 10;
	}
	return res;
}

bool is_prime(int n)
{
	for (int i = 2; i <= n / 2; i++)
		if (n % i == 0)
			return false;
	return true;
}


int main()
{
	int n;
	cin >> n;
	int b = digit_sum(n);
	int current = 0;
	while (current < b) {
		n++;
		if (is_prime(n))
			current++;
	}
	cout << n << endl;
	return 0;
}
