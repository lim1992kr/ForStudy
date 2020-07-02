#include <stdio.h>
#include "stack.h"

int main(void)
{
	Stack s1,s2;	
	
	initStack(&s1, 10, sizeof(int));
	initStack(&s2, 100, sizeof(double));
	
	int i = 100;  push(&s1,&i);
	i = 200;	 	push(&s1,&i);
	i = 300;		push(&s1,&i);
			
//어느스택에 넣을꺼냐 = 인자로 전달한다.
	pop(&s1, &i); printf("s1 1st pop(): %d\n",i);
	pop(&s1, &i); printf("s1 2nd pop(): %d\n",i);
	pop(&s1, &i); printf("s1 3rd pop(): %d\n",i);

	double d = 1.1;  push(&s2, &d);
	d = 2.2; 			push(&s2, &d);
	d = 3.3; 			push(&s2, &d);
	
	pop(&s2, &d); printf("s1 1st pop(): %f\n",d);
	pop(&s2, &d); printf("s1 2nd pop(): %f\n",d);
	pop(&s2, &d); printf("s1 3rd pop(): %f\n",d);

	cleanupStack(&s1);
	cleanupStack(&s2);

	return 0;
}
/*
int re =f();
int f(void)
{
return 100;
}
이걸 아래껄로 바꾼다.

int re;
f(&re);
void f(int *p)
{
*p = 100;
}


*/
