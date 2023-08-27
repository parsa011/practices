#include <iostream>
#include <string.h>

using namespace std;

int str_repeat_time(string str, string key)
{
	int c = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == key[0]) {
			int same = 1;
			for (int j = 1; j < key.length(); j++) {
				if (str[i + j] == key[j])
					same++;
				else
					break;
			}
			if (same == key.length()) {
				c++;
				i += key.length() - 1;
			}
		}
	}
	return c;
}

void copy(string key, int count, string &str)
{
	int index = 0;
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < key.length(); j++) {
			str[index++] = key[j];
		}
	}
}

int compare(string key, string str)
{
	return str.compare(key) == 0 ? 1 : 0;
}

int substr(string key, int count, string str)
{
	return str_repeat_time(str, key) == count ? 1 : 0;
}

int attach(string key, int count, string second, string str)
{
	key += second;
	return count == str_repeat_time(str, key) ? 1 : 0;
}

int length(int len, string str)
{
	return len == str.length() ? 1 : 0;
}

int main()
{
	int goodness = 0;
	string str, command;
	cin >> str;
	copy("hi", 3, str);
	cout << str << endl;
	goodness += compare("hihihiintamrinkheilisadast.hooorrraaaaa", str);
	goodness += substr("aaa", 3, str);
	goodness += attach("hi", 2, "in", str);
	goodness += length(39, str);
	cout << goodness << endl;
	return 0;
}
