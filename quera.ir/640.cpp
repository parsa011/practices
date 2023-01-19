#include <iostream>
#include <math.h>

using namespace std;

void find_gcd(long a, long b, long current, long &gcd)
{
    if (current > abs(a) || current > abs(b))
        return;
    if (a % current == 0 && b % current == 0)
        gcd = current;
    find_gcd(a, b, current + 1, gcd);
}

int main()
{
    long a, b;
    cin >> a >> b;
    long gcd = 0;
    find_gcd(a, b, 1, gcd);
    cout << gcd << endl;
    return 0;
}
