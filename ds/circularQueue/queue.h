#ifndef QUEUE_H //만약 정의가 안되어있으면 불러와라. 해더파일을 두번 불러오지 않게하는거
#define QUEUE_H// 정의하면서 불러온다,.
//#define QUEUESIZE 100

typedef struct queue {
//	int arr[QUEUESIZE];  //고정크기 배열
	int *pArr;			//동적할당하기위해서.
	int size; //배열의 길이.
	int front;
	int rear;	
} Queue;

void initQueue(Queue *pq,int size);
void cleanupQueue(Queue *pq);

void push(Queue *pq,int data); // 함수선언.
int pop(Queue *pq);

#endif	//	정의가 되어있으면 종료해라.

