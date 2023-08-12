#include <iostream>
#include <string>

using namespace std;

int main()
{
  string names[] = {"parsa", "ali", "hossein"};
  for (string name : names) {
    cout << name << endl;
  }
  for (int i = 0; i < sizeof(names) / sizeof(names[0]); i++) {
    cout << names[i] << endl;
  }
  return 0;
}
