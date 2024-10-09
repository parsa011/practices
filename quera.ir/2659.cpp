#include <iostream>

using namespace std;

string read_line()
{
	string str = {};
	char c = getchar();
	while (c != '\n')
	{
		str += c;
		c = getchar();
	}
	return str;
}

int main()
{
	int c;
	cin >> c;
	string s1 = {}, s2 = {};
	cin.ignore();
	getline(cin, s1);
	getline(cin, s2);
	int res = 0;
	for (int i = 0; i < c; i++)
	{
		if (s1[i] != s2[i])
			res++;
	}
	cout << res << endl;
	return 0;
}
