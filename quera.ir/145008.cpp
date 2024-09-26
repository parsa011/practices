#include <iostream>

using namespace std;

int main()
{
	int c;
	cin >> c;
	string str;
	cin.ignore();
	getline(cin, str);
	char other_one;
	bool res = true;
	for (int i = 0; i < c; i++)
	{
		other_one = str[i] == 'S' ? 'F' : 'S';
		if (str[i + c] != other_one)
		{
			res = false;
			break;
		}
	}
	cout << (res ? "YES" : "NO") << endl;
	return 0;
}

