#include<stdio.h>

//int sumArray(int pArr[], int size) 
int sumArray(const int *pArr, int size)
{
	int result = 0;
	for (int i = 0 ; i < size ; ++i)
		result += pArr[i];
		
	return result;	
}

int main(void)
{
	int nums[] = {1,2,3,4,5};
	
	int re;
	re = sumArray(nums, 5);
	
	printf("re : %d\n", re);
	return 0;
}
