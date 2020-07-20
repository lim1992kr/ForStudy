#include <iostream>
#include "queue.h"

int main()
{
	Queue q1;
    Queue q2(10);
    Queue q3(q2);

    q2.push(100);
    q2.push(200);
    q2.push(300);

    q1 = q2;
    if(q1 == q2)
        std::cout << "q1 and q2 are equal" << std::endl;
    else
        std::cout << "q1 and q2 are not equal;" << std::endl;

    std::cout << "q1 1st pop() : " << q1.pop() << std::endl;
    std::cout << "q1 2nd pop() : " << q1.pop() << std::endl;
    std::cout << "q1 3rd pop() : " << q1.pop() << std::endl;
    return 0;
	return 0;
}
