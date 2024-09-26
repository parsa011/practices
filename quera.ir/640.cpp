#include <iostream>
#include <math.h>

using namespace std;

long gcd(long u, long v)
{
	if (v == 0)
		return u;
	return gcd(v, u % v);
}

int main()
{
    long a, b;
    cin >> a >> b;
    long g = gcd(abs(a), abs(b));
    cout << g << endl;
    return 0;
}
