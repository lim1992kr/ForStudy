#include <iostream>
using std::cout;
using std::endl;
/*
void swap(int &ra, int &rb)
{
	int tmp = ra;
	ra = rb;
	rb = tmp;
}

void swap (double &rx, double &ry)
{
	double tmp = rx;
	rx = ry;
	ry = tmp;
}
*/
template <typename T>
void swap (T &ra, T &rb)
{
	T tmp = ra;
	ra = rb;
	rb = tmp;
}

int main()
{
	int a = 100;
	int b = 200;
	
	cout << "a: " << a << "  b: " << b << endl;
	swap(a,b);
	cout << "a: " << a << "  b: " << b << endl;

	double x = 1.1;
	double y = 2.2;
	
	cout << "x: " << x << "  y: " << y << endl;
	swap(x,y);
	cout << "x: " << x << "  y: " << y << endl;

	return 0;	
}
