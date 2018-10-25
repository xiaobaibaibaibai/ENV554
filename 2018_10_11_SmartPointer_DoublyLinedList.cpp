//CIS554 HW1
//Due: 11:59PM, Friday (9/14)

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
	node(int i) { value = i; }
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

	//inplement the following member functions:
	/*
	void remove_one(int k); //remvoe the first node with value k
	void remove_all(int k); //remove all nodes with value k
	void reverse();//reverse the order of the list
	void sort(); //sort the nodes in ascending order
	void insert(int k); //insert a node to an already sorted list
	*/
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

int main() {
	doubly_linked_list d1;
	d1.make_random_list(30, 10);
	d1.print_forward();
	d1.print_backward();
	/*
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
	*/

	getchar();
	getchar();
	return 0;
}