from C to C++
1. .c ---> .cpp

2. push(&s1, 100); ---> s1.push(100); // member func
	-멤버함수는 반드시 객체(구조체 자료)를 통해서 호출해야 한다.
	-멤버함수는 자신을 호출한 객체를 가리키는 this 포인터를 가진다.

3. typedef struct{...}Stack; ---> struct Stack{...};

4. int main(void) ---> int main()

5. malloc()/free()  --> new, delete 연산자.

6. 생성자(construtor) : 객체가 생성될때 자동적으로 호출되는 멤버함수. 
						 //객체관련된 초기화.
   소멸자(destructor) : 객체가 소멸될때 자동적으로 호출되는 멤버함수.
   						 //클린업, 정리하는 코드.			
 	*생성자 소멸자에 반환타입을 쓰지 않는다
 							 
7. 접근 지정자(private/public) -> 정보 은닉(information hiding)
	-내부구현(implementation)은 허용된 연산을 통해서 접근한다.
	-내부구현은 숨기고 인터페이스는 외부로 보인다.

멤버함수는 같은 구조체 안에 있는 멤버에대해 접근이 가능하다.
메인에서는 퍼블릭에있는 멤버만 접근가능.

8. class = stuct(in C) + 멤버함수(class에 들어간 함수) + 접근지정자(public, private)

9. <assert.h> --> <cassert> //.h 가 없으면 name space가 적용안된거.

10. printf() ---> std::cout;

함수 중복(function overloading)  
'one - interface - multi - method'
똑같은 이름의 함수를 정의 가능(in C X), but 인자의 갯수 타입이 달라야 함.
c언어는 함수를 호출하면 함수의 이름만 보고 찾으러 가고
c++은 함수를 호출하면 함수의 이름 과 인자의 개수와 인자의 타입을 보고 찾는다.

디폴트 인자는 뒤쪽부터 써야한다.

 
참조(reference) :연산자 중복때문에 있다. aliasing
참조 vs pointer.
레퍼런스 
선언할때 초기값을 줘야한다.
사용할때 일반변수처럼사용.
*하나의 공간에 다른 이름을 붙혀서 사용하는거.

int a;
int *p;
a = 100;
p = &a;
*p = 200;
//a
값을 바꿀수있고 역참조

int a;
int &r = a;
a = 100;
r = 200;
//a
 
포인터
int a = 100;
int b = 200;
swap (&a,&b);
void swap(int *pa, int *pb) 
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

int a = 100;
int b = 200;
swap (a,b);
void swap(int &ra,int &rb);
{
	int tmp = ra;
	ra = rb;
	rb = tmp;
}
 

복사생성자는 인자의 타입이 콘스트 t타입의(임의의타입) 레퍼런스로 쓴다.
벨류로 그냥 쓰면 무한히 호출된다.

논리를 나타내는 bool타입.
bool b;
b = true;
b = false;

1. C++에서 one-interface-multi-method를 지원하기 위한 메커니즘 함수 중복, 기본인자에 대해서 설명하시오.
2. 포인터와 참조를 비교 설명하시오.
3. 복사 생성자를 설명하시오.
4. Complex 클래스를 위한 operator=(), operator==(), operator+()를 정의하시오.
 
 
 2020/7/8
 스트링카피.
char *str1 = newchar[20];
char *str2 = newchar[10];
strcpy(str1,"hello");
strcpy(str2,"greeting");

str1=str2; 
 . . .
delete[]str1;
delete[]str1;
 
포인터가 가르치는 값을 복사할려면 삭제하고 할당하고 내용복사 

shallow copy vs deep copy
-shallow copy 포인터가 가르키는 주소값만 복사하는것
-deep copy 포인터가 가르키는 데이터영역의 값을 삭제하고 다시 할당하여 내용을 복사하는것.

컴파일러가 자동적으로 만들어주는 멤버함수
1. 다른 생성자가 없는 경우 본체가 비어있는 디폴트 생성자 생성
2. 복사 생성자가 없으면 각각의 멤버를 치환하는 코드를 가지는 복사 생성자 생성
3. 소멸자가 없으면 본체가 비어있는 소멸자 생성
4. 치환연산이 없으면 각각의 멤버를 치호나하는 코드를 가지는 치환 연산 생성.
5. oprator&()
6  opretor&() const 

차이점. 
#include <string.h> 		//old C++
#include <cstring>		//strlen(),strcpy() ...
#include <string>			//std::string
 
 포인터 멤버를 가지는 클래스는 deep copy를 고려해서, 복사생성자, 소멸자, 치환연산을 꼭!!!! 만들어준다.
 컴파일러가 자동으로 만들어 주는 것을 사용하면 안된다.
  
 //m_re mRe re_ 맴버변수와 지역변수의 이름이 다르면 this->를 생략할수있다.
 //멤버변수와 인자 이름이 같으면 생략불가
 
 생성자 초기화 리스트
 
 const member func 
 
1. shallow copy 와 deep copy를 비교 설명하시오.
2. const member function에 대해서 설명하시오.
3. friend 함수에 대해서 설명하시오.

4. 다음 클래스에 컴파일러가 자동적으로 만드러주는 멤버함수에 대해서 설명하시오. 
 class Empty{};
5. String 클래스의 operator=() 멤버함수를 정의하시오.
 
