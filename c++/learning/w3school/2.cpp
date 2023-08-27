#include <iostream>
#include <string>

using namespace std;
int main(int argc, char **argv)
{
  string name, last_name;
  cout << "Enter your Name \n";
  cin >> name;
  cout << "Enter your last name" << endl;
  cin >> last_name;
  cout << "your name is : " << name << endl;
  // concat
  cout << name.append(" " + last_name) << endl;
  cout << "length of your full name is : " << name.size() << endl;
  return 0;
}
