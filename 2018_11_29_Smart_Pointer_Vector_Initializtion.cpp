#include <iostream>
#include <memory>
#include <vector>

using namespace std;
int main() {
	vector<int> * P0 = new vector<int>({ 1,2,3,4,5 });//vector 1

	shared_ptr<vector<int>> P1 = make_shared<vector<int>>(*P0); //vector 2 and vector with same values
	shared_ptr<vector<int>> P2(P0); //only one vector -- vector 1

	//P2 = P1; This line will cause the vector pointed by PO be deleted.
	//because the reference count becomes zero.
	cout << (*P0)[2] << endl;

	//the following three statements perform the same task
	cout << (*P2.get())[2] << endl;
	cout << (*P2)[2] << endl;
	cout << (*P0)[2] << endl;

	getchar();
	getchar();
	return 0; //exit(0);
}
