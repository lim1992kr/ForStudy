#ifndef QUEUE_H //만약 정의가 안되어있으면 불러와라. 해더파일을 두번 불러오지 않게하는거
#define QUEUE_H// 정의하면서 불러온다,.

typedef struct queue {

	//int *pArr;			//동적할당하기위해서.
	void *pArr;
	int eleSize;
	int size; //배열의 길이.
	int front;
	int rear;	
} Queue;

void initQueue(Queue *pq,int size,int eleSize);
void cleanupQueue(Queue *pq);

void push(Queue *pq, const void *pData); // 함수선언.
void pop(Queue *pq, void *pData);//임의의 인자를 전달할때 보이드 포인트를 쓴다.

#endif	//	정의가 되어있으면 종료해라.

