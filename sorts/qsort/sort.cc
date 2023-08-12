#include <iostream>

using namespace std;

#define ARR_LEN(arr) (sizeof(arr) / sizeof(arr[0]))

void qsort(int arr[], int len)
{
  if (len < 2)
    return;
  int pivot = arr[0];
  int less[len];
  int less_len = 0;
  int greater[len];
  int greater_len = 0;

  int current;
  for (int i = 1; i < len; i++) {
    current = arr[i];
    if (pivot >= current) {
      less[less_len++] = current;
    } else {
      greater[greater_len++] = current;
    }
  }

  qsort(less, less_len);
  qsort(greater, greater_len);

  int i = 0;
  for (int j = 0; j < less_len; j++) {
    arr[i++] = less[j];
  }
  arr[i++] = pivot;
  for (int j = 0; j < greater_len; j++) {
    arr[i++] = greater[j];
  }
}

int main()
{
  int array[] = {2, 3, 9, 12, 4, 1, 2, 8, 12, 8 , 5, 28, 3};
  qsort(array, ARR_LEN(array));
  for (int i = 0; i < ARR_LEN(array); i++) {
    cout << array[i] << '\t';
  }
  cout << endl;
  return 0;
}
