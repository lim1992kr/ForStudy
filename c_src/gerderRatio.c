#include<stdio.h>

int main(void)
{
	int man, woman;
	printf("#man #woman : ");
	scanf("%d %d", &man , &woman);
	
	int total = man + woman;
	
	double manRatio, womanRatio;
	//manRatio = 1.0*man / total *100;
	//womanRatio = (0.0+woman) / total *100;
	manRatio = (double)man/total *100;
	womanRatio = (double) woman/total*100;
	
	printf("manRatio : %.2f%%\twomanRatio : %.2f%%\n", manRatio,womanRatio);
	
	return 0;
}
