#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define ARR_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))

int binary_search(string names[], int len, const string target)
{
  int low = 0;
  int high = len - 1;
  int mid = 0;
  string item;
  while (low <= high) {
    mid = (low + high) / 2;
    item = names[mid];
    if (item == target) {
      return mid;
    }
    if (strcmp(target.c_str(), item.c_str()) < 0) {
      high = mid - 1;
    } else
      low = mid + 1;
  }
  return -1;
}

int main(int argc, char **argv)
{
  string names[] = {
    "ali",
    "arsham",
    "bahman",
    "bahram",
    "bizhan",
    "darioush",
    "erfan",
    "parsa",
    "setayesh"
  };
  int index = binary_search(names, ARR_LENGTH(names), "ali");
  if (index >= 0) {
    cout << "founded name is : " << names[index] << endl;
  }
  return 0;
}
