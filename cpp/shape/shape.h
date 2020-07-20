#ifndef SHAPE_H
#define SHAPE_H

class Shape { 				//Abstract base Class(ABC) 추상클래스
protected:
	int x_;
	int y_;

public:
	Shape(int x, int y);
	virtual ~Shape() {} //헤더파일 만들면서 정의. 인라인 함수로 만들어주세요.
	
	void move(int offsetX, int offsetY);
	virtual double area() const = 0;  //순수 가상함수. pure virtual function 
};

#endif

