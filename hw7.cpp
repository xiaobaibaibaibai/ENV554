#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <string>
using namespace std;

int bufferArea[] = {0, 0, 0, 0};
mutex m1;
condition_variable cv1, cv2;


void PartWorker(int i) {
    int num1 = 0, num2 = 0, num3 = 0;
    int updatedPlaceRequest[] = {0, 0, 0, 0};
    int iteration = 1;
    while (iteration < 6) {
        unique_lock<mutex> ulock1(m1);
        while (bufferArea[0] + updatedPlaceRequest[0] > 6
                || bufferArea[1] + updatedPlaceRequest[1] > 5
                || bufferArea[2] + updatedPlaceRequest[2] > 4
                || bufferArea[3] + updatedPlaceRequest[3] > 3) {
                    cv1.wait(ulock1);
                }
        string output = "Part Worker ID: " + to_string(i) + "\n";
        output = output + "Iteration: " + to_string(iteration) + "\n";
        output = output + "Buffer State: (" + to_string(bufferArea[0]) + ", "
                    + to_string(bufferArea[1]) + ", "
                    + to_string(bufferArea[2]) + ", "
                    + to_string(bufferArea[3]) + ")\n";
        
        while (num1 + num2 + num3 != 4) {
            num1 = rand() % 5;
            num2 = rand() % 5;
            num3 = rand() % 5;
        }
        int randomNums[] = {num1, num2, num3};
        int combination[4];
        int zeroPlace = rand() % 4;
        int u = 0, v = 0;
        while (u < 4) {
            if (u == zeroPlace) {
                combination[zeroPlace] = 0;
            } else {
                combination[u] = randomNums[v];
                v++;
            }
            u++;
        }
        for (int j = 0; j < 4; j++) {
            if (bufferArea[j] + combination[j] + updatedPlaceRequest[j] > (6 - j)) {
                updatedPlaceRequest[j] = bufferArea[j] + combination[j] + updatedPlaceRequest[j] - (6 - j);
                bufferArea[j] = 6 - j;
            } else {
                bufferArea[j] = bufferArea[j] + combination[j] + updatedPlaceRequest[j];
                updatedPlaceRequest[j] = 0;
            }
        }
        
        if (updatedPlaceRequest[0] != 0 || updatedPlaceRequest[1] != 0 
            || updatedPlaceRequest[2] != 0 || updatedPlaceRequest[3] != 0) {
                cout << output;
                cout << "Place Request: (" << combination[0] << ", " << combination[1] << ", " << combination[2] << ", " << combination[3] << ")" << endl;
                cout << "Updated Buffer State: (" << bufferArea[0] << ", " << bufferArea[1] << ", " << bufferArea[2] << ", " << bufferArea[3] << ")" << endl;
                cout << "Updated Place Request: (" << updatedPlaceRequest[0] << ", " << updatedPlaceRequest[1] << ", " << updatedPlaceRequest[2] << ", " << updatedPlaceRequest[3] << ")" << endl;
                cout << endl;
            }
        iteration++;
        cv2.notify_all();
    }
    cv1.notify_all();
    
}


void ProductWorker(int i) {
    int num1 = 0, num2 = 0, num3 = 0;
    vector<int> updatedPickupRequest = {0, 0, 0, 0};
    int iteration = 1;
    bool isSuspend = false;
    while (iteration < 6) {
        unique_lock<mutex> ulock1(m1);
        while (bufferArea[0] - updatedPickupRequest[0] < 0
                || bufferArea[1] - updatedPickupRequest[1] < 0
                || bufferArea[2] - updatedPickupRequest[2] < 0
                || bufferArea[3] - updatedPickupRequest[3] < 3) {
                    cv2.wait(ulock1);
        }
        if (isSuspend) {
            isSuspend = false;
        }
        
        string output = "Product Worker ID: " + to_string(i) + "\n";
        output = output + "Iteration: " + to_string(iteration) + "\n";
        output = output + "Buffer State: (" + to_string(bufferArea[0]) + ", "
                    + to_string(bufferArea[1]) + ", "
                    + to_string(bufferArea[2]) + ", "
                    + to_string(bufferArea[3]) + ")\n";

        while (num1 + num2 + num3 != 5) {
            num1 = rand() % 3 + 1;
            num2 = rand() % 3 + 1;
            num3 = rand() % 3 + 1;
        }
        int randomNums[] = {num1, num2, num3};
        int combination[4];
        int zeroPlace = rand() % 4;
        int u = 0, v = 0;
        while (u < 4) {
            if (u == zeroPlace) {
                combination[zeroPlace] = 0;
            } else {
                combination[u] = randomNums[v];
                v++;
            }
            u++;
        }
        for (int j = 0; j < 4; j++) {
            if (bufferArea[j] - combination[j] - updatedPickupRequest[j] < 0) {
                updatedPickupRequest[j] = updatedPickupRequest[j] + combination[j] - bufferArea[j];
                bufferArea[j] = 0;
            } else {
                bufferArea[j] = bufferArea[j] - combination[j] - updatedPickupRequest[j];
            }
        }
        if (updatedPickupRequest[0] != 0 || updatedPickupRequest[1] != 0
            || updatedPickupRequest[2] != 0 || updatedPickupRequest[3] != 0) {
                cout << output;
                cout << "Pickup Request: (" << combination[0] << ", " << combination[1] << ", " << combination[2] << ", " << combination[3] << ")" << endl; 
                cout << "Updated Buffer State: (" << bufferArea[0] << ", " << bufferArea[1] << ", " << bufferArea[2] << ", " << bufferArea[3] << ")" << endl;
                cout << "Updated Place Request: (" << updatedPickupRequest[0] << ", " << updatedPickupRequest[1] << ", " << updatedPickupRequest[2] << ", " << updatedPickupRequest[3] << ")" << endl;
                cout << endl;
                isSuspend = true;

        }
        iteration++;
        cv1.notify_all();
    }
    cv2.notify_all();
}


int main() {
    const int m = 10, n = 8;
    // const int m = 20, n = 16;   //m: number of Part Workers
                                // n: number of Product Workers
                                // m>n
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

