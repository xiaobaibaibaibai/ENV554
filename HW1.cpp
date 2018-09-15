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

	//implement the following member functions:
	
	void remove_one(int k); //remvoe the first node with value k
	void remove_all(int k); //remove all nodes with value k
	void reverse();//reverse the order of the list
	void sort(); //for the nodes in assending order
	void insert(int k); //insert a node to an already sorted list
};

void doubly_linked_list:: make_random_list(int m, int n) {

	for (int i = 0; i < m; i++) {
		node * p1 = new node(rand() % n);
		p1->previous = tail;
		if (tail != nullptr) tail->next = p1;
		tail= p1;
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
    if (head == nullptr) {
        return;
    }
    node *p;
	if (head -> value == k && tail == head) {
		p = head;
		head = head -> next;
		tail = tail -> previous;
		delete p;
		return;
	}
    if (head -> value == k) {
        p = head;
        head = head -> next;
        head -> previous = nullptr;
        delete p;
        return;
    }
    node *p1 = head, *p2 = head -> next;
    while (p2 != nullptr) {
		if (p2 -> value == k) {
			p1 -> next = p2 -> next;
			if (p2 != tail) {
				p2 -> next -> previous = p1;
			} else {
				tail = p1;
			}
			delete p2;
			return;
		}
		p1 = p2;
		p2 = p2 -> next;
	}
}

void doubly_linked_list::remove_all(int k) {
	if (head == nullptr) {
		return;
	}
	while (head -> value == k) {
		node *p = head;
		if (head == tail) {
			head = head -> next;
			tail = tail -> previous;
			delete p;
			return;
		}
		head = head -> next;
		head -> previous = nullptr;
		delete p;
	}
	node *p1 = head;
    while (p1 -> next != nullptr) {
		node *p2 = p1 -> next;
		if (p2 -> value == k) {
			p1 -> next = p2 -> next;
			if (p2 != tail) {
				p2 -> next -> previous = p1;
			} else {
				tail = p1;
			}
			delete p2;
		} else {
			p1 = p2;
		}
	}
}

void doubly_linked_list::reverse() {
	if (head == nullptr || head == tail)
		return;
	node *p1 = head, *p2, *p3;
    p2 = p1 -> next;
    while (p2 != nullptr) {
        p3 = p2 -> next;
        p2 -> next = p1;
		p2 -> previous = p3;
        if (p1 == head) {
            p1 -> next = nullptr;
			p1 -> previous = p2;
			tail = p1;
        }
        p1 = p2;
        p2 = p3;
    }
    head = p1;
}

node * merge(node *font, node *back) {
	if (font == nullptr) {
		return back;
	} else if (back == nullptr) {
		return font;
	} else {
		if (font -> value < back -> value) {
			font -> next = merge(font -> next, back);
			font -> next -> previous = font;
			font -> previous = nullptr;
			return font;
		} else {
			back -> next = merge(font, back -> next);
			back -> next -> previous = back;
			back -> previous = nullptr;
			return back;
		}
	}
}

node * mergeSort(node *head) {
	if (head == nullptr || head -> next == nullptr) {
		return head;
	}
	node *pf = head, *ps = head;
	while (pf -> next != nullptr && pf -> next -> next != nullptr) {
		pf = pf -> next -> next;
		ps = ps -> next;
	}
	node *mid = ps -> next;
	ps -> next = nullptr;

	head = mergeSort(head);
	mid = mergeSort(mid);
	return merge(head, mid);
}

void doubly_linked_list::sort() {
	if (head == nullptr || head == tail) return;
	node* begin = mergeSort(head);
	head = begin;
	while (begin -> next != nullptr) {
		begin = begin -> next;
	}
	tail = begin;
}

void doubly_linked_list::insert(int k) {
	node *p = new node(k);
	if (head == nullptr) {
		head = p;
		tail = p;
		return;
	}
	if (head == tail) {
		head -> next = p;
		p -> previous = head;
		tail = p;\
		return;
	}
	if (k <= head -> value) {
		p -> next = head;
		head -> previous = p;
		head = p;
		return;
	}
	node *p1 = head;
	while (p1 -> next != nullptr) {
		node *p2 = p1 -> next;
		if (p2 == tail) {
			p2 -> next = p;
			p -> previous = p2;
			tail = p;
			return;
		} else if (p1 -> value < k && p2 -> value >= k) {
			p -> previous = p1;
			p -> next = p2;
			p1 -> next = p;
			p2 -> previous = p;
			return;
		} else {
			p1 = p2;
		}
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