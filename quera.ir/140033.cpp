#include <iostream>

using namespace std;

#define CHAR_TO_INT(ch) ch - 'a' 

int main()
{
	int alphabet[26] = { 0 };
	alphabet[CHAR_TO_INT('a')] = alphabet[CHAR_TO_INT('o')] = alphabet[CHAR_TO_INT('i')] = alphabet[CHAR_TO_INT('e')] = alphabet[CHAR_TO_INT('u')] = 1;
	int res = 0;
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (alphabet[CHAR_TO_INT(str[i])])
			res++;
	}

	cout << res << endl;
	return 0;
}
