#include <stdio.h>
#include "queue.h"

int main(void)
{
	Queue q1,q2; //메모리의 시작주소와 데이터 크기를 알면 모두 다룰수있다.
	
	initQueue(&q1,10,sizeof(int));  //초기화 시킬때 사이즈를 준다. 가변길이의 배열 공간이 10개
	initQueue(&q2,100,sizeof(double));
	
	//q1.front = 0;
	//q1.rear = 0;
	//q2.front = 0;
	//q2.rear = 0;
	int i = 100; push(&q1,&i);
	i = 200;  push(&q1,&i);
		
	pop(&q1, &i); printf("1st pop() ; %d\n", i);
	
	i = 300;  push(&q1,&i);
	
	pop(&q1, &i); printf("2nd pop() ; %d\n", i);
	pop(&q1, &i); printf("3rd pop() ; %d\n", i);
	
	
	double d = 1.1; push(&q2,&d);
	d = 2.2;  push(&q2,&d);
		
	pop(&q2, &d); printf("1st pop() ; %f\n", d);
	
	d = 3.3;  push(&q2,&d);
	
	pop(&q2, &d); printf("2nd pop() ; %f\n", d);
	pop(&q2, &d); printf("3rd pop() ; %f\n", d);
	
	cleanupQueue(&q1);
	cleanupQueue(&q2);
	
	return 0;
}
