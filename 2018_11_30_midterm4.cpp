#include <iostream>
#include <map>
using namespace std;

class node {
public:
	int * value_p;
	node * next;
	node(int p) { value_p = new int(p); next = nullptr; }

};

class linked_list {
public:
	node * head;
	linked_list() {  head = nullptr; }
	linked_list(const initializer_list<int> &V);
	// void reverse() {
	// 	if (head == nullptr) return;
	// 	node * p1 = head, *p2, *p3;
	// 	p2 = p1->next;
	// 	while (p2 != nullptr) {
	// 		p3 = p2->next;
	// 		p2->next = p1;
	// 		if (p1 == head) p1->next = nullptr;
	// 		p1 = p2;
	// 		p2 = p3;
	// 	}
	// 	head = p1;
	// }
	void reverse();
	void print() {
		cout << endl;
		auto p = head;
		while (p != nullptr) {

			cout << *(p->value_p) << " ";
			p = p->next;
		}
	}

};

linked_list::linked_list(const initializer_list<int> &L) {
	head = nullptr;
	auto it = L.begin();
	auto p1 = new node(-1);
	while (it != L.end()) {
		auto p2 = p1;
		p1 = new node(*it);
		if (head == nullptr) {
			head = p1;
			delete p2;
		} else {
			p2 -> next = p1;
		}
		it++;
	}
}

void linked_list::reverse() {
	node * p1 = head, *p2 = nullptr, *p3;
	while (p1 != nullptr) {
		p3 = p1 -> next;
		p1 -> next = p2;
		p2 = p1;
		p1 = p3;
	}
	head = p2;
}

int main() {
	linked_list L = { 1, 2,3,4,5 };
	L.print();
	L.reverse();
	L.print();
	getchar();
	getchar();
	return 0;
}
//The following is screenshot of the above code
/*

1 2 3 4 5
5 4 3 2 1
*/
