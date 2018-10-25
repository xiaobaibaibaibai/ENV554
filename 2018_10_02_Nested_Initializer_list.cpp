#include <iostream>
using namespace std;


class ThreeD {
public:
	int ht;
	int wid;
	int dep;
	
	ThreeD() {}
	ThreeD(int i, int j, int k) { ht = i + 1; wid = j + 1; dep = k + 1; }
	
	ThreeD(const initializer_list<int> &V) {
		auto it1 = V.begin();
		ht = *it1 * 2;
		it1++;
		wid = *it1 * 2;
		it1++;
		dep = *it1 * 2;
	}
	
	friend ostream & operator<<(ostream & str, ThreeD T);
};


class node {
public:
	ThreeD value;
	node * next;
	node * previous;
	node(ThreeD t) { value = t; next = previous = nullptr; }
};

class linked_list {
public:
	node * head;
	node * tail;
	linked_list() { head = tail = nullptr; }
	void push_back(ThreeD t);
	linked_list(const initializer_list<ThreeD> &V) {
		auto it1 = V.begin();
		while (it1 != V.end()) {
			push_back(*it1);
			it1++;
		}
	}
	void print() {
		node * p = head;
		cout << endl;
		while (p != nullptr) {
			cout << p->value << " ";
			p = p->next;
		}

	}
};

void linked_list::push_back(ThreeD t) {
	node * p = new node(t);
	if (tail != nullptr) { tail->next = p; p->previous = tail; tail = p; }
	else { head = tail = p; }
}

ostream & operator<<(ostream & str, ThreeD T) {
	str << "(" << T.ht << " , " << T.wid << " , " << T.dep << " ) ";
	return str;
}

int main() {

	linked_list L = { {3,4,5}, {7,8,9}, {10, 20, 30} };
	L.print();

	ThreeD t1 = { 1,2,3 }, t2(5, 6, 7);

	cout << t1 << " " << t2 << endl;

	cin.get();
	cin.get();

	getchar();
	getchar();
	return 0;
}