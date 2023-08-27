#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int dm_length = 2 * n + 1;
	int stars_count = 1, space_count = n + 1;
	int inc = 2, sp_inc = -1;
	for (int i = 0; i < dm_length; i++) {
		cout << setw(space_count);
		for (int j = 0; j < stars_count; j++) {
			cout << "*";
		}
		if (i == dm_length / 2) {
			inc = -2;
			sp_inc = 1;
		}
		cout << endl;
		stars_count += inc;
		space_count += sp_inc;
	}
	return 0;
}
