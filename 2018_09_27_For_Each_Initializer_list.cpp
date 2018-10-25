#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
using namespace std;
class ThreeD {
public:
	int ht;
	int wid;
	int dep;
	ThreeD(int i, int j, int k): ht(k), wid(j), dep(i){}
	ThreeD() { ht = wid = dep = 0; }
	ThreeD(const initializer_list<int> & V);
};

ThreeD::ThreeD(const initializer_list<int> & V) {
	auto it1 = V.begin();
	ht = *it1;
	it1++;
	wid = *it1;
	it1++;
	dep = *it1;
}

class node {
public:
	int value;
	node * next;
	node * previous;
	node(int i) { value = i; next = previous = nullptr; }
	node() { previous = next = nullptr; }

};

class linked_list {
public:
	int num_nodes;
	node * head, *tail;
	linked_list() { num_nodes = 0; tail = head = nullptr; }
	void make_list(int m, int n);
	void push_back(int);
	linked_list(const initializer_list<int> &V);
	friend ostream & operator<<(ostream &stream, linked_list & L);

};
linked_list::linked_list(const initializer_list<int> &V) :linked_list() {
	
	auto it1 = V.begin();
	cout << "first is " << (*it1) << endl;
	while (it1 != V.end()) {
		push_back(*it1);
		it1++;
	}
}
void linked_list::push_back(int k) {
	node *p = new node(k);
	if (num_nodes == 0) { head = tail = p; num_nodes++; return; }
	p->previous = tail;
	tail->next = p;
	tail = p;
	num_nodes++;
}


void linked_list::make_list(int m, int n) {
	for (int i = 0; i < n; i++) {
		node * p = new node(rand() % m);
		p->next = head;
		head = p;
	}
}

ostream & operator<<(ostream &stream,  linked_list & L) {
	node * p = L.head;
	while (p != nullptr) {
		stream << p->value << " ";
		p = p->next;
	}
	return stream;
}

int main() {
	
	int i = 10, j = 20;

	//auto F1 = [&, j] //[&] //[=] //[=,&i]
	int sum = 0;
	vector<int> V1 = { 1,2,3,4,5 };
	for (int i : V1) { sum += i; }
	// cout << sum << endl;
	
	for (int &i : V1) { i += 3; cout << i << endl; }
	/*
	sum = 0;
	list<int> L1 = { 1,2,3,4,5 };
	for (int i : L1) { sum += i; }
	cout << sum << endl;
	for (int &i : L1) { i += 3; cout << i << endl; }
	
	map<int, string> M1 = { {1, "Chen"}, {2, "Patel"}, {3, "Trump"} };
	for (auto i : M1) { cout << i.second << endl; }

	string S1 = "this is interesting!";
	for (char i : S1) { cout << (char) toupper(i); }

	int AA[] = { 1,2,3,4,5 };
	for (int i : AA) { i += 10; cout << i << endl; }
	


	ThreeD T3 = { 1,2,3 };
	ThreeD T1 = { 4, 5,6 };
	//Preference: initializer_list > constructor> aggregate initialization

	linked_list L1 = {1,2,3,4,5 };
	cout << L1 << endl;

	node n1 = { 10 };
*/
	// getchar();
	// getchar();
	return 0;
}