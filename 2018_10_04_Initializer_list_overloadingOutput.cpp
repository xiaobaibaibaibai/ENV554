
#include <iostream>
using namespace std;

class node {
public:
	int value;
	node * next;
	node(int i) { value = i; next = nullptr; }
	node() { next = nullptr; }
};
class linked_list {
public:
	node * head;
	linked_list() { head = nullptr; }
	linked_list(const initializer_list<int> &V);
	friend ostream & operator<< (ostream &str, const linked_list &L);
};
linked_list::linked_list(const initializer_list<int> &V) {
	auto it1 = V.end() - 1;
	while (it1 != V.begin()) {
		node * p = new node(*it1);
		p->next = head;
		head = p;
		it1--;
	}
	node * p = new node(*it1);
	p->next = head;
	head = p;
}

ostream & operator<< (ostream &str, const linked_list &L) {
	str << "[";
	node * p = L.head;
	while (p != nullptr) {
		str << p->value;
		if (p->next != nullptr) cout << ", ";
		p = p->next;
	}
	str << "]";
	return str;
}


int main() {

	linked_list L1 = { 5,20,32,99 };//initializer_list
	linked_list L2;
	cout << L1 << endl;  //overload <<
						 //cin >> L1 ;

	// getchar();
	// getchar();
	return 0;
}