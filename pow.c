#include  <stdio.h>

double myPow(double x, long long int n) {
	if(n==0){
		return 1;
	}
	if(n<0){
		n=-n;
		x=1/x;
	}
	if(n%2==0){
		return myPow(x*x, n/2);
	}
	return x*myPow(x*x, n/2);

}

int main()
{
	printf("%f\n", myPow(2, -2));
	return 0;
}
