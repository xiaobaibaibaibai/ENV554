#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    int i, j, k;
    char c;
    float f;
    string s;

    // cin >> i >> j >> s;
    // cout << i << " " << j << " " << k << endl;

    // ofstream out1("data1.txt");
    // cin >> s;
    // cout << s << endl;
    // out1 << s;
    // out1.close();


    ifstream in1("data1.txt");
    in1 >> s;
    cout << s<< endl;
    in1.close();
    

    return 0;
}