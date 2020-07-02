#include<stdio.h>

long long fac(int );

int main(void)
{
	for (int i = 1; i <= 100; ++i)
		printf("%d! = %lld\n", i , fac(i));

	return 0;
}

long long fac(int n)
{
	long long result = 1;
	for (int i = 1; i <= n; ++i)
		result *= i;
		
		return result;
}
// big integer
