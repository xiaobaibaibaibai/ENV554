#include <iostream>
using namespace std;

class ThreeD {
public:
    int ht;
    int wid;
    int dep;
    // following are constructor for initializing object avlue
    ThreeD(int i, int j, int k) {
        ht = i;
        wid = j;
        dep = k;
    }
    ThreeD(int u) {
        ht = wid = dep = u;
    }
    ThreeD(){}
    int vol() {
        return ht * wid * dep;
    }

    // 'const' here for users only using the input value without change it.
    // &d is reference, so users can change this value but this way should block
    ThreeD operator+(ThreeD const &d);
    
    bool operator<(ThreeD &d) {
        return vol() < d.vol();
    }
    int & operator[] (int k);
    ThreeD operator++(); // prefix
    ThreeD operator++(int never_used); // postfix
};


ThreeD ThreeD::operator+(ThreeD const &d) {
    ThreeD temp;
    temp.ht = ht + d.ht;
    temp.wid = wid + d.wid;
    temp.dep = dep + d.dep;
    return temp;
}

// this return is not the value, it returns the reference of value.
// the function returns a reference
int & ThreeD::operator[](int k) {
    switch(k) {
        case 0: return ht;
        case 1: return wid;
        case 2: return dep;
        default: return dep;
    }
}

// prefix
ThreeD ThreeD::operator++() {
    ht++;
    wid++;
    dep++;
    return *this;
}

// postfix
ThreeD ThreeD::operator++(int never_used) {
    ThreeD temp = *this;
    ht++;
    dep++;
    wid++;
    return temp;
}

int main() {
    ThreeD d1(3, 4, 5), d2 (6, 7, 8), d3, d4;
    // ThreeD tests1 = {5, 6, 7}; // professor works but I do not
    
    // compiler will convrt it into d3 = d1.operator+(d2)
    d3 = d1 + d2;

    if (d1 < d2) {
        cout << d1.vol() << " " << d2.vol() << endl; 
    } else {
        cout << d2.vol() << " " << d1.vol() << endl;
    }

    d3[2] = 10; // equivlent to d3.dep = 10
    cout << d3[2] << endl;

    d3++; //postfix
    ++d1; // prefix

    ThreeD d6(5, 6, 7);
    ThreeD *p1 = &d6;
    (*p1).ht = 1000;
    p1 -> dep = 2000;

    return 0;
}