#include <iostream>
#include "employee.h"
int main()
{
	Employee* ems[5];
	ems[0] = new Employee (1, "Lim chae beom",NULL);
	ems[1] = new Employee (2, "cat", ems[0] );
	ems[2] = new Employee (3, "dog", ems[0] );	
	ems[1] = new Employee (4, "dolpin", ems[1] );	
	ems[1] = new Employee (2, "fish", ems[1] );
	
//	Employee e1; // 	X
//	Employee e2(e1); // X

//  e2 = e1 ;  X
	if (ems[0]->isDirector())
		std::cout << ems[0]->getName() <<  "is a Manager" << std::endl;
	else
		std::cout << ems[0]->getName() <<  "is not a Manager" << std::endl;
	
	std::cout << "id:" << ems[0]->getId() << " "<< ems[0]->getName() << " " << std::endl;
	
	for (int i = 0; i < 5; ++i)
		delete ems[i]; 
	
	
	return 0;
}
