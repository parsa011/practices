#include <iostream>
#include <math.h> 

using namespace std;

int digit_count(int n)
{
	return floor(log10(abs(n))) + 1;
}

int main()
{
	cout << digit_count(123) << endl;
	return 0;
}
