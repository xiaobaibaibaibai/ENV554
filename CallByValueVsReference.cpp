// call by value va call by reference

# include <iostream>
using namespace std;

// call by value
void f1(int i){
    // a new copy is created inside the function. 
    // any nodification on this new copy will not affect the original copy.
    i++;
    cout << i << endl;
}
// call by reference
void f2(int &i) {
    // no new copy is created, only the original object is used in the function.
    i++;
    cout << i << endl;
}

// always call by ref for array argument
void f3(int A[], int k) {
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += A[i];
    }
    cout << sum << endl;
    A[2] = 1000;
}

// always call by ref for array argument
void f4(int *A, int k) {
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += A[i];
    }
    cout << sum << endl;
    A[2] = 1000;
}

int main() {
    int j = 10;
    f1(j);
    cout << j << endl;
    f2(j);
    cout << j << endl;
    int A[] = {1, 3, 4, 6, -2, -5, 22};
    f3(A, 5);
    return 0;
}