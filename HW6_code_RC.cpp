//HW6 Threaded MergeSort
//Due:  Friday (11/23) at 11:59PM
//You need to create 4 new threads to perform merge_sort
//There will be totally 5 thread (4 + main thread).
//Your implementation is not required to be in-place implementation.

//Total Points: 30

#include <iostream>
#include <vector>
#include <thread>
using namespace std;

void merge_sort(vector<int> &V, int i, int j); //sort elements of vector V from position i to position j
void merge(vector<int> &V, int i1, int i2, int j1, int j2); //Merge vector elments from position i1 to position i2 with vector elements
															//from position j1 to position j2.
															//Note that elements from i1 to i2 are already sorted, and elements from j1 to j2 are
															//also sorted already.

int main() {
	int n = 100;
	vector<int> V(n);//V has n elements.
	for (int i = 0; i < n; i++) V[i] = rand() % 20;
	thread t1(merge_sort, ref(V), 0, 24);
	thread t2(merge_sort, ref(V), 25, 49);
	thread t3(merge_sort, ref(V), 50, 74);
	thread t4(merge_sort, ref(V), 75, 99);
	//merge_sort(V, 0, n-1);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	merge(V, 0, 24, 25, 49);
	merge(V, 50, 74, 75, 99);
	merge(V, 0, 49, 50, 99);
	for (int i : V) { cout << i << " "; }
	//You need to crate four threads to perform sorting
	//You need to then save the sorted result to output.txt
	getchar();
	getchar();
	return 0;
}

void merge_sort(vector<int> &V, int i, int j) {
	if (j - i < 1) return;
	merge_sort(V, i, i + (j - i) / 2);
	merge_sort(V, i + (j - i) / 2 + 1, j);
	merge(V, i, i + (j - i) / 2, i + (j - i) / 2 + 1, j);
}


void merge(vector<int> &V, int i1, int i2, int j1, int j2) {;
	vector<int> temp_V;
	int index1 = i1, index2 = j1;
	while (index1 <= i2 || index2 <= j2) {
		if (index1 > i2) { temp_V.push_back( V[index2]); index2++; }
		else if (index2 > j2) { temp_V.push_back(V[index1]); index1++; }
		else if (V[index1] < V[index2]) { temp_V.push_back(V[index1]); index1++; }
		else if (V[index1] > V[index2]) { temp_V.push_back(V[index2]); index2++;}
		else if (V[index1] == V[index2]) { temp_V.push_back( V[index1]); temp_V.push_back(V[index1]); index1++; index2++; }
	}
//for (int k : temp_V) { cout << k << " "; }
//cout << endl;
	
	for (int k = 0; k < i2 - i1 + 1; k++) {
		V[i1 + k] = temp_V[k];
	}
	for (int k = 0; k < j2 - j1 + 1; k++) {
		V[j1 + k] = temp_V[i2 - i1 + 1 + k];
	}
}

