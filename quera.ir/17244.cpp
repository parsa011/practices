#include <iostream>

using namespace std;

int find(int n)
{
    if (n == 0)
        return 0;
    return n + find(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << find(n) << endl;
    return 0;
}
