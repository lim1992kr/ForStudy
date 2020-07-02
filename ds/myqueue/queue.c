#include <stdio.h>

int queue[100];
int front; 	//뺄자리
int rear; // 들어갈자리

void push(int data)
{
	queue[rear] = data;
	++rear;
}
int pop(void)
{
	//int index = front;
	//++front;
	//return queue[front];
	return queue[front++];
}
 

int main(void)
{
	push(100);
	push(200);
	
	printf("1st pop() ; %d\n", pop());
	
	push(300);
	printf("2nd pop() ; %d\n", pop());
	printf("3rd pop() ; %d\n", pop());
	return 0;
}

