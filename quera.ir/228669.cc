#include <iostream>

using namespace std;

int main()
{
  int col;
  int row;
  cin >> col;
  cin >> row;
  if (row == 1 || col == 1) {
    cout << col * row << endl;
  } else {
    cout << col * 2 + (row - 2) * 2 << '\n';
  }
  return 0;
}
