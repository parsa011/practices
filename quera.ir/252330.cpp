#include <iostream>
#include <vector>

using namespace std;

string read_line()
{
	string res = "";
	char ch = getchar();
	while (ch != '\n') {
		res += ch;
		ch = getchar();
	}
	return res;
}

int main()
{
	int t, c, res, index;
	cin >> t;
	ios_base::sync_with_stdio(false); cin.tie(0);
	vector<int> outputs;
	string stu;
	for (int i = 0; i < t; i++) {
		cin >> c;
		int max_chars[26] = { 0 };
		res = 0;
		for (int j = 0; j < c; j++)
		{
			stu = read_line();
			int arr[26] = { 0 };
			for (int k = 0; k < stu.length(); k++) {
				index = stu[k] - 'a';
				max_chars[index] = max(max_chars[index], ++arr[index]);
			}
		}
		for (int x = 0; x < 26; x++)
			res += max_chars[x];
		outputs.push_back(res);
	}
	for (int i = 0; i < outputs.size(); i++)
        cout << outputs[i] << endl;
	return 0;
}
