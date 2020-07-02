#include <assert.h>
#include <stdlib.h>
#include "queue.h"


void initQueue(Queue *pq, int size)
{
	pq->pArr = malloc (sizeof(int) * size);
	assert(pq->pArr != NULL);//조건이 참이면 진행, 거짓이면 프로그램이 죽는다.  !=NULL 생략
	// == NULL이 반환되면 동적할당에 실패한거
	// != NULL이 반환되면 동적할당에 성공해서 할당된 메모리의 포인터를 받아온다.
	//Malloc Return Value
	//This function returns a pointer to the allocated memory, or NULL if the request fails.
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
	//assert(pq->front != pq->size);    //꽉차면 꺼라
	assert(pq->rear != (pq->front +1)% pq->size);//빈것과 꽉찬게 구분이 안되니까 빈칸을 만든다.	
	
	pq->pArr[pq->front] = data;
	//++pq->front;		
	pq->front = (pq ->front) + 1 % pq->size;
}
int pop(Queue *pq)
{
	assert(pq->rear != pq->front);  
	int index = pq->rear;
	pq->rear = (pq->rear +1) % pq ->size;
	return pq->pArr[index];
}
