#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int pow = 1;
	do {
		pow *= 2;
	} while (pow <= n);
	cout << pow << endl;
	return 0;
}
