#include <iostream>
#include <iomanip>
using namespace std;  // std:: 을 생략할수있다.

ostream& general (ostream& ostr) {
	ostr.setf(ios_base::fmtflags(0), ios_base::floatfield);	
	return ostr;
}



int main (int, char**) {
	int i = 12345;	double d = 3.1415;
	
	cout << setfill('_') << showbase;
	cout << setw(11) << dec << i;
	cout << setw(11) << oct << i;
	cout << setw(11) << hex << i << endl;
	cout << setprecision(3);
	cout << general 		<< d << "  ";
	cout << scientific	<< d << "  ";
	cout << fixed			<< d << endl;
}
