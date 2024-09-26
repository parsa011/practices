#include <iostream>

using namespace std;

int main()
{
	string str;
	cin >> str;
	cout << "saal:" << str.substr(0, 2) << endl;
	cout << "maah:" << str.substr(2, 2) << endl;
	return 0;
}
