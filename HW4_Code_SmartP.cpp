#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;


template <class T> class TreeD {
public:
    T ht;
    T wd;
    T dep;
    TreeD() {ht = 0; dep = 0; wd = 0;};
    TreeD(T i) {
        ht = i; wd = i; dep = i;
    }
    TreeD(T a, T b, T c) {
        ht = a; wd = b; dep = c;
    }
    template <class U> friend ostream & operator<<(ostream &str, const TreeD<U> &tree);
};

template <class W> ostream & operator<<(ostream & str, const TreeD<W> &tree) {
    str << tree.ht << " " << tree.wd << " " << tree.dep;
    return str;
}


int main() {
    TreeD<double> t1(1.1, 2.2, 3.3);
    cout << t1 << endl;

    return 0;
}