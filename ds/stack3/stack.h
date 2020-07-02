#ifndef STACK_H
#define STACK_H
#define STACKSIZE 100

typedef struct stack {
	int arr[STACKSIZE];  //배열의 크기
	int tos;	
} Stack;

void 	initStack(Stack *ps);

void push (Stack * ps, int data);
int pop (Stack *ps);

#endif