static 전역
static 지역

클레스변수 클레스 안에 스테틱맴버로 들어간다

static member함수

std::ostream& operator<<(std::ostream& out, const String& rhs);

07/09

static 멤버

explicit

delete = 소멸자 + Free

7/13

1. 참조계수(reference counting)를 사용해서 String 클래스 만들기
- body 클래스인 StringRep 구현(stringRep.h stringRep.cpp)
- handle 클래스인 Srting 클래스의 다음 멤버 함수만 구현
	//String();
	String(const char *s);
	String(const String& rhs);
	~String();
	String& operator=(const String& rhs);
	bool operator==(const String& rhs) const;
	
7/17 
Class를 쓰고 접근지정자를 안쓰면 private가 되고
struct를 쓰면 public이 된다	

템플릿(template)
generic programming mechanism.

임의의 타입에 대응하는 코드를 작성
사용할 데이터 타입을 인자로 입력.
데이터 타입에 맞는 코드 생성

코드가 타입을 쓸때마다 늘어난다.
타입을 입력값으로 주면 소스 코드를 생성해낸다.
	
//클래스 이름 생성자 소멸자는 <T>는 안바꾼다.
	
array.cpp --> array.h 밑에쪽에 붙이기
array.cpp 삭제

header file에 있는 대상들에 
template  <typename T> 붙인다.

Array --> Array<T> but, 클래스 이름, 생성자, 소멸자 Array로 사용
내부에 저장되는 int타입을 --> 임의의 타입 T

main() 쪽에서
Array arr1; ---> Array<int> arr1;

상속 재사용성.

상속 reuse
프라이빗상속 
부모쪽의 퍼블릭이 자식쪽의 프라이빗으로.

퍼블릭상속
부보쪽의 퍼블릭이 자식쪽으로 퍼블릭으로

protected:		
//프라이빗 멤버 인데 자식쪽에서 접근할수있게
//메인은 접근안되고 자식은 접근가능

폴리모피즘 다형성 (polymorphism)
//부모클래스 타입의 포인터/레퍼런스는 자식클래스 타입의 객체를 가리키거나 참조할수있다.
	
//스테틱 바인딩 다이나믹 바인딩
static binding - compile time에 결정 
dynamic binding - run time에 결정 --> 가상함수 (virtual function)를 사용

포인터타입을 보고 결정나는데 실행시간에 결정하고싶을때 버추얼을 쓴다.	
클래스가 가상함수를 가지는 경우, 소멸자는 무조건 virtual이다
버추얼을 하나라도 가지면 소멸자는 무조건 버추얼

부모클래스 - base class(기본 클래스), super class
자식클래스 - derived class(기저 클래스), sub class

추상클래스(abstruct base class)
	shape 
	
객체지향 언어의 특징에 대해서 설명하시오
1. 캡슐화 (encapsulation) 
 정보은닉, 데이터와 관련된 연산을 
2. 정보은닉 (information hiding)
 데이터 하이딩 인포메이션 하이딩
3. 상속	(inheritance)
reuse
4. 추상화 (abstraction)
콘크리트하게
5. 다형성 (polymorphism)

6. RTTI

함수중복(function overloading)과 함수 재정의(function overriding) 에 대해서 비교설명하시오


 2 부모쪽에 있는 함수를 자식쪽에서 다시만드는거, 똑같이 생겨야한다,
 

 19/7/17
 inline 함수 ->한 라인에 집어넣는다. 함수랑 반대개념
 c++ 함수 호출 많이함. 함수의 본체가 한줄두줄일때 오버해드를 줄여서 성능개선을 한다.
 인자전달및 점프하는 이동을 줄이는 대신 사이즈가 커진다. 
 함수 본체의 사이즈가 길때, 복잡할때
 정의가 헤더파일에서 되야한다.
 클래스 정의할때 안에서할수도 있다. 인라인 안붙히고 정의해준다.
 남용하면 캐시메모리의 히트율이 떨어져서 성능이 떨어질수 있다. 
 
 
 Macro함수 (in C)
 #define MAX(a,b) \
 	( (a) > (b) ) ? (a) : (b)

int re = Max(5,4);
int re = ( (5) > (4) ) ? (5) : (4); //컴파일 하기전에 바뀐다. 함수호출의 오버해드가 없다.

int re = MAX(++i, j);
int re =  (++i) > (j) ) ? (++i) : (j) // ++i의 값이 바뀐다.

 new type casting(x4)
 
 -static_cast<???>(expr)
 -reinterpret_cast<???>(expr) 	--> 강제형변환 c에서 쓰는 캐스팅이랑 비슷하다
 -dynamic_cast<???>(expr)	  	--> 부보클래스를 자식타입으로 바꿀때 컴파일
 -const_cast<???>(expr)			--> const 붙히고 안붙히고.
 
 (???) expr
 
 int *p;
 int a;
 p = (int *)100;
 a = (int)&p;
 *(int *)a = 200;
 printf("%d",(int)p);
 
 int a = static_cast<int> (3.14);//써보고 안되면 강제형변환 reinterpret_cast
 
 
 memory pooling   // Thread pool
 공간을 미리 할당시켜놓고 사용하자. 링크드 리스트로 만들어서 관리를 한다.

 exception handling 
  



 
 
