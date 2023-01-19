#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n, temp;
	cin >> n;
	
	int sizes[n];
	for (int i = 0; i < n; i++)
		cin >> sizes[i];

	for (int i = 0; i < n; i++) {
		if (sizes[i] < 1024) {
			cout << sizes[i]<< "B" << endl;
		} else if (sizes[i] < 1024 * 1024) {
			cout << floor(sizes[i] / 1024) << "KiB" << endl;
		} else
		 	cout << floor(sizes[i] / (1024 * 1024)) << "MiB" << endl;
	}
	return 0;
}
