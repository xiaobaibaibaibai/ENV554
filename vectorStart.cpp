//standard template library (STL)
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

class course {
public:
	string name; //such as "CIS554"
	int section;
	int credits;
	course(string n, int s, int c) { name = n; section = s; credits = c; }

};


int main() {
	vector<int> v1 = { 4,5,6,7 };
	course c1("CIS554", 1, 3), c2("CSE674", 1, 3), c3("MAT296", 7, 4), c4("PED121", 20, 1);
	vector<course> v2 = { c1, c2,c3,c4 };
	v2.pop_back();
	cout << v2.size() << endl;
	v2.push_back(c1);
	cout << v2.size() << endl;

	getchar();
	getchar();
	return 0;
}


