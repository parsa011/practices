#include <iostream>

using namespace std;

int main()
{
	string res = "", str;
	for (int i = 0; i < 5; i++)
	{
		getline(cin, str);
		if (str.find("HAFEZ") != string::npos || str.find("MOLANA") != string::npos)
			res += to_string(i + 1) + " ";
	}
	if (!res.empty())
		res.pop_back();
	cout << (res == "" ? "NOT FOUND!" : res) << endl;
	return 0;
}
