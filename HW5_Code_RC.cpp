
//CIS554 HW5 Due: Wednesday (11/7) at 11:59pm.
//Implment insertion sort using smart pointers.
//You are not allowed to swap node values; instead, you are only
//allowed to change pointer addresses.
//Will explain more on this in class.


#include <iostream>
#include <memory>
using namespace std;
class node {
public:
	int value;
	//node * next;
	//node * previous;
	shared_ptr<node> next;
	weak_ptr<node> previous;
	//node(int i) { value = i; next = previous = nullptr; }
	node(int i) { value = i;}
	//node() { next = previous = nullptr; }
	node() {}
};

class doubly_linked_list {
public:
	//node * head;
	//node * tail;
	shared_ptr<node> head, tail;
	//doubly_linked_list() { head = tail = nullptr; }
	doubly_linked_list() {}
	void make_random_list(int m, int n);
	void print_forward();
	void print_backward();

	//***************************
	//You need to implement insertion_sort following the 
	//special requirements.
	void insertion_sort();
};

void doubly_linked_list::make_random_list(int m, int n) {

	for (int i = 0; i < m; i++) {
		//node * p1 = new node(rand() % n);
		shared_ptr<node> p1 = make_shared<node>(rand() % n);
		p1->previous = tail;
		//if (tail != nullptr ) tail->next = p1;
		if (tail) tail->next = p1;
		tail = p1;
		//if (head == nullptr) head = p1;
		if (!head) head = p1;
	}
}

void doubly_linked_list::print_forward() {
	cout << endl;
	//node * p1 = head;
	shared_ptr<node> p1 = head;
	//while (p1 != nullptr) {
	while (p1) {
		cout << p1->value << " ";
		p1 = p1->next;
	}
}

void doubly_linked_list::print_backward() {
	cout << endl;
	//node * p1 = tail;
	shared_ptr<node> p1 = tail;
	//while (p1 != nullptr) {
	while (p1) {
		cout << p1->value << " ";
		p1 = p1->previous.lock();
	}
}


void doubly_linked_list::insertion_sort() {
	//Using insertion sort
	if (!head  || !(head->next) ) return;
	//node * p1 = head->next, *p2;
	shared_ptr<node> p1 = head->next, p2, p3;
	int temp;
	while (p1) {
		p3 = p1->next;
		p2 = p1;
		temp = p1->value;
		while (!p2->previous.expired() && temp < p2->previous.lock()->value) {
			p2 = p2->previous.lock();
		}
		if (p2 == p1){}
		else if (p2->previous.expired()) {
			p1->previous.lock()->next = p1->next;
			if (p1->next) { p1->next->previous = p1->previous; }
			if (p1 == tail) tail = p1->previous.lock();
			head->previous = p1;
			p1->next = head;
			p1->previous.reset();
			head = p1;
		}
		else {
			p1->previous.lock()->next = p1->next;
			if (p1->next) { p1->next->previous = p1->previous; }
			if (p1 == tail) tail = p1->previous.lock();
			p2->previous.lock()->next = p1;
			p1->previous = p2->previous;
			p1->next = p2;
			p2->previous = p1;
		}
		p1 = p3;
	}
}

int main() {
	doubly_linked_list d1;
	d1.make_random_list(30, 10);
	d1.print_forward();
	d1.print_backward();
	d1.insertion_sort();
	d1.print_forward();
	d1.print_backward();
	getchar();
	getchar();
	return 0;
}


