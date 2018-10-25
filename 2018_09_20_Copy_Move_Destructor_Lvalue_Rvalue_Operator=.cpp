//destructor, copy constructor, move constructor, L-value operator=, R-value operator
#include <iostream>
using namespace std;
/*
Objects that can only be placed on right hand side of a statement is an R=value object
Objects that can be placed on either side of a statement is an L-value object.
Examples of R-value objects:  35, x+1, f(x), etc.
Examples of L-values: j
*/

class big_data {
public:
	int size;
	int * big_array;
	big_data() { size = 0; big_array = nullptr; }
	big_data(int i) {
		size = i;
		big_array = new int[size];
		for (int j = 0; j < size; j++) big_array[j] = 0;
	}
	~big_data() { //destructor
		delete[] big_array;
		cout << "Leaving destructor!" << endl;
	}

	big_data(const big_data &X) { //copy constructor
								  //notice the use of const and & 
								  //if X is L-value
		size = X.size;
		big_array = new int[size];
		for (int i = 0; i < size; i++) big_array[i] = X.big_array[i];
		cout << "Leaving copy constructor!" << endl;
	}

	big_data(big_data &&X) { //move constructor
							 //if X is R-value
		size = X.size;
		big_array = X.big_array;
		X.big_array = nullptr;
		cout << "Leaving move constructor!" << endl;
	}

	void create_random_array(int m, int n) {
		size = m;
		big_array = new int[size];
		for (int i = 0; i < size; i++) { big_array[i] = rand() % n; }
	}
	void print() {
		cout << endl;
		for (int i = 0; i < size; i++) {
			cout << big_array[i] << " ";
		}
		cout << endl;
	}
	big_data three_times() {
		big_data temp(size);
		for (int i = 0; i < size; i++) {
			temp.big_array[i] = 3 * big_array[i];
		}
		return move(temp);//return by value -- will invoke copy constructor to create a hidden copy
						  // move change an object from L-value to R-value
	}

	void operator=(const big_data &X) { //L-value version
		delete[] big_array;
		size = X.size;
		big_array = new int[size];
		for (int i = 0; i < size; i++) big_array[i] = X.big_array[i];
		cout << "Leaving L-value operator= !" << endl;
	}

	void operator=(big_data &&X) { //if X is an R-value
		delete[] big_array;
		size = X.size;
		big_array = X.big_array;
		X.big_array = nullptr;
		cout << "Leaving R-value operator= !" << endl;
	}

};

int main() {
	big_data B1, B2;
	B1.create_random_array(10, 30);
	cout << "B1";
	B1.print();
	B2 = B1;//only copy top level data
			//operator=
			//B2.operator=(B1);  L-value operator=

	cout << "B2";
	B2.print();
	B1.big_array[10] = 1000;
	B2.print();

	cout << "B3" << endl;
	big_data B3(B1); //will invoke copy constructor
					 //equivalently, big_data B3 = B1;
	B1.big_array[15] = 2000;
	B3.print();

	big_data B4;
	B4 = B1.three_times();
	//B4.operator=(B1.three_times());
	//R-vauie operator=

	// getchar();
	// getchar();
	return 0;
}