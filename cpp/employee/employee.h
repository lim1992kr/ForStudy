#ifndef EMPLOYEE_
#define EMPLOYEE_
#include "string.h"

class Employee{
private:
	int id_;
	String name_;
	Employee *pManager_;
	
	Employee();
	Employee(const Employee& rhs);
	Employee& operator = (const Employee& rhs);  //기본제공하는 함수를 쓰기 싫으면 프라이빗에 넣어준다.
	
public:

//	~Employee();

//	Employee* operator&();
//	const Employee* operator&() const;
	Employee(int id, String name,const Employee *pManager);
	
	int getId() const;
	String getName() const;
	Employee* getManager() const;
	
	bool isDirector() const;
	
	void setManager(const Employee* pManager);
	
};

#endif

