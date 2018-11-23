//namespace
#include <iostream>
#include "Header1.h"
using namespace std;

int x = 40;
namespace one {
	int x = 10;
	//void fun() { cout << 500 << endl; }
}

namespace two {
	class C
	{
	public:
		int C1;

	};
	int x = 20;
}

//using namespace two;
int main() {

	//int x = 50;
	//local variables declaration always control

	{
		//using namespace one;
		std::cout << one::x << std::endl;//:: will refer to global variable

	}

	{
		//using namespace two;
		std::cout <<two:: x << std::endl;//:: will refer to global variable

	}
	two::C  x1;
	cout << three::x << std::endl;
	cout << ::x << endl;
	getchar();
	getchar();
	return 0;
}
/*
//header1.h
namespace three {
	int x = 30;

}
*/