#include <iostream>
#include <typeinfo>
#include "shape.h"
#include "rectangle.h"
#include "circle.h"

void printAreaOfShapeArray(Shape **ptrArr, int size) //포인터를 엘리먼트로 가지는 배열을 넘길때
{
	for (int i = 0; i < size; ++i)
	{
		if (typeid(*ptrArr[i]) == typeid(Rectangle)) {
			std::cout << "rectangle";
		} else if (typeid(*ptrArr[i]) == typeid(Circle)) {
			std::cout << "circle";
		}else
			;
		std::cout << "area : " << ptrArr[i] -> area() << std::endl;
	}
}

void printArea(const Shape *ps)
{
	if (typeid(*ps) == typeid(Rectangle))  //runtime type indentification (RTTI) 객체지향언어에서 자바에서 많이씀
		std::cout << "rectangle";
	else if (typeid(*ps)== typeid(Circle))
		std::cout << "circle";
	else
		;

	std::cout << "area: " << ps->area() << std::endl;

}


int main()
{
//	Shape s(100, 200); //abc는 객체못만든다.
	Shape *ps = new Rectangle(100, 200, 10, 50);
	delete ps;
	Circle c(200, 200, 10);
	Shape &r = c;
	
	Shape *shapes[5];
	shapes[0] = new Rectangle (100, 200, 10, 50);
	shapes[1] = new Circle (200, 100, 5);
	shapes[2] = new Rectangle (50, 50, 100, 10);
	shapes[3] = new Rectangle (200, 50, 5, 5);
	shapes[4] = new Circle(200, 200, 10);
	
	for (int i = 0; i < 5; ++i) {
		if (typeid(*shapes[i]) == typeid(Rectangle)) {
			Rectangle *pr = dynamic_cast<Rectangle *> shapes[i];
			std::cout << "sumOfSide: " << pr->sumOfSide() << std::endl; 
		
		} else if (typeid(*shapes[i])== typeid(Circle)) {
			Circle *pc = dynamic_cast<Circle *> shapes[i];
			std::cout << "circumference : " << pc->circumference() << std::endl;
		} else {
		
		}
	
	}
	
	
	for(int i = 0; i<5; ++i)
		printArea(shapes[i]);
		
	printAreaOfShapeArray(shapes,5);
	
	for (int i = 0; i < 5; ++i)
		delete shapes[i];
	
	return 0;
}
