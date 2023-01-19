#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (180 - (a + b) == c
        &&
        180 - (a + c) == b
        &&
        180 - (b + c) == a)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
