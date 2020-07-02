#include<stdio.h>

int main(void)
{
	int num;
	printf("input num : ");
	scanf("%d", &num);
	
//  if( num % 2 /* != 0 zero canbe false */ ){
//		printf("%d is a odd number\n",num);		//odd
//	} else{
//		printf("%d is	even number\n", num); //even
//	}

	printf("%d is a ??? number\n", num,(num % 2 ) ? "odd" : "even");
	
	return 0;
}
