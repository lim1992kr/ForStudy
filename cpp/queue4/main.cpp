#include <iostream>
#include "queue.h"

//실행할때 g++ -o teststack main.o stack.o array.o 해야한다.
int main()
{
	Queue<int> q1;			//Stack s1(100);
	q1.push(100);
	q1.push(200);
	q1.push(300);
			
	std::cout << "q1 1st pop() : " << q1.pop() << std::endl;	
	std::cout << "q1 2nd pop() : " << q1.pop() << std::endl;			
	std::cout << "q1 3rd pop() : " << q1.pop() << std::endl;	
		
	Queue<double> q2;			//Stack s1(100);
	q2.push(1.1);
	q2.push(2.2);
	q2.push(3.3);
			
	std::cout << "q2 1st pop() : " << q2.pop() << std::endl;	
	std::cout << "q2 2nd pop() : " << q2.pop() << std::endl;			
	std::cout << "q2 3rd pop() : " << q2.pop() << std::endl;	
	
	Queue<long long> q3;			//Stack s1(100);
	q3.push(70000000000);
	q3.push(80000000000);
	q3.push(90000000000);
			
	std::cout << "q3 1st pop() : " << q3.pop() << std::endl;	
	std::cout << "q3 2nd pop() : " << q3.pop() << std::endl;			
	std::cout << "q3 3rd pop() : " << q3.pop() << std::endl;	
			
			
	return 0;
}
