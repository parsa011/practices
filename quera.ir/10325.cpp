#include <iostream>

using namespace std;

int main()
{
	int r, c;
	cin >> r >> c;
	if (c > 10)
	{
		cout << "Left " << 10 - (r - 1) << " " << 10 - (c - 10) + 1;
	}
	else
	{
		cout << "Right " << 10 - (r - 1) << " " << c;
	}
	cout << endl;
	return 0;
}
