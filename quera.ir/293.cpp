#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int n) {
  if (n <= 1) return false;
  int sqrt_n = sqrt(n);
  for (int i = 2; i <= sqrt_n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int main()
{
	int a, b;
	cin >> a >> b;
	int MAX = max(a, b), MIN = min(a, b);
	for (int i = MIN; i <= MAX; i++)
	{
		if (is_prime(i))
			cout << i << endl;
	}
	return 0;
}
	
