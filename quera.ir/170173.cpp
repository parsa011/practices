#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	string d, m, c;
	bool valid;
	for (int i = 0; i < t; i++)
	{
		cin >> d >> m >> c;
		valid = true;
		for (int j = 0; j < c.length(); j++)
		{
			if (c[j] == 'O')
				continue;
			if (c[j] == '+')
			{
				if (d.find("+") == string::npos && m.find("+") == string::npos)
				{
					valid = false;
					break;
				}
			}
			if (c[j] == 'A')
			{
				if (d.find("A") == string::npos && m.find("A") == string::npos)
				{
					valid = false;
					break;
				}
			}
			if (c[j] == 'B')
			{
				if (d.find("B") == string::npos && m.find("B") == string::npos)
				{
					valid = false;
					break;
				}
			}
		}
		if (valid)
		{
			cout << "valid" << endl;
		}
		else
		{
			cout << "invalid" << endl;
		}
	}
	return 0;
}
