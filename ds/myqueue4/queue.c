#include <assert.h>
#include <stdlib.h>
#include "queue.h"


void initQueue(Queue *pq, int size)
{
	pq->pArr = malloc (sizeof(int) * size);
	assert(pq->pArr );//조건이 참이면 진행, 거짓이면 프로그램이 죽는다.  !=NULL 생략
	pq->size = size;	
	pq->front = 0;
	pq->rear = 0;
}
void cleanupQueue(Queue *pq)
{
	free(pq->pArr);
}
void push(Queue *pq, int data)
{
	assert(pq->front != pq->size);    //꽉차면 꺼라
	/*
	if (pq->front == QUEUESIZE){
		fprintf(stderr, "stack is full\n");
		//stdout 버퍼를 쓴다. stderr 버퍼를 쓰지 않는다.
		exit(1);
	}
	*/	
	pq->pArr[pq->front] = data;
	++pq->front;		
}
int pop(Queue *pq)
{
	assert(pq->rear == pq->front);  
	/*
	if (pq->rear == QUEUESIZE){
		fprintf(stderr, "stack is empty\n");
		exit(2);
	}
	*/		
	//++pq->rear;
	return pq->pArr[pq->rear++];
}
