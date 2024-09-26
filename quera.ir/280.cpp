#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int nums[3];
	cin >> nums[0] >> nums[1] >> nums[2];
	sort(begin(nums), end(nums));
	if (pow(nums[0], 2) + pow(nums[1], 2) == pow(nums[2], 2))
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
	return 0;
}
