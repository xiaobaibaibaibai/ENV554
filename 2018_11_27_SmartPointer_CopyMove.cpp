//destructor, copy constructor, move constructor, L-value operator=, R-value operator
#include <iostream>
#include <vector>
#include <memory>

using namespace std;
/*
Objects that can only be placed on right hand side of a statement is an R=value object
Objects that can be placed on either side of a statement is an L-value object.
Examples of R-value objects:  35, x+1, f(x), etc.
Examples of L-values: j
*/

class big_data {
public:
	shared_ptr<vector<int>> PV;
	big_data() {
		PV  = make_shared<vector<int>>();//the vector is empty with size 0
	}
	big_data(int i) {
		PV = make_shared<vector<int>>(i, 0);//vector contains i items with 0 as initial values
	}

	/*
	//destructor is no longer needed when using smart pointer
	~big_data() { //destructor
		delete[] big_array;
		cout << "Leaving destructor!" << endl;
	}
	*/

	big_data(const big_data &X) { //copy constructor
		
		PV = make_shared<vector<int>>(*X.PV);


								  //notice the use of const and & 
				  //if X is L-value
		cout << "Leaving copy constructor!" << endl;
	}

	big_data(big_data &&X) { //move constructor
							 //if X is R-value
		PV = X.PV;
		X.PV.reset();
		cout << "Leaving move constructor!" << endl;
	}

	void create_random_array(int m, int n) {
		PV->resize(m);
		for (size_t i = 0; i < PV->size(); i++) (*PV)[i] = rand() % n;
	}
	void print() {
		cout << endl;
		for (size_t i = 0; i < PV->size(); i++) cout << (*PV)[i] << " ";
		cout << endl;
		
	}
	big_data three_times() {
		big_data temp(PV->size());
		for (size_t i = 0; i < PV->size(); i++) {
			(*temp.PV)[i] = 3 * (*PV)[i];
		}
		return move(temp);//return by value -- will invoke copy constructor to create a hidden copy
						  // move change an object from L-value to R-value
	}

	void operator=(const big_data &X) { //L-value version
		*PV = *X.PV;
		cout << "Leaving L-value operator= !" << endl;
	}

	void operator=(big_data &&X) { //if X is an R-value
		PV = X.PV;
		X.PV.reset();
		cout << "Leaving R-value operator= !" << endl;
	}

};

void f1(big_data B) { //call by value; will invoke copy constructor
	big_data B1 = B;
	cout << B1.PV->size() << " " << (*B1.PV)[3] << endl;
}

int main() {
	big_data B1, B2;
	B1.create_random_array(20, 30);
	B1.print();
	B2 = B1;//only copy top level data
			//operator=
			//B2.operator=(B1);  L-value operator=

	B2.print();
	(*B1.PV)[10] = 1000;
	B2.print();

	
	big_data B3(B1); //will invoke copy constructor
					 //equivalently, big_data B3 = B1;
	(*B1.PV)[15] = 2000;
	B3.print();
	big_data B4;
	B4 = B1.three_times();
	//B4.operator=(B1.three_times());
	//R-vauie operator=
	B4.print();
	//big_data * p1 = &B2; //will cause error with delete p1;
	//big_data * p1 = new big_data(5);
	//delete p1;

	f1(B1);

	getchar();
	getchar();
	return 0;
}