#include <iostream>

using namespace std;

int orig[] = {
    1,
    1,
    2,
    2,
    2,
    8
};

int main()
{
    int m[6];
    for (int i = 0; i < 6; i++) {
        cin >> m[i];
    }
    for (int i = 0; i < 6; i++) {
        cout << orig[i] - m[i] << " ";
    }
    return 0;
}
