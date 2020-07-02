#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void initQueue(Queue *pq)
{
	pq->front =0;
	pq->rear =0;
}

void push(Queue *pq, int data)
{
	if (pq->front == QUEUESIZE){
		fprintf(stderr, "stack is full\n");
		//stdout 버퍼를 쓴다. stderr 버퍼를 쓰지 않는다.
		exit(1);
	}
	pq->arr[pq->front] = data;
	++pq->front;		
}

int pop(Queue *pq)
{
	if (pq->rear == QUEUESIZE){
		fprintf(stderr, "stack is empty\n");
		exit(2);
	}
	
	//++pq->rear;
	return pq->arr[pq->rear++];
}
 
