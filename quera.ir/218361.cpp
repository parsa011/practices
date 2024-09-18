#include <iostream>

using namespace std;

#define WAGON_SIZE 8

int main()
{
	int arr1[WAGON_SIZE];
	int arr2[WAGON_SIZE];
	for (int i = 0; i < WAGON_SIZE; i++)
	{
		cin >> arr1[i];
	}
	for (int i = 0; i < WAGON_SIZE; i++)
	{
		cin >> arr2[i];
	}
	int res = 0;
	for (int i = 0; i < WAGON_SIZE; i++)
	{
		if (arr1[i] == arr2[i] && arr1[i] == 1)
		{
			res++;
		}
	}
	cout << res << endl;
	return 0;
}
