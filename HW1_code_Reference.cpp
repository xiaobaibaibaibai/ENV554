//CIS554 HW1
//Due: 11:59PM, Friday (9/14)

#include <iostream>
using namespace std;

class node {
public:
	int value;
	node * next;
	node * previous;
	node(int i) { value = i; next = previous = nullptr; }
	node() { next = previous = nullptr; }
};

class doubly_linked_list {
public:
	node * head;
	node * tail;
	doubly_linked_list() { head = tail = nullptr; }
	void make_random_list(int m, int n);
	void print_forward();
	void print_backward();

	//inplement the following member functions:

	void remove_one(int k); //remvoe the first node with value k
	void remove_all(int k); //remove all nodes with value k
	void reverse();//reverse the order of the list
	void sort(); //sort the nodes in ascending order
	void insert(int k); //insert a node to an already sorted list
};

void doubly_linked_list::make_random_list(int m, int n) {

	for (int i = 0; i < m; i++) {
		node * p1 = new node(rand() % n);
		p1->previous = tail;
		if (tail != nullptr) tail->next = p1;
		tail = p1;
		if (head == nullptr) head = p1;
	}
}

void doubly_linked_list::print_forward() {
	cout << endl;
	node * p1 = head;
	while (p1 != nullptr) {
		cout << p1->value << " ";
		p1 = p1->next;
	}
}

void doubly_linked_list::print_backward() {
	cout << endl;
	node * p1 = tail;
	while (p1 != nullptr) {
		cout << p1->value << " ";
		p1 = p1->previous;
	}
}

void doubly_linked_list::remove_one(int k) {
	if (head == nullptr) return;
	if (head->value == k) {
		node * p = head;
		head = head->next;
		delete p;
		if (head != nullptr) {
			head->previous = nullptr;
		}
		if (head == nullptr) tail = nullptr;
		return;
	}
	node  *p1 = head->next;
	while (p1 != nullptr) {
		if (p1->value == k) {
			p1->previous->next = p1->next;
			if (p1->next != nullptr) p1->next->previous = p1->previous;
			delete p1;
			return;
		}
		p1 = p1->next;
	}
}

void doubly_linked_list::reverse() {
	if (head == nullptr || head->next == nullptr) return;
	node * p1 = head, *p2;
	while (p1 != nullptr) {
		 p2 = p1->next;
		 p1->next = p1->previous;
		 p1->previous = p2;
		 p1 = p2;

	}
	p2 = head;
	head = tail;
	tail = p2;
}

void doubly_linked_list::remove_all(int k) {
	if (head == nullptr) return;
	node * p1 = head, *p2;
	while (p1 != nullptr) {
		p2 = p1->next;
		if (p1->value == k) {
			if (p1->next != nullptr) { p1->next->previous = p1->previous; }
			if (p1->previous != nullptr) { p1->previous->next = p1->next; }
			if (tail == p1) { tail = p1->previous; }
			if (head == p1) { head = p1->next; }
			delete p1;
		}
		p1 = p2;
	}
}

void doubly_linked_list::sort() {
	//Using insertion sort
	if (head == nullptr || head->next == nullptr) return;
	node * p1 = head->next, *p2;
	int temp;
	while (p1 != nullptr) {
		p2 = p1;
		temp = p1->value;
		//cout << "value = " << p1->value << endl;
		while (p2->previous != nullptr && temp < p2->previous->value) {
				p2->value = p2->previous->value;
				p2 = p2->previous;
		}
		p2->value = temp;
		p1 = p1->next;
	}
}


void doubly_linked_list::insert(int k) {
	node *p1 = new node(k);
	if (head == nullptr) {
		head = tail = p1; 
		return;
	}
	if (k < head->value) {
		head->previous = p1;
		p1->next = head;
		head = p1;
		return;
	}
	node *p2 = head->next;
	while (p2 != nullptr && k > p2->value) {
		p2 = p2->next;
	}
	if (p2 == nullptr) {
		tail->next = p1;
		p1->previous = tail;
	}
	else {
		p1->previous = p2->previous;
		p2->previous->next = p1;
		p1->next = p2;
		p2->previous = p1;
	}
}


int main() {
	doubly_linked_list d1;
	d1.make_random_list(30, 10);
	d1.print_forward();
	d1.print_backward();

	d1.reverse();
	d1.print_forward();
	d1.print_backward();

	d1.remove_one(7);
	d1.remove_one(8);
	d1.print_forward();
	d1.print_backward();
	
	d1.remove_all(5);
	d1.print_forward();
	d1.print_backward();
	
	d1.sort();
	d1.print_forward();
	d1.print_backward();


	d1.insert(4);
	d1.insert(9);
	d1.insert(0);
	d1.print_forward();
	d1.print_backward();
	

	getchar();
	getchar();
	return 0;
}