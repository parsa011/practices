#include <iostream>
#include <string>

using namespace std;

struct person {
  string name;
  int age;
};

struct person read_person()
{
  cout << "=========================" << endl;
  struct person person;
  string name;
  int age;
  cout << "Enter persons name : ";
  cin >> name;
  cout << "enter persons age : ";
  cin >> age;
  cout << "=========================" << endl;
  person.name = name;
  person.age = age;
  return person;
}

int main()
{
  int count;
  cout << "How Many Person do you want to enter ? " << endl;
  cin >> count;
  struct person persons[count];
  for (int i = 0; i < count ; i++) {
    persons[i] = read_person();
  }
  return 0;
}
