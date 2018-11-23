//HW6 Threaded MergeSort
//Due:  Friday (11/23) at 11:59PM
//You need to create 4 new threads to perform merge_sort
//There will be totally 5 thread (4 + main thread).
//Your implementation is not required to be in-place implementation.

//Total Points: 30

#include <iostream>
#include <vector>
#include <thread>
#include <fstream>
using namespace std;


void merge_sort(vector<int> &V, int i, int j); //sort elements of vector V from position i to position j
void merge(vector<int> &V, int i1, int i2, int j1, int j2); //Merge vector elments from position i1 to position i2 with vector elements
                                                            //from position j1 to position j2.
							    //Note that elements from i1 to i2 are already sorted, and elements from j1 to j2 are
							    //also sorted already.


void merge_sort(vector<int> &V, int i, int j) {
	if (i < j) {
		int mid = (i + j) / 2;
		merge_sort(V, i, mid);
		merge_sort(V, mid+1, j);
		merge(V, i, mid+1, mid, j);
	}
}

void merge(vector<int> &V, int i1, int i2, int j1, int j2) {
	int n1 = j1 - i1 + 1;
	int n2 = j2 - i2 + 1;
	vector<int> v1(n1);
	vector<int> v2(n2);

	for (int i = 0; i < n1; i++) {
		v1[i] = V[i + i1];
	}
	for (int j = 0; j < n2; j++) {
		v2[j] = V[j + i2];
	}

	int k1 = 0, k2 = 0, vi = i1;
	while (k1 < n1 && k2 < n2) {
		if (v1[k1] < v2[k2]) {
			V[vi] = v1[k1];
			k1++;
		} else {
			V[vi] = v2[k2];
			k2++;
		}
		vi++;
	}

	while (k1 < n1) {
		V[vi] = v1[k1];
		k1++;
		vi++;
	}
	while (k2 < n2) {
		V[vi] = v2[k2];
		k2++;
		vi++;
	}
}


void output(vector<int> &V, int i) {
	V[i] = i;
}



int main() {
	int n = 100000;
	vector<int> V(n);//V has n elements.
	for (int i = 0; i < 100000; i++) V[i] = rand() % 5000;
	//You need to creat four threads to perform sorting
	//You need to then save the sorted result to output.txt
	

	thread t1(merge_sort, ref(V), 0, n/4 - 1);
	thread t2(merge_sort, ref(V), n/4, n/2 - 1);
	thread t3(merge_sort, ref(V), n/2, n -n/4 - 1);
	thread t4(merge_sort, ref(V), n -n/4, n-1);
	t1.join();
	t2.join();
	t3.join();
	t4.join();

	merge(V, 0, n/4, n/4 - 1, n/2 - 1);
	merge(V, n/2, n - n/4, n - n/4 - 1, n-1);
	merge(V, 0, n/2, n/2 - 1, n - 1);

	ofstream out1("output.txt");
	for (int i = 0; i < n; i++) {
		out1 << V[i] << " ";
	}
	out1.close();



}