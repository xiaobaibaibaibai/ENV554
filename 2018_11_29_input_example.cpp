#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {

	ifstream in("data1.txt");
	string T, s, s1, s2, s3;
	getline(in, s1);
	getline(in, s2);
	getline(in, s3);
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	while (!in.eof()) {
		getline(in, s);
		cout << s;
		T.append(s);
	}
	cout << T << endl;
	in.close();
	cin.get();
	cin.get();
	return 0;
	
}