#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <string>
using namespace std;
int main() {
	//The following all carry the nototation of a 2-dimensional array
	int A[5][5];
	A[2][3] = 45;
	vector<vector<int>> V1{ {1,2}, {3,4,5},{7, 8, 9, 10} };
	V1[2][1] = 45;
	map<int, vector<int>> M1 = { 
			{2, 
				{1, 2}
			}, 
			{1, 
				{3,4,5}
			}, 
			{0, 
				{4, 9, 10, 11}
			} 
		};
	M1[1][2] = 45;
	vector< map<int, int>> V2 = { { {3, 3}, {4,4}, {5, 5}, {6,6}}, {{4,4}, {5,5}, {6,6}, {7,7}} };
	V2[1][5] = 45;
	map<int, map<int, int>> M2 = {
		{1, { { 3, 3 },{ 4,4 },{ 5, 5 },{ 6,6 } }},
		{ 2,{ {  3, 3 },{ 4,4 },{ 5, 5 },{ 6,6 } }}  };
	M2[2][4] = 45;

	cout << M1[1][0] << "  " << M1[1][1] << "  " << M1[1][2] << "  " << M1[2][1] << endl;
	cout << M2[2][5] << "  " << M2[2][1] << "  " << M2[2][2] << "  " << M2[2][3] << "  " << M2[2][4] << endl;
	cout << M2[2].size() <<endl;
	// getchar();
	// getchar();
	return 0;
}