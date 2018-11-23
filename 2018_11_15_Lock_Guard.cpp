//mutex 

#include <iostream>
#include <mutex>
#include <thread>

using namespace std;
mutex m1;
void f1() {
	//m1.lock();
	lock_guard<mutex> lock1(m1); //Lock_guard gives the same function as mutex, but will unlock
	//itself once it goes out of scope
	for (int i = 0; i > -1000; i--) cout << i << endl;
	//m1.unlock(); // forget to unlock will cause a big problem
}
void f2() {
	//m1.lock();
	lock_guard<mutex> lock1(m1);
	for (int i = 0; i < 1000; i++) cout << i << endl;
	//m1.unlock();
}

int main() {

	thread t1(f1);
	thread t2(f2);
	t1.join();
	t2.join();

	getchar();
	getchar();
	return 0;
}