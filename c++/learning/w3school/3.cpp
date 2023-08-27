#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
  string name;
  cout << "Enter your name : ";
  getline(cin, name);
  cout << "Your name is : " << name;
  return 0;
}
