#include <iostream>
#include <string>
#include <cctype> 

using namespace std;

int main()
{
	int c;
	cin >> c;
	string str;
	for (int i = 0; i <= c; i++)
	{
		getline(cin, str);

		bool last_was_space = true;
		for (int j = 0; j < str.length(); j++)
		{
			char current = str[j];
			if (isspace(current) || !isalpha(current))
			{
				cout << (char) current;
				last_was_space = isspace(current);
				continue;
			}
			if (last_was_space)
			{
				cout << (char) toupper(current);
				last_was_space = false;
			}
			else
			{
				cout << (char) tolower(current);
			}
		}
		cout << endl;
	}
	return 0;
}
