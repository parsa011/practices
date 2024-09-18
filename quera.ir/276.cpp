#include <iostream>

using namespace std;

#define ll long long int

void find_longest(ll len, ll sum)
{
	if (sum == 0)
	{
		if (len == 1)
		{
			cout << 0;
			return;
		}
		cout << -1;
		return;
	}
	if (sum > len * 9)
	{
		cout << -1;
		return;
	}
	ll res[len];
	for (int i = 0; i < len; i++)
	{
		if (sum >= 9)
		{
			res[i] = 9;
			sum -= 9;
		}
		else
		{
			res[i] = sum;
			sum = 0;
		}
	}
	for (int i = 0; i < len; i++)
	{
		cout << res[i]; 
	}
}

void find_smallest(ll len, ll sum)
{
	if (sum == 0)
	{
		if (len == 1)
		{
			cout << 0;
			return;
		}
		cout << -1;
		return;
	}
	if (sum > len * 9)
	{
		cout << -1;
		return;
	}
	ll res[len];
	sum -= 1;
	for (int i = len - 1; i > 0; i--)
	{
		if (sum > 9)
		{
			res[i] = 9;
			sum -= 9;
		}
		else
		{
			res[i] = sum;
			sum = 0;
		}
	}
	res[0] = sum + 1;
	for (int i = 0; i < len; i++)
	{
		cout << res[i];
	}
}

int main()
{
    ll m, s;
	cin >> m >> s;
	find_smallest(m, s);
	cout << ' ';
	find_longest(m, s);
	cout << endl;
	return 0;
}
