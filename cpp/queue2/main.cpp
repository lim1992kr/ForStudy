#include <iostream>
#include "queue.h"

int main()
{
	Queue q1(10),q2(100);
	
	//q1.initQueue(10);  //초기화 시킬때 사이즈를 준다. 가변길이의 배열 공간이 10개
	//q2.initQueue(100);//생성자로 바꿔준다.
	
	q1.push(100);
	q1.push(200);
		
	std::cout << "q1 1st pop() :" << q1.pop() << std::endl;
	//결과값은 cout이고 side effect로 글자가 프린트 된다.
	
	q1.push(300);
	std::cout << "q1 2nd pop() :" << q1.pop() << std::endl;	
	
	std::cout << "q1 3rd pop() :" << q1.pop() << std::endl;	
	
	q2.push(400);
	q2.push(500);

	std::cout << "q2 1st pop() :" << q2.pop() << std::endl;
	
	q2.push(600);
	std::cout << "q2 2nd pop() :" << q2.pop() << std::endl;	
	std::cout << "q2 3rd pop() :" << q2.pop() << std::endl;	
	
	
	return 0;
}
