#include <iostream>
#include <cmath>

using namespace std;

#define ulli unsigned long long int

ulli digit_count(ulli n)
{
	return log10(n) + 1;
}

ulli do_sum(ulli n)
{
	ulli res = 0;
	while (n > 0)
	{
		res += n % 10;
		n /= 10;
	}
	return res;
}

int main()
{
	ulli n;
	cin >> n;
	ulli res = n;
	do {
		res = do_sum(res);
	} while (digit_count(res) > 1);
	cout << res << endl;
	return 0;
}
