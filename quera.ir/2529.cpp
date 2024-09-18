#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int c;
	cin >> c;
	int longest = 0;
	string str;
	for (int i = 0; i < c; i++)
	{
		cin >> str;

		int arr[26] { 0 };
		for (int j = 0; j < str.length(); j++)
		{
			arr[str[j] - 'a']++;
		}

		int temp = 0;
		for (int j = 0; j < 26; j++)
		{
			if (arr[j] >= 1)
			{
				temp++;
			}
		}
		if (temp > longest)
		{
			longest = temp;
		}
	}

	cout << longest << endl;
	return 0;
}
