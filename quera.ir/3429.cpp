#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n < 0)
        cout << "Ice\n";
    else if (n > 100)
        cout << "Steam\n";
    else
        cout << "Water\n";
    return 0;
}
