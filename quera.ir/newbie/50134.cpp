#include <iostream>

using namespace std;

int main()
{
	int x;
	cin >> x;
	for (int i = 0; i < x; i++) {
		int a, b ,c;
		cin >> a >> b >> c;
		a -= c;
		bool founded = false;
		for (int j = 0; j < a; j++) {
			if (b * j == a) {
				founded = true;
				break;
			}
		}
		if (founded) {
			cout << "YES\n";
		} else
			cout << "NO\n";
	}
	return 0;
}
