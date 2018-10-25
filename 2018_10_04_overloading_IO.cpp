

#include <iostream> //cin, cout
using namespace std;

class ThreeD {
public:
	int ht;
	int wid;
	int dep;
	//constructor
	ThreeD(int i, int j, int k) { ht = i * i; wid = j * j; dep = k * k; }
	ThreeD() {}//default constructor
	int vol() { return ht * wid * dep; }
	ThreeD operator+ (ThreeD const &D);
	bool operator<(ThreeD &D) { return vol() < D.vol(); }
	int & operator[](int k);
	ThreeD operator++();//prefix
	ThreeD operator++(int never_used);//postfix
									  //by seeing the unused int argument, compiler will know 
									  //that this is a postfix implementation
	friend ostream & operator<< (ostream & str, const ThreeD &T);
	friend istream & operator>> (istream & str, ThreeD &T);


};

ThreeD ThreeD::operator+(ThreeD const &D) {
	ThreeD temp;
	temp.ht = ht + D.ht;
	temp.wid = wid + D.wid;
	temp.dep = dep + D.dep;
	return temp;
}

int & ThreeD::operator[](int k) { //notice the 
								  //funciton returns a reference
								  // the reference type allows the return of the function to
								  // appear on the left_hand_side of a statement.
	switch (k) {
	case 0: return ht;
	case 1: return wid;
	case 2: return dep;

	}
}
ThreeD ThreeD::operator++() {//prefix
	++ht;
	++wid;
	++dep;
	return *this;
}


ThreeD ThreeD::operator++(int never_used) { //postfix
	ThreeD temp = *this;
	ht++;
	wid++;
	dep++;
	return temp;
}

ostream & operator<< (ostream & str, const ThreeD &T) {
	str << "(" << T.ht << ", " << T.wid << ", " << T.dep <<")";
	return str;
}

istream & operator>> (istream & str, ThreeD &T) {
	str >> T.ht >> T.wid >> T.dep;
	return str;
}


int main() {
	//default initializer_list


	ThreeD d1 = { 3, 4, 5 }, d2 = { 6,7,8 }, d3, d4;
	d3 = d1 + d2;
	
	//compiler will convert it into
	//d3 = d1.operator+(d2);
	if (d1 < d2) 
		cout << d1.vol() << " " << d2.vol() << endl;
	else 
		cout << d2.vol() << " " << d1.vol() << endl;
	
	d3[2] = 10;
	//equivlent to d3.dep = 10;
	cout << d3[2] << endl;

	int i = 20;
	int & k = i; //the same variable also has a nickname k
	d3++; //postfix
	++d1; //prefix

		  // . , *, ->


	ThreeD d6 = { 5,6,7 };

	ThreeD * p1 = &d6;

	(*p1).ht = 1000;
	p1->dep = 2000;

	cout << d1 << endl;

	cin >> d1;
	cout << d1 << endl;

	// getchar();
	// getchar();

	return 0;
}

