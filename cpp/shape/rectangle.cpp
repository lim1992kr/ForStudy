#include "rectangle.h"

Rectangle::Rectangle (int x, int y, int w, int h)
: Shape(x,y), width_(w), height_(h)
{

}

double Rectangle::area() const
{
	return width_ * height_; 
}

int Rectangle::sumOfSide() const
{
	//return 2 * width_ + 2+ height_;
	return width_ + width_ + height_ + height_ ;
 }//왼쪽으로 시프트 한번하면 *2

