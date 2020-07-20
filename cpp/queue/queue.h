#ifndef QUEUE_H //만약 정의가 안되어있으면 불러와라. 해더파일을 두번 불러오지 않게하는거
#define QUEUE_H// 정의하면서 불러온다,.
//#define QUEUESIZE 100

class Queue {
private:
	int *pArr;			//동적할당하기위해서.
	int size; //배열의 길이.
	int front;
	int rear;	

public:
	Queue (int size);  //constructor
	~Queue();			  //destructor
	void push(int data); // 함수선언.
	int pop();

};


#endif	//	정의가 되어있으면 종료해라.

