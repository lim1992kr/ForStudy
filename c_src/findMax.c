#include<stdio.h>

int main(void)
{
	int nums[] = {30, 50, 100, 90, 10, 20, 40, 60, 70, 80};
	
	int max = nums[0];
	for (int i = 1; i<10; ++i) {
		if (max < nums[i])
			max = nums[i];
	}
	
	printf("max : %d\n",max);	
	
	return 0 ;
	}
	
