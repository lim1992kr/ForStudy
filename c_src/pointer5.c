#include<stdio.h>


int add (int a, int b)
{
	return a+b;
}

int sub (int a, int b)
{
	return a-b;
}

int main(void)
{
	int (*fp)(int ,int);
	
	fp = add; fp = &add;
	
	int re = fp(4,3); // re = (*fp)(4.3)
	printf("re: %d\n", re);
	
	fp = sub;
	re = fp(4,3);
	printf("re: %d\n",re);
	
	
	return 0;
}
