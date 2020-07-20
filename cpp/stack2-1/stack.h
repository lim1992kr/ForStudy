#ifndef STACK_H
#define STACK_H

class Stack{
private:
	int *pArr_;					//배열은 포인터 식으로 포인터는 배열식으로.
	int size_;					//사용자가 원하는 배열의 크기를 담기 위해서 만들었다.
	int tos_;	

	//void initStack(int size);
	//void cleanupStack();
public:
	Stack (int size);  //constructor
	~Stack();			  //destructor
	Stack(const Stack& rhs);
	
	Stack& operator=(const Stack& rhs);
	//오퍼레이트= 연산은  이렇게 생김 데이지 체인연산을하려면 필요하다.,결과값이 s1
	
	bool operator==(const Stack& rhs);	
	
	void push (int data);
	int pop ();

};


#endif
