#include <iostream>
using namespace std;

int main()
{
    long long res = 5, n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        res *= 5;
    }
    cout << res << endl;
}
