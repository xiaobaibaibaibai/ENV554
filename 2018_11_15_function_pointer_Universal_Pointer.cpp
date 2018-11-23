//passing function as parameter
//void *
#include <iostream>
using namespace std;

bool comp1(int i, int j) {
	return (i < j);
}


bool comp2(int i, int j) {
	return ((i + 101) < 2 * j);

}
void max(int m, int n, bool(*p)(int i, int j)) {
	if (p(m, n)) cout << n << endl;
	else cout << m << endl;
}

int main() {

	int m = 100, n = 200;
	max(m, n, comp1);
	max(m, n, comp2);
	
	bool(*Q) (int i, int j);  //Q is a pointer to a function, which has returns bool and take two
	//arguments int i, int j
	Q = comp1;

	max(m, n, Q);

	void * p1;// p1 is a pointer of universal data type
	p1 = &m;
	cout << *((int *) p1) << endl; //type casting is required to use univeral pointers

	char c1 = 'W';
	p1 = &c1;
	cout << *((char *)p1) << endl;

	char * p2;
	p2 = (char *) p1;


	getchar();
	getchar();
	return 0;


}