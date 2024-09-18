#include <iostream>
#include <string>

using namespace std;

int main()
{
	int c;
	cin >> c;
	for (int z = 0; z < c; z++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		int i = 0, j = 0;
		bool res = false;
		while (i < s1.length() && j < s2.length())
		{
			if (s1[i] == s2[j])
			{
				j++;
			}
			i++;
		}
		if (j == s2.length())
		{
			res = true;
		}
		if (!res)
		{
			// reverse search
			i = 0;
			j = s2.length() - 1;
			while (i < s1.length() && j >= 0)
			{
				if (s1[i] == s2[j])
				{
					j--;
				}
				i++;
			}
			if (j == -1)
			{
				res = true;
			}
		}
		if (res)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}
