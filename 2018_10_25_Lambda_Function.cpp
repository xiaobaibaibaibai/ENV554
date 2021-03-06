#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;


class Three_D {
public:
	int ht;
	int wid;
	int dep;
	Three_D(int i, int j, int k) { ht = i; wid = j; dep = k; }
	bool operator<(Three_D T) { return ht * wid*dep < T.ht*T.wid*T.dep; }
};

bool f_sort(Three_D T1, Three_D T2) { return T1.ht + T1.wid + T1.dep < T2.ht + T2.wid + T2.dep; }

int main() {
	list<int> L1 = { 6, 3, 11, 2, 1 };
	L1.sort();
	for (int ll : L1) {
		cout << ll << " ";
	}
	cout << endl;

	
	vector<int> V1 = { 6, 3, 11, 2, 1 };
	sort(V1.begin(), V1.end());
	for (int vv : V1) {
		cout << vv << " ";
	}
	cout << endl;
	
	Three_D T1(3, 4, 5), T2(5, 1, 2), T3(2, 1, 8);
	vector<Three_D> V2 = { T1, T2,  T3 };
	sort(V2.begin(), V2.end());
	sort(V2.begin(), V2.end(), f_sort);
	sort(V2.begin(), end(V2), [](Three_D T1, Three_D T2) {return T1.ht + T1.wid + T1.dep < T2.ht + T2.wid + T2.dep; });
	//lambda function allows in-line function definition and insersion.

	int i = 5;
	int j = 10;
	int k = 40;



	auto LF1 = [i, &j, &k](int c, int d) -> int {
		//i is read only
		//j, k allow both read and write
	
		
		j++;//j allows both read and write
		//i++;  Error!  i is read only.
		
		cout << "i : " << i << endl;
		cout << "j : " << j << endl;
		cout << "k : " << k << endl;
		cout << "c : " << c << endl;
		cout << "d : " << d << endl;

		return i + j + k + c + d;
	};
	i = 100;
	j = 200;
	k = 300;

	cout << LF1(20, 30) << endl;



	getchar();
	getchar();
	return 0;

}