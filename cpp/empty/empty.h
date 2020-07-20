#ifndef EMPTY_H
#define EMPTY_H

class Empty{

public:
	//Empty() {}//본체가 비어있는 디폴트 생성자  아무생성자가 없을떄 생김
	//Empty(const Empty& rhs) {/* memberwise copy */}  포인터값을 치환. 	
	//~Empty()	//본체가 비어있는 소멸자. 	아무소멸자가 없을때 생김,
	//Empty& operator=(const Empty& rhs)  {/* memberwise copy */}
	//Empty* operator&() { return this;}
	//const Empty* operator&() const {return this;}



};
//6의 맴버함수가 생긴다. 컴파일러가 만들어준다.
/*자동적으로 만들어주는 멤버함수 생성자가 없을경우 본체가 비어있는 디폴트 생성자를 만들어줌


*/
#endif
