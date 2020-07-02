//함수정의는 다른 c파일에 있을수있다.
//const, static

void initQueue(Queue *pq)
{
	pq->front =0;
	pq->rear =0;
}

void push(Queue *pq, int data)
{
	pq->arr[pq->rear] = data;
	++pq->rear;
	
	//queue[rear] = data;
	//++rear;
}
int pop(Queue *pq, void)
{
	return pq->arr[pq->fornt++];
	//return queue[front++];
}
 
