/*
 
 . dot
 * star
 {} curly bracket
 [] square bracket
 ~ tidle
 & address or ref
 -> select
 ; semicolon
 
 */

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
    int vol() {
        return ht * wid * dep;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    int i = 10;
    int *p = &i;
    // cout << i << " " << *p << endl;
    
    int j = 20;
    p = &j;
    *p = 30;
    // cout << j << " " << *p << endl;
    
    int A[5] = {0, 1, 2, 3, 4};
    // cout << *A << " " << A[0] << endl;
    // array name without index is the same as the address of the first element of the array, same as &A[0].
    
    *(A + 2) = 10; // the same as A[2] = 10;
    // cout << A[2] << endl;
    
    // cout << A[6] << endl; // check the array upper bound
    
    int *B = new int[5];
    // new asks the system to allocate memory space and returns the address of the memory space.
    B[2] = 100; // *(B + 2) = 100;
    // cout << B[1] << " " << B[2] << endl;
    
    int *w = new int;
    delete w; // return the memory space pointed by w
    delete[] B; // return the memory space pointed by B
    // delete can only work for new. new and delete are pair
    
    // self-design
    ThreeD D1(3, 4, 5), D2(3);
    // cout << D1.vol() << endl;
    
    int C[3][4] = {
        {1, 2, 3, 4},
        {10, 20, 30, 40},
        {25, 35, 45, 55}
    };
    C[2][3] = 1000;
    // the same as *(*(C+2)+3) = 1000; the same a *(C[2] + 3) = 1000; the same as *(&C[0][0] + 2*4+3) = 1000
    
    
    
    return 0;
}
