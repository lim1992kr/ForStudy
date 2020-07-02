#include<stdio.h>

int main()
{
	int num;
	printf("input num : ");
	scanf("%d",&num);
	
	if(num > 0)
		printf("num: %d is a positive number \n", num);
	else if( (num == 0 ) 
		printf("num : %d is a zero number\n", num);
	else
		printf("num: %d is a negative number \n", num);
			
//	printf("num: %d is a %s number\n", 
//	(num >0 )"Positive" : "zere" :(num ==0) ? "zere" : "negetive");	
	
	return 0;
}
