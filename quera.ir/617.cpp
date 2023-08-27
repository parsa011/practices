#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	long n;
	cin >> n;
	string str = to_string(n);
	int l = 0, r = str.length() - 1;
	bool its = true;
	while (r > l) {
		if (str[l] != str[r]) {
			its = false;
			break;
		}
		r--;
		l++;
	}
	if (its)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
