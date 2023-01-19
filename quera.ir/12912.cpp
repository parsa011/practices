#include <iostream>

using namespace std;

void make(int db[], int len, int index, string bag)
{
    if (index >= len)
        return;
    cout << "{" << bag << "}" << endl;
    string temp;
    for (int i  = index + 1; i < len; i++) {
        temp = bag;
        temp += ", ";
        temp += to_string(db[i]);
        make(db, len, i, temp);
    }
}

int main()
{
	int n;
	cin >> n;

	int db[n];
	for (int i = 0; i < n; i++) {
        db[i] = i + 1;
	}

	cout << "{}" << endl;
	for (int i = 0; i <= n; i++) {
    	make(db, n, i, to_string(db[i]));
	}
	return 0;
}
