#include <iostream>
void swap(int *pa, int *pb)
{
	int tmp = *pb;
	*pa = *pb;
	*pb = tmp;
}
void swap2(int &ra, int &rb)		//call by reference!
{
	int tmp = ra;
	ra = rb;
	rb = tmp;
}

int main()
{
	int a = 100;
	int b = 200;
	
	std::cout << "a : " << a << "\t" << "b : " << b << std::endl;
	swap(&a,&b);
	std::cout << "a : " << a << "\t" << "b : " << b << std::endl;

	a = 100;
	b = 200;
	
	std::cout << "a : " << a << "\t" << "b : " << b << std::endl;
	swap2(a,b);
	std::cout << "a : " << a << "\t" << "b : " << b << std::endl;
	
	
	return 0;
}




