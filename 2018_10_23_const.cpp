//const
#include <iostream>
using namespace std;


int main() {
	int P = 10, Q = 100, R = 1000, S = 5000;
	int * p1 = &R;
	cout << "p1 : " << *p1 << endl;

	const int * p2 = &P;
	//the object pointed by p2 is const
	cout << "p2 : " << *p2 << endl;

	int const * p3 = &P; //the same as const int * p3 = &P;
	cout << "p3 : " << *p3 << endl;
	p3 = &Q;
	//*p3 = 5000;  error
	cout << "p3 : " << *p3 << endl;

	int * const p4 = &Q;
	//pointer is const
	cout << "p4 : " << *p4 << endl;
	*p4 = 5000;
	//p4 = &P;  error
	cout << "p4 : " << *p4 << endl;

	const int * const p5 = &P;
	//both pointer and the object pointed by pointer are const

	//void f1(const int i) ...
	//call by value; use copy constructor to create a local object i;
	//i is read-only
	//

	//void f(const int &i) ...
	//call by ref; i is read only
	//
	//void f(...) const {...}
	//only for member function of a class
	//all members of the class are read only




	cin.get();//identical to getchar();
	cin.get();
	return 0;
}