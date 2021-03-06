#ifndef ARRAY_H
#define ARRAY_H

class Array {  
protected:			//메인은 접근안되고 자식은 접근가능
	int *pArr_;
	int size_;	 //프라이빗 멤버 인데 자식쪽에서 접근할수있게

private:
	static const int ARRAYSIZE; 
	
	void set_arr(const int *pArr, int size);
	
public:
	//Array();
	//Array(const Array& rhs);
	//~Array();
	//Array& operator=(const Array& rhs);
	//Array* operator&();
	//const Array* operator&() const;
	
	explicit Array(int size = Array::ARRAYSIZE);	//인자가 하나인 생성자	 //묵시적인 형변환을 막는다.//기본인자로 100개를 줌
	Array(const int *pArr, int size);	//인자가 두개인 생성자
	Array(const Array& rhs);	//복사생성자	
	virtual ~Array();		//소멸자.
		
	Array& operator=(const Array& rhs);  //치환연산자
	
	bool operator==(const Array& rhs) const;		//비교연산자
	
	int& operator[](int index);			//대괄호 연산자
	const int& operator[](int index) const;		//두개가 뭐가다름??
	
	int size() const;  //싸이즈를 확인하는 함수.
};

#endif
