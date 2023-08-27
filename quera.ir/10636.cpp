#include <iostream>
#include <string.h>

using namespace std;

#define COUNT 30

int main()
{
  int n, k, res = 0;
  cin >> n;
  char name[COUNT], last[COUNT];
  for (int i = 0; i < n; i++) {
    cin.getline(name, COUNT);
    if (i > 0) {
		k = 0;
		while (name[k] != ' ') {
			k += 1;
		}
		if (strncmp(name, last, k) == 0)
			res++;
    }
	cout << endl << name << '\t' << last << endl;
    strcpy(last, name);
  }
  cout << res << endl;
  return 0;
}
