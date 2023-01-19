#include <iostream>

using namespace std;


void make_biggest(int count, int sum, int current_sum, int &res, int len)
{
    if (sum > count * 9 || sum == 0) {
        res = -1;
        return;
    }
    if (len == count)
        return;
    if (current_sum == sum && len < count) {
        res *= 10;
    }
	// else if (sum - current_sum < 10) {
    //     res = res * 10 + (sum - current_sum);
    //     current_sum += sum - current_sum;
    // }
	else {
        int to_add = sum - current_sum >= 10 ? 9 : sum - current_sum;
        res = res * 10 + to_add;
        current_sum += to_add;
    }
    make_biggest(count, sum, current_sum, res, len + 1);
}

void make_smallest(int count, int sum, int current_sum, int &res, int len)
{
	if (sum > count * 9 || sum == 0) {
		res = -1;
		return;
	}
	if (len == count)
		return;
	if (sum - current_sum < 10 && len + 1 < count && len > 0) {
		res *= 10;
	} else if (len + 1 == count && sum - current_sum < 10) {
		res = res * 10 + sum - current_sum;
	} else {
		int to_add = 0;
		for (int i = 1; i < 10; i++) {
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
    int m, s;
    cin >> m >> s;
    int biggest = 0, smallest = 0;
    make_biggest(m, s, 0, biggest, 0); 
    make_smallest(m, s, 0, smallest, 0);
    cout << smallest << " " << biggest << endl;
    return 0;
}
