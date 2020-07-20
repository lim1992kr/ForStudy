#include "empty.h"

int main()
{
	Empty e1;
	Empty e2(e1);

	e1 = e2;
	
	Empty *p;
	p = &e1;
	
	const Empty e3;
	&e3;

	return 0;
}

//클레스안에 정의가 안되면 자동적으로 만들어주는 애가 있다.
