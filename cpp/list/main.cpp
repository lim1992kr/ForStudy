#include <stdio.h>
#include "list.h"

int main()
{
	List list;  //List자료형에 포인터(이름:ptr) list를 메인에 만든다.
//	initList(&list); --> constructor //List초기화 함수. list 의 주소를 보낸다.
	
	list.insertFirstNode(4); 		//[4]
	std::cout << list << std::endl;
	list.insertFirstNode(3);		//[3,4]
	std::cout << list << std::endl;
	list.insertFirstNode(1);		//[1,3,4]
	std::cout << list << std::endl;
	list.insertNode(1 ,2);			//[1,2,3,4]
	std::cout << list << std::endl;
		
	list.deleteNode(3);  			//[,1,2,4]
	std::cout << list << std::endl;

//	cleanupList(&list);		--> destructor
	return 0;
}

