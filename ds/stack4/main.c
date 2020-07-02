// 가변길이의 배열을 가지는 스택 구현
#include <stdio.h>
#include "stack.h"

int main(void)
{
	Stack s1,s2;	
	
	initStack(&s1, 10);  //arr[10];
	initStack(&s2, 100); //arr[100];
		
	push(&s1,100);
	push(&s1,200);
	push(&s1,300);		
//어느스택에 넣을꺼냐 = 인자로 전달한다.
	printf("s1 1st pop(): %d\n", pop(&s1));
	printf("s1 2nd pop(): %d\n", pop(&s1));
	printf("s1 3rd pop(): %d\n", pop(&s1));

	push(&s2,900);
	push(&s2,800);
	push(&s2,700);		
	
	printf("s2 1st pop(): %d\n", pop(&s2));
	printf("s2 2nd pop(): %d\n", pop(&s2));
	printf("s2 3rd pop(): %d\n", pop(&s2));

	cleanupStack(&s1);
	cleanupStack(&s2);

	return 0;
}


