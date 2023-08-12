#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		int as_int = str.at(i) - '0';
		cout << as_int << ": ";
		for (int j = 0; j < as_int; j++) {
			cout << as_int;
		}
		cout << endl;
	}
	return 0;
}
