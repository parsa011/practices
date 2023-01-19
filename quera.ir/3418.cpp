#include <iostream>

using namespace std;

int find_gcd(int a, int b)
{
    int t;
    while (a > 0) {
        if (a < b) {
            t = a;
            a = b;
            b = t;
        }
        a -= b;
    }
    return b;
}

int main()
{
    int n;
    cin >> n;

    int numbers[n];
    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    int max_gcd = 0;
    for (int i = 0 ; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            max_gcd = max(find_gcd(numbers[i], numbers[j]), max_gcd);
        }
    }

    cout << max_gcd << endl;
    return 0;
}
