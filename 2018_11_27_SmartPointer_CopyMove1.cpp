#include <iostream>
#include <memory>
using namespace std;

template <class T> class node{
public:
    T value;
    shared_ptr<node> next;
    node() {}
    node(T i) {
        value = i;
    }
};

template <class T> class linked_list{
public:
    shared_ptr<node<T>> head;
    linked_list() {
        // head = nullptr;
    }
    linked_list(const linked_list<T> & L); //copy constructor
	linked_list(linked_list<T> &&L);//move constructor
	void operator= (const linked_list<T> &L); //L-value operator=
	void operator=(linked_list<T> &&L); //R-value operator=
	linked_list(const initializer_list<T> & I);

    template <class W> friend ostream & operator<<(ostream &str, const linked_list<W> L);

    void make_random_list(int m, int n);

};

template <class T> linked_list<T>::linked_list(const linked_list<T> &L) { // copy constructor, L-value
    head.reset();
    shared_ptr<node<T>> dummy = make_shared<node<T>>(-1);
    shared_ptr<node<T>> p1 = L.head;
    shared_ptr<node<T>> p2 = dummy;
    while(p1) {
        p2->next = make_shared<node<T>>(p1->value);
        p1 = p1->next;
        p2 = p2->next;
    }
    head = dummy->next;
    dummy.reset();
}

template <class T> linked_list<T>::linked_list(linked_list<T> &&L) { // move constructor, R-value
    head = L.head;
    L.head.reset();
}

template <class T> void linked_list<T>::operator=(const linked_list<T> &L) { // L-value
    while (head != nullptr) {
        shared_ptr<node<T>> p = head->next;
        head.reset();
        head = p;
    }
    shared_ptr<node<T>> dummy = make_shared<node<T>>(-1);
    shared_ptr<node<T>> p1 = L.head;
    shared_ptr<node<T>> p2 = dummy;
    while(p1) {
        p2->next = make_shared<node<T>>(p1->value);
        p1 = p1->next;
        p2 = p2->next;
    }
    head = dummy->next;
    dummy.reset();
}

template <class T> void linked_list<T>::operator=(linked_list<T> &&L) { // R-value
    while (head != nullptr) {
        shared_ptr<node<T>> p = head->next;
        head.reset();
        head = p;
    }
    head = L.head;
    L.head.reset();
}

template <class T> linked_list<T>::linked_list(const initializer_list<T> & I): linked_list() {
    auto it = I.begin();
    shared_ptr<node<T>> dummy = make_shared<node<T>>(-1);
    shared_ptr<node<T>> p = dummy;
    while (it != I.end()) {
        p->next = make_shared<node<T>>(*it);
        p = p->next;
        it++;
    }
    head = dummy->next;
    dummy.reset();
}

template <class T> ostream & operator<<(ostream &str, const linked_list<T> L) {
    shared_ptr<node<T>> p = L.head;
    str << endl;
    while (p != nullptr) {
        str << p->value << " ";
        p = p->next;
    }
    str << endl;
    return str;
}

template <class T> void linked_list<T>::make_random_list(int m, int n) {
    for (int i = 0; i < m; i++) {
        shared_ptr<node<T>> p = make_shared<node<T>>(rand()%n);
        p->next = head;
        head = p;
        p = p->next;
    }
}

int main() {
    linked_list<int> L1 = { 1,2,3,4,5 };
	cout << L1 << endl;
	linked_list<int> L2(L1), L3;
	cout << L2 << endl;
	L3 = L2;
	cout << L3 << endl;

    return 0;
}
