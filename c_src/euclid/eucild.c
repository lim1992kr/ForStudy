#include <stdio.h>

int gcd(int a, int b)
{
	int tmp=0;
	while(1){ 
		if(a < b){
		 tmp = a;
		 a = b;
		 b = tmp;	 
		 }	
		if (a % b == 0)
			return b;
		else if(a % b != 0 )
			a = a % b;								 		 
	}
}	
int gcd2(int a, int b)
{
	int tmp=0; 
		if(a < b){
		 tmp = a;
		 a = b;
		 b = tmp;	 
		 }	
	int r;
	while (r = a % b){
		a = b;
		b = r;
	}
		return b;
}

int main(void)
{
	int a, b;

	scanf("%d %d", &a, &b);
	printf("gcd : %d\n", gcd(a,b));	
}
