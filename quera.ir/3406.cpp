#include <iostream>

using namespace std;

int reverse(int n)
{
	int res = 0;
	while (n > 0)
	{
		res = res * 10 + n % 10;
		n /= 10;
	}
	return res;
}

int main()
{
	int n1, n2;
	cin >> n1 >> n2;
	int nr1 = reverse(n1), nr2 = reverse(n2);
	if (nr1 > nr2) {
		cout << n2 << " < " << n1 << endl;
	} else if (nr2 > nr1) {
		cout << n1 << " < " << n2 << endl;
	} else {
		cout << n1 << " = " << n1 << endl;
	}
	return 0;
}
