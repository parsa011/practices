#include <iostream>

using namespace std;

#define ll long long int

void make_biggest(ll count, ll sum, ll current_sum, ll &res, ll len)
{
    if (sum > count * 9 || sum == 0) {
        res = -1;
        return;
    }
    if (len == count)
        return;
    if (current_sum == sum && len < count) {
        res *= 10;
    } else {
        ll to_add = sum - current_sum >= 10 ? 9 : sum - current_sum;
        res = res * 10 + to_add;
        current_sum += to_add;
    }
    make_biggest(count, sum, current_sum, res, len + 1);
}

void make_smallest(ll count, ll sum, ll current_sum, ll &res, ll len)
{
	if (sum > count * 9 || sum == 0) {
		res = -1;
		return;
	}
	if (len == count)
		return;
	if ((sum - current_sum < 10 && len + 1 < count && len > 0)
		||
		((count - (len + 1)) * 9 >= sum - current_sum && len > 0)) {
		res *= 10;
	} else if (len + 1 == count && sum - current_sum < 10) {
		res = res * 10 + sum - current_sum;
	} else {
		ll to_add = 0;
		for (ll i = 1; i < 10; i++) {
			if (i + (9 * (count - (len + 1))) >= sum - current_sum) {
				to_add = i;
				break;
			}
		}
		res = res * 10 + to_add;
		current_sum += to_add;
	}
	make_smallest(count, sum, current_sum, res, len + 1);
}

int main()
{
    ll m, s;
    cin >> m >> s;
    ll biggest = 0, smallest = 0;
    make_biggest(m, s, 0, biggest, 0); 
    make_smallest(m, s, 0, smallest, 0);
    cout << smallest << " " << biggest << endl;
    return 0;
}
