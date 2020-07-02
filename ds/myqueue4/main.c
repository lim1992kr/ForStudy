#include <stdio.h>
#include "queue.h"

int main(void)
{
	Queue q1,q2;
	
	initQueue(&q1,10);  //초기화 시킬때 사이즈를 준다. 가변길이의 배열 공간이 10개
	initQueue(&q2,100);
	
	//q1.front = 0;
	//q1.rear = 0;
	//q2.front = 0;
	//q2.rear = 0;
	
	push(&q1,100);
	push(&q1,200);
	
	printf("1st pop() ; %d\n", pop(&q1));
	
	push(&q1,300);
	printf("2nd pop() ; %d\n", pop(&q1));
	printf("3rd pop() ; %d\n", pop(&q1));
	
	
	push(&q2,400);
	push(&q2,500);
	
	printf("1st pop() ; %d\n", pop(&q2));
	
	push(&q2,600);
	printf("2nd pop() ; %d\n", pop(&q2));
	printf("3rd pop() ; %d\n", pop(&q2));
	
	
	return 0;
}
