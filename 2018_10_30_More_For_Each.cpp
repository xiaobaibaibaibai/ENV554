#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <string>

using namespace std;
void f1(int &i);
void f2(int & i);

 int main() {
	 
	 int k = 10;
	 f2(k);
	 cout << k << endl;
	 
	 int sum = 0;
	 vector<int> V1({ 1,2,3,4,5 });
	 for (int &i : V1) { i = 10; }
	 cout << V1[0] << endl;

	 list<int> L1({ 1,2,3,4,5 });
	 for (int &i : L1) { i = 10; }
	 cout << L1.front() << endl;

	 string S1("A very good example");
	 for (char &i : S1) {
		 i = toupper(i);
	 }
	 cout << S1 << endl;

	 int A[] = { 1,2,3,4,5 };
	 for (int &i : A) { i += 50; }
	 cout << A[0] << endl;
	 int i = 10;
	 auto func1 = [i](int a) -> int {return a + i; };

	 cout << func1(100) << endl;
	 
	 pair<int, string> p1 = { 5, "steve" };
	 cout << p1.second << endl;

	 map<int, string >  M1 = { {1, "steve"}, {2, "pat"}, {3, "Dave"}};
	 for (auto &m : M1) { m.second = "XXXX"; }
	 for (pair<int, string> &m1 : M1) { m1.second = "ZZZZ"; }


	 cout << M1.begin()->second << endl;
	 for (auto &m : M1) {
		 cout << m.first << " " << m.second;
	 }


	//out << (5 >>2)<< endl;

	 
	 getchar();
	 getchar();
	 return 0;
 }

 void f2(int & i) { f1(i); }
 void f1(int &i) { i += 10; }


 