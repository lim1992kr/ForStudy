#ifndef QUEUE_H //만약 정의가 안되어있으면 불러와라. 해더파일을 두번 불러오지 않게하는거
#define QUEUE_H// 정의하면서 불러온다,.
#define QUEUESIZE 100

typedef struct queue {
	int arr[QUEUESIZE];
	int front;
	int rear;	
} Queue;

void 	initQueue(Queue *ps);

void push(Queue *pq,int data); // 함수선언.
int pop(Queue *pq);

#endif	//	정의가 되어있으면 종료해라.
/*
#ifndef STACK_H
#define STACK_H
#define STACKSIZE 100

typedef struct stack {
	int arr[STACKSIZE];
	int tos;	
} Stack;

void 	initStack(Stack *ps);

void push (Stack * ps, int data);
int pop (Stack *ps);

#endif

*/
