#include <iostream>
using namespace std;

class node {
public:
    int value;
    node *next;
    //constructor
    node(int i) {
        value = i;
        next = nullptr;
    }
    node() {
        next = nullptr;
    }
};

class linked_list {
public:
    int num_nodes;
    node *head;
    linked_list() {
        num_nodes = 0;
        head = nullptr;
    }
    //create a linked_list of m nodes, with node values randomly selected 0...n-1
    void make_random_list(int m, int n);
    void print_list();
    void reverse();
    linked_list twice();
    void remove_one(int k);
};
void linked_list::make_random_list(int m, int n) {
    for (int i = 0; i < m; i++) {
        node *p = new node(rand() % n);
        p -> next = head;
        head = p;
        num_nodes++;
    }
}
void linked_list::print_list() {

    node *p = head;
    while (p != nullptr) {
        cout << p -> value << " ";
        p = p ->next;
    }
}
void linked_list::reverse() {
    node *p1 = head, *p2, *p3;
    p2 = p1 -> next;
    while (p2 != nullptr) {
        p3 = p2 -> next;
        p2 -> next = p1;
        if (p1 == head) {
            p1 -> next = nullptr;
        }
        p1 = p2;
        p2 = p3;
    }
    head = p1;
}
linked_list linked_list::twice() {
    linked_list temp;
    node *p1 = head, *p2;
    for (int i = 0; i < num_nodes; i++) {
        p2 = new node;
        p2 -> next = temp.head;
        temp.head = p2;
        temp.num_nodes++;
    }
    p2 = temp.head;
    for (int i = 0; i < num_nodes; i++) {
        p2 -> value = p1 -> value * 2;
        p1 = p1 -> next;
        p2 = p2 -> next;
    }
    return temp;
}
void linked_list::remove_one(int k) {
    node *p;
    if (head == nullptr) return;
    if (head -> value == k) {
        p = head;
        head = head -> next;
        delete p;
        return;
    }
    node *p1 = head, *p2 = head -> next;
    while (p2 != nullptr) {
        if (p2 -> value == k) {
            p1 -> next = p2 -> next;
            delete p2;
            num_nodes--;
            return;
        }
        p1 = p2;
        p2 = p2 -> next;
    }
}

int main() {
    linked_list l1;
    l1.make_random_list(10, 30);
    l1.print_list();
    l1.reverse();
    cout << endl;
    l1.print_list();
    cout << endl;
    linked_list l2;
    l2 = l1.twice();
    l2.print_list();
    cout << endl;
    l2.remove_one(38);
    l2.print_list();
    cout << endl;
    l2.remove_one(38);
    l2.print_list();

    return 0;
}


