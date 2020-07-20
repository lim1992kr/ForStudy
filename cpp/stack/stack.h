#ifndef STACK_H
#define STACK_H

class Stack{
private:
	int *pArr;					//배열은 포인터 식으로 포인터는 배열식으로.
	int size;					//사용자가 원하는 배열의 크기를 담기 위해서 만들었다.
	int tos;	

	//void initStack(int size);
	//void cleanupStack();
public:
	Stack (int size);  //constructor
	~Stack();			  //destructor
	
	void push (int data);
	int pop ();

};


#endif
