#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

mutex m1;
condition_variable cv1, cv2;


void  PartWorker(int i) {
    int num1 = 0, num2 = 0, num3 = 0;
    int iteration = 1;
    while (iteration < 6) {
        unique_lock<mutex> ulock1(m1);
        while (num1 + num2 + num3 != 4) {
            num1 = rand() % 5;
            num2 = rand() % 5;
            num3 = rand() % 5;
        }
        cout << "Part Worker ID: " << i << endl;
        cout << "Iteration: " << iteration << endl;
        cout << "Buffer State: (" << "0, 0, 0, 0" << ")" << endl;
        cout << "Place Request: (";
        int zeroPlace = rand() % 4;
        switch (zeroPlace) {
            case 0:
                cout << 0 << " " << num1 << " " << num2 << " " << num3  << ")" << endl;
                break;
            case 1:
                cout << num1 << " " << 0 << " " << num2 << " " << num3  << ")" << endl;
                break;
            case 2:
                cout << num1 << " " << num2 << " " << 0 << " " << num3  << ")" << endl;
                break;
            default:
                cout << num1 << " " << num2 << " " << num3 << " " << 0  << ")" << endl;
                break;
        }
        cout << "Updated Buffer State: (" << "0, 0, 0, 0" << ")" << endl;
        cout << "Updated Place Request: (" << "1,0,0,1" << ")" << endl;
        cout << endl;
        iteration++;
    }
}


void ProductWorker(int i) {
    int num1 = 0, num2 = 0, num3 = 0;
    int iteration = 1;
    while (iteration < 6) {
        unique_lock<mutex> ulock(m1);
        while (num1 + num2 + num3 != 5) {
            num1 = rand() % 3 + 1;
            num2 = rand() % 3 + 1;
            num3 = rand() % 3 + 1;
        }

        cout << "Product Worker ID: " << i << endl;
        cout << "Iteration: " << iteration << endl;
        cout << "Buffer State: (" << "0, 0, 0, 0" << ")" << endl;
        cout << "Pickup Request: (";
        int zeroPlace = rand() % 4;
        switch (zeroPlace) {
            case 0:
                cout << 0 << " " << num1 << " " << num2 << " " << num3 << ")" << endl;
                break;
            case 1:
                cout << num1 << " " << 0 << " " << num2 << " " << num3  << ")" << endl;
                break;
            case 2:
                cout << num1 << " " << num2 << " " << 0 << " " << num3  << ")" << endl;
                break;
            default:
                cout << num1 << " " << num2 << " " << num3 << " " << 0  << ")" << endl;
                break;
        }
        cout << "Updated Buffer State: (" << "0, 0, 0, 0" << ")" << endl;
        cout << "Updated Pickup Request: (" << "1,0,0,1" << ")" << endl;
        cout << endl;
        iteration++;
    }
    
}


int main() {
    const int m = 5, n = 4;
    // const int m = 20, n = 16;   //m: number of Part Workers
                                //n: number of Product Workers
                                //m>n
    thread partW[m];
    thread prodW[n];

    for (int i = 0; i < n; i++){
        partW[i] = thread(PartWorker, i);
        prodW[i] = thread(ProductWorker, i);
    }
    for (int i = n; i<m; i++) {
        partW[i] = thread(PartWorker, i);
    }


    /* Join the threads to the main threads */
    for (int i = 0; i < n; i++) {
        partW[i].join();
        prodW[i].join();
    }
    for (int i = n; i<m; i++) {
        partW[i].join();
    }

    cout << "Finish!" << endl;


    getchar();
    getchar();
    return 0;
}

