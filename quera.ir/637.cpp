#include <iostream>
#include <algorithm>

using namespace std;

#define CHAR_TO_INT(n) n - '0'
#define INT_TO_CHAR(n) to_string(n)

void big_int_add(string &str, string n)
{
	if (str == "" || n == "")
	{
		str = str + n;
		return;
	}

	string res = "";
	string bigger = str.length() > n.length() ? str : n;
	string smaller = bigger == n ? str : n;
	
	int i = bigger.length() - 1, j = smaller.length() - 1;
	int current = 0, carry = 0;
	
	while (i >= 0)
	{
		current = CHAR_TO_INT(bigger[i]) + carry;
		if (j >= 0)
			current += CHAR_TO_INT(smaller[j--]);
		carry = current / 10;
		current %= 10;
		res += INT_TO_CHAR(current);
		i--;
	}

	if (carry)
		res += INT_TO_CHAR(carry);

	reverse(res.begin(), res.end());
	str = res;
}

int main()
{
	int t;
	cin >> t;
	string res = "", n;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		big_int_add(res, n);
	}
	cout << res << endl;
	return 0;
}
