//2018_08_30 notes

#include <iostream>
#include <memory>
using namespace std;

class node {
public:
	int value;
	//node * next;
	shared_ptr<node> next;
	//constructor
	//node(int i) { value = i; next = nullptr; }
	node(int i) { value = i;}
	//node() { next = nullptr; }
	node() {}
};

class linked_list {
public:
	int num_nodes;
	//node * head;
	shared_ptr<node> head;
	//linked_list() { num_nodes = 0; head = nullptr; }
	linked_list() { num_nodes = 0;}
	void make_random_list(int m, int n);
	//create a linked_list of m nodes, with node values randomly distributed in 0 ...n-1
	void print_list();
	void reverse();
};
void linked_list::make_random_list(int m, int n) {
	for (int i = 0; i < m; i++) {
		//node * p = new node(rand() % n);
		shared_ptr<node> p = make_shared<node>(rand() % n);
		p->next = head; //this is the same as (*p).next = head;
		head = p;
		num_nodes++;
	}
}
void linked_list::print_list() {
	cout << endl;
	//node * p = head;
	shared_ptr<node> p = head;
	//while (p != nullptr) {
	while (p) {
		cout << p->value << " ";
		p = p->next;
	}
}
void linked_list::reverse() {
	if (num_nodes <= 1) return;
	//node * p1 = head, *p2, *p3;
	shared_ptr<node> p1 = head, p2, p3;
	p2 = p1->next;
	//while (p2 != nullptr) {
	while (p2) {
		p3 = p2->next;
		p2->next = p1;
		//if (p1 == head) p1->next = nullptr;
		if (p1 == head) p1->next.reset();
		p1 = p2;
		p2 = p3;
	}
	head = p1;
}


int main() {

	linked_list L1;
	L1.make_random_list(5, 50);
	L1.print_list();
	L1.reverse();
	L1.print_list();
	// getchar();
	// getchar();
	return 0;
}
