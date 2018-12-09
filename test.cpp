#include <iostream>
#include <memory>
#include <vector>
using namespace std;


int main() {
	vector<int> vec1 = {1, 2,3, 4};
	shared_ptr<vector<int>> vec = make_shared<vector<int>>(vec1);
	for (size_t i = 0; i < vec->size(); i++) {
		cout << (*vec)[i] << endl;
	}
	return 0;
}