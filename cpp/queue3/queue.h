#ifndef QUEUE_H //만약 정의가 안되어있으면 불러와라. 해더파일을 두번 불러오지 않게하는거
#define QUEUE_H// 정의하면서 불러온다,.
#include "array.h"	//해즈어 관계
//#define QUEUESIZE 100

class Queue {
private:
	static const int QUEUESIZE;
		
//	int *pArr_;	//array.h에 이미 선언을 해놨음.		
//	int size_;		
	Array arr_;
	int front_;
	int rear_;	

public:

	explicit Queue (int size = Queue::QUEUESIZE);  //constructor 함수중복하지않고 
//	Queue(const Queue& rhs);	
//	~Queue();			  //destructor //컴파일러가 제공하는것을 사용한다.
//	Queue& operator=(const Queue& rhs);
	//오퍼레이트= 연산은  이렇게 생김 데이지 체인연산을하려면 필요하다.,결과값이 s1	
	bool operator==(const Queue& rhs)const;	
	
	int size() const;
	
	
	void push(int data); // 함수선언.
	int pop();

};


#endif	//	정의가 되어있으면 종료해라.

