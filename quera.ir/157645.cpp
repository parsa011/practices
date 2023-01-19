#include <iostream>

using namespace std;

int main()
{
    int rabits_count, losses, period;
    cin >> rabits_count >> losses >> period;

    for (int i = 0; i < period; i++) {
        rabits_count = rabits_count * 2 - losses;
    }

    cout << rabits_count << endl;

    return 0;
}
