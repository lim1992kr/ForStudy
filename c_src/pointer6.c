#include<stdio.h>

int main(void)
{
	void *p;
	
	int i = 100;
	p = &i;
	
	*(int*)p =200;
	printf("i: %d\n" , i);
	
	double d = 3.14 ; 
	p = &d;
	
	*(double*)p = 2.718;
	printf("d: %f\n",d);
	
	return 0;
}
