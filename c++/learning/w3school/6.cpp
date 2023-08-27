#include <iostream>
#include <string>

using namespace std;

int main()
{
  string name = "parsa";
  string &namep = name;
  cout << name << endl << namep << endl;
  namep = "ali";
  cout << name << endl << namep << endl;
  // ===================
  int age = 21;
  int *agep = &age;
  cout << age << endl << agep << '\t' << *agep << endl;
  return 0;

}
