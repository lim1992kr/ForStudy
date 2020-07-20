#include <iostream>

std::ostream& tab(std::ostream& out)
{
	return out << '\t';
}

int main()
{
	std::cout << "hello" << tab << "world" << std::endl;

	return 0;
}
