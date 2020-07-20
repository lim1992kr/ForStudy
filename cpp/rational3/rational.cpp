#include <cassert>
#include "rational.h"

int Rational::numberOfRational; //전역변수는 초기화 되서 0이다.
//생성자에서 증가시키고 소멸자에서 감소시킨다.

const int Rational::BLOCK_SIZE = 256;
Rational* Rational::headOfFreeList = NULL;



std::ostream& operator << (std::ostream& out, const Rational& rhs)
{
	out << "(" << rhs.num_ << "/ " << rhs.den_ << ") ";
	
	return out; 
}
int Rational::getNumberOfRational()
{
	return Rational::numberOfRational;
}

static int getGcd (int a, int b)
{//rational.cpp에서만 쓴다.
	if (a == 0 || b == 0)
		return 1;
	int tmp=0;
	while(1){ 
		if(a < b){
		 tmp = a;
		 a = b;
		 b = tmp;	 
		 }	
		if (a % b == 0)
			return b;
		else if(a % b != 0 )
			a = b % a;								 		 
	}
}	

std::istream& operator >> (std::istream& in, Rational& rhs)
{
	int num = 0;
	int den = 1;
	
	in >> num;
	if (in.peek() == '/') {
		in.ignore();
		in >> den;
	}
	
	if(in ) 
	rhs = Rational(num, den);
	
	return in;
}

//static member func.

void *Rational::operator new(size_t size)
{
	if (size != sizeof(Rational))
		return ::operator new(size);
	
	Rational *ptr = Rational::headOfFreeList;
	if(ptr) {
		Rational::headOfFreeList = ptr->next;
	}else {
		Rational *newBLK = reinterpret_cast<Rational *> ( ::operator new (Rational::BLOCK_SIZE * sizeof(Rational)));
		assert(newBLK );
		
		for(int i = 1; i < Rational::BLOCK_SIZE -1; ++i)
			newBLK[i].next = &newBLK[i + 1];
	
		newBLK[Rational::BLOCK_SIZE -1 ].next = NULL;
		
		Rational::headOfFreeList = &newBLK[1];
		ptr = newBLK;
	}
	return ptr;
}
void Rational::operator delete(void *ptr,size_t size)
{
	if(ptr == NULL)
		return;
	if(size != sizeof(Rational)){
		::operator delete(ptr);
		return;
	}
	
	Rational *deleteNode = reinterpret_cast<Rational *>(ptr);
	deleteNode->next = Rational::headOfFreeList;
	Rational::headOfFreeList = deleteNode;
	

}

/*
Rational::Rational() //생성자 1
{
	num_ = 0;
	den_ = 1;
}

Rational::Rational(int num) //생성자 2
{
	num_ = num;
	den_ = 1;
}
*/ //맴버변수와 지역변수이름이 같아서 this 생략
Rational::Rational(int num, int den) // 생성자 3
: num_(num), den_(den)
{
	assert(den != 0);
	this->reduce();
	++Rational::numberOfRational;
}
Rational::Rational(const Rational& rhs)
{
	num_ = rhs.num_;
	den_ = rhs.den_;
	++Rational::numberOfRational;
}

Rational::~Rational()	//소멸자
{
	--Rational::numberOfRational;
}
/*
Rational& Rational::operator= (const Rational& rhs)
{
	num_ = rhs.num_;
	den_ = rhs.den_; 
}
*/
bool Rational::operator==(const Rational& rhs) const
{
/*	if (this->re == ths.re && this -> im == ths.im)
		return true;
	else
		return false; 
*/		
	return (num_ == rhs.num_ && den_ == rhs.den_);	
}

const Rational Rational::operator+(const Rational& rhs) const
{
	int num = num_ * rhs.den_ + rhs.num_ * den_ ;
	int den = den_ * rhs.den_;
	
	Rational result(num,den);    // 3 + 3/4	
	result.reduce();
	return result;
}
const Rational Rational::operator-(const Rational& rhs) const
{
	int num = num_ * rhs.den_ - rhs.num_ * den_ ;
	int den = den_ * rhs.den_;

	 
	Rational result(num,den);    	 
	result.reduce();
	return result;
}

const Rational Rational::operator*(const Rational& rhs) const
{	
	int num = num_ * rhs.num_ ;
	int den = den_ * rhs.den_;
	 
	Rational result(num, den);    // 3/1 * 3/4	
	result.reduce();
	return result;
}

const Rational Rational::operator/(const Rational& rhs) const
{
	int num = num_ * rhs.den_ ;
	int den = den_ * rhs.num_;
	 	 
	Rational result(num, den); // 3/1 / 3/4	
	result.reduce();
	return result; 
}

int Rational::getNum() const
{
	return num_;
}

int Rational::getDen() const
{
	return den_;
}

void Rational::setNum(int num)
{
	num_ = num;
}

void Rational::setDen(int den)
{
	den_ = den;
}
void Rational::reduce()const
{
	int gcd = getGcd(num_, den_);
	
	num_ = num_ /gcd;
	den_ = den_ /gcd;

}

