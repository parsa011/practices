#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    float n, sum = 0, min_n, max_n = 0, product = 1;
    for (int i = 0; i < 4; i++)
    {
        cin >> n;
	sum += n;
	min_n = i == 0 ? n : min(min_n, n);
	max_n = i == 0 ? n : max(max_n, n);
	product *= n;
    }
    setprecision(6);
    cout << "Sum : " << fixed << setprecision(6) << sum << endl;
    cout << "Average : " << sum / 4 << endl;
    cout << "Product : " << product << endl;
    cout << "MAX : " << max_n << endl;
    cout << "MIN : " << min_n << endl;
    return 0;
}
