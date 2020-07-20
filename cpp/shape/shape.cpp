#include "shape.h"

Shape::Shape(int x, int y)
:x_(x), y_(y)
{

}

void Shape::move(int offsetX, int offsetY)
{
	x_ += offsetX;
	y_ += offsetY;
}
