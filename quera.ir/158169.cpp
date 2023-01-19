#include <iostream>
#include <vector>

using namespace std;

void get_array(vector<int> &buf, int len)
{
    int temp;
    for (int i = 0 ; i < len; i++) {
        cin >> temp;
        buf.insert(buf.end(), temp);
    }
}

int find(int foods_count, vector<int> calories, int count)
{
    if (count > foods_count)
        return 0;
    int n = 0, max_c = 0, start = 0, end = 0;
    for (int i = 0; i < foods_count; i++) {
        if (n > max_c || n < 0) {
            end = i;
            max_c = max(max_c, n);
            n = 0;
        }
        n += calories.at(i);
    }
    cout << start << '\t' << end << endl;
    return max_c + find(foods_count, calories, count + 1);
}

int main()
{
    int foods_count;
    cin >> foods_count;

    vector<int> calories;
    get_array(calories, foods_count);

    int cal = find(foods_count, calories, 1);
    cout << cal << endl;
    return 0;
}
