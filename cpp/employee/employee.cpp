#include "employee.h"

Employee::Employee(int id, String name, const Employee *pManager)
: id_(id), name_(name), pManager_((Employee *)pManager)
{

}

int Employee::getId() const
{
	return id_;
}

String Employee::getName() const
{
	return name_;
}

Employee* Employee::getManager() const
{
	return pManager_;
}

void Employee::setManager(const Employee *pManager)
{
	pManager_ = (Employee *)pManager;
}

bool Employee::isDirector() const
{
	return pManager_ == 0;
}




