#ifndef STACK_H
#define STACK_H
//#define STACKSIZE 100

typedef struct stack {
//	int arr[STACKSIZE];
	int *pArr;					//배열은 포인터 식으로 포인터는 배열식으로.
	int size;					//사용자가 원하는 배열의 크기를 담기 위해서 만들었다.
	int tos;	
} Stack;

void initStack(Stack *ps,int size);
void cleanupStack(Stack *ps);

void push (Stack * ps, int data);
int pop (Stack *ps);

#endif
