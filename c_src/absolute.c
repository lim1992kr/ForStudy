#include<stdio.h>
int main(void)
{
	int num;
	printf("input valve : ");
	scanf("%d",&num);

	if(num<0){
		num = -num;
	}
	
	printf("absolute value : %d\n",num);
	
	return 0;
}
