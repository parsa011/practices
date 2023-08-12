#include <stdio.h>
#include <stdint.h>
#include <limits.h>

#define ARR_LEN(arr) (sizeof(arr) / sizeof(arr[0]))

int binary_search(int list[], uint64_t len, uint64_t item)
{
  uint64_t low = 0;
  uint64_t high = len - 1;
  uint64_t mid = 0, guess = 0;
  while (low <= high) {
    mid = (low + high) / 2;
    guess = mid;
    if (guess == item)
      return mid;
    if (guess > item)
      high = mid - 1;
    else
      low = mid + 1;
  }
  return -1;
}

int normal_search(int list[], uint64_t len, uint64_t item)
{
  for (uint64_t i = 0; i < len; i++)
    if (i + 1 == item)
      return i;
  return -1;
}

int main() {
  uint64_t len = 1800000000;
  int list[2];
  printf("%d\n", binary_search(list, len, 1383069300));
  return 0;
}
