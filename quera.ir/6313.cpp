#include <iostream>

using namespace std;

int main()
{
	int n;
	while (true) {
		cin >> n;
		if (n == 0)
			break;
		if (n >= 1000000 && n <= 5000000) {
			cout << n - (n / 100 * 10) << endl;
		} else if (n > 5000000) 
			cout << n - (n / 100 * 20) << endl;
		else
			cout << n << endl;
	}
	return 0;
}
