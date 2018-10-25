#include <iostream>
#include <vector>
#include <list>
#include <algorithm> //You need to include this to use the sort function on vector.
using namespace std;

bool comp(int * p1, int * p2) {
	return *p1 < *p2;
}

void f1(int k) { cout << k << endl; }

int main() {
	vector <int *> V = { new int(4), new int(3), new int(2), new int(1) };
	sort(V.begin(), V.end(), comp); //note that sort is not a member function for vector
	//Note that this sort function also works for array
	for (int * p : V) { cout << *p << " "; }
	cout << endl;

	


	
	list<int *> L = { new int(4), new int(3), new int(2), new int(1) };
	L.sort(comp); //note that sort is a member function for list
	for (int * p : L) { cout << *p << " "; }


	bool(*FuncVariable) (int * p1, int * p2);
	FuncVariable = comp;// function name carries the address of a function
	
	void(*FuncVariabl_1)(int);
	FuncVariabl_1 = f1;

	// getchar();
	// getchar();
	return 0;
}