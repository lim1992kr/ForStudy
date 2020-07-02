#include <stdio.h>
#include "queue.h"

int main(void)
{
	Queue q1,q2; //더만들고 싶으면 배열을 만들어라.
	
	initQueue(&q1);
	initQueue(&q2);
	//q1.front = q1.rear = q2.front = q2.rear = 0;
	
	push(&q1,100);
	push(&q1,200);
	
	printf("q1 1st pop() ; %d\n", pop(&q1));
	
	push(&q1,300);
	printf("q1 2nd pop() ; %d\n", pop(&q1));
	printf("q1 3rd pop() ; %d\n", pop(&q1));

	push(&q2,700);
	push(&q2,800);
	
	printf("q2 1st pop() ; %d\n", pop(&q2));
	
	push(&q2,900);
	printf("q2 2nd pop() ; %d\n", pop(&q2));
	printf("q2 3rd pop() ; %d\n", pop(&q2));

	//구조체는 무조건 포인터를 써라. 오버헤드를 줄이기위해서.

	return 0;
}
