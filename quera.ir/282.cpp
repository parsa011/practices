#include <iostream>

using namespace std;

int main()
{
	int  n, sum = 1;
	cin >> n;
	for (int i = 2; i <= n / 2; i++) {
		if (n % i == 0)
			sum += i;
	}
	if (sum == n)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
