#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	if (a == 0 && b == 0) {
		cout << "infinitie\n";
	} else if (a == 0 && b != 0)
		cout << "invalid\n";
	else if (b == 0 && a != 0)
		cout << "unique\n";
	else
		cout << "unique\n";
	return 0;
}
