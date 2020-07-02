#include<stdio.h>

int main(void)
{
	int num;
	printf("input num : ");
	scanf("%d", &num);
	
	if( num % 2 ){
		printf("%d is a odd number\n",num);		//odd
	} else{
		printf("%d is	even number\n", num);	   //even
	}
	
	return 0;
}
