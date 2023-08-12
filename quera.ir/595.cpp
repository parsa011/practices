#include <iostream>

using namespace std;

int main()
{
	int count;
	cin >> count;
	int triangle[count][count] = {
		{1},
		{1,1}
	};
	/*
	  calculating triangle
	  but not with formula
	*/
	for (int i = 2; i < count; i++) {
		triangle[i][0] = 1;
		for (int j = 1; j < i; j++) {
			triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
		}
		triangle[i][i] = 1;
	}

	/*
	  showing result
	*/
	for (int i = 0; i < count; i++) {
		for (int j = 0; j <= i; j++) {
			cout << triangle[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}
