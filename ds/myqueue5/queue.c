#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "queue.h"


void initQueue(Queue *pq, int size, int eleSize)
{
	pq->pArr = malloc (eleSize * size);
	assert(pq->pArr );//조건이 참이면 진행, 거짓이면 프로그램이 죽는다.  !=NULL 생략
	pq->eleSize = eleSize;
	pq->size = size;	
	pq->front = 0;
	pq->rear = 0;
}
void cleanupQueue(Queue *pq)
{
	free(pq->pArr);
}
void push(Queue *pq, const void  *pData)
{
	assert(pq->front != pq->size);    //꽉차면 꺼라
	/*
	if (pq->front == QUEUESIZE){
		fprintf(stderr, "stack is full\n");
		//stdout 버퍼를 쓴다. stderr 버퍼를 쓰지 않는다.
		exit(1);
	}
	*/	
//	pq->pArr[pq->front] = data;
	memcpy((unsigned char *)pq->pArr + pq->front * pq->eleSize, pData, pq->eleSize);
	++pq->front;		
}
void pop(Queue *pq, void *pData)
{
	assert(pq->rear != pq->front);  
	/*
	if (pq->rear == QUEUESIZE){
		fprintf(stderr, "stack is empty\n");
		exit(2);
	}
	*/		
	int index = pq->rear;
	++pq->rear;
	//	return pq->pArr[pq->rear++];
	memcpy(pData, (unsigned char *)pq->pArr + index * pq->eleSize,pq->eleSize);


//memcpy(a, b, 5); b의 공간중에 앞에 5바이트의 내용을 a에 복사를 하고 싶습니다.


}
