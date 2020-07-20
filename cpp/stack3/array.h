#ifndef ARRAY_H
#define ARRAY_H

class Array {
private:
	static const int ARRAYSIZE; 
	
	int *pArr_;
	int size_;	
	void set_arr(const int *pArr, int size);
	
public:
	//Array();
	//Array(const Array& rhs);
	//~Array();
	//Array& operator=(const Array& rhs);
	//Array* operator&();
	//const Array* operator&() const;
	
	explicit Array(int size = Array::ARRAYSIZE);		 //묵시적인 형변환을 막는다.//기본인자로 100개를 줌
	Array(const int *pArr, int size);
	Array(const Array& rhs);
	~Array();
		
	Array& operator=(const Array& rhs);
	
	bool operator==(const Array& rhs) const;
	
	int& operator[](int index);	
	const int& operator[](int index) const;
	
	int size() const;
};

#endif
