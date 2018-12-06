
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
	linked_list(const linked_list & L); //copy constructor
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

linked_list::linked_list(const linked_list & L): linked_list(){//copy constructor
	// node * p1 = L.head, *p2;
	// while (p1 != nullptr) {
	// 	p2 = new node();
	// 	p2->next = head;
	// 	head = p2;
	// 	p1 = p1->next;
	// }
	// p1 = head;
	// p2 = L.head;
	// while (p2 != nullptr) {
	// 	p1->value = p2->value;
	// 	p1 = p1->next;
	// 	p2 = p2->next;
	// }

	node *p1 = L.head, *p2 = new node(-1);
	while (p1 != nullptr) {
		node *p3 = p2;	
		p2 = new node(p1 -> value);
		p3 -> next = p2;
		if (head == nullptr)
			head = p2;
		p1 = p1 -> next;
	}
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
	linked_list L2(L1);
	cout << L1 << endl;  //overload <<
						 //cin >> L1 ;

	cout << L2 << endl;

	// getchar();
	// getchar();
	return 0;
}