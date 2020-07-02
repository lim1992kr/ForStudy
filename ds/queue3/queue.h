#ifndef STACK_H //만약 정의가 안되어있으면 불러와라. 해더파일을 두번 불러오지 않게하는거
#define STACK_H// 정의하면서 불러온다,.
#define QUEUESIZE 100

typedef struct {
	int arr[QUEUESIZE];
	int front;
	int rear;
}Queue;

void push(Queue *pq, int data); // 함수선언.
int pop(Queue *pq);

#endif	//	정의가 되어있으면 종료해라.
