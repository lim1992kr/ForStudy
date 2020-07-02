#include<stdio.h>

long long power (int base, int exponent)
{
	long long result = 1ll;
	for (int i = 1; i<=exponent; ++i)
		result *= base;
	return result;

}


int main(void)
{
	long long result;
	
	result = power(2,32);
	printf("2 power of 8 : %lld\n", result);

	return 0;
}
