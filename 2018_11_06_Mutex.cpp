#include <iostream>
#include <thread>
#include <mutex> //mutually exclusive
using namespace std;
mutex lock1;
mutex mtx;


void f1(int k, int j) {
	
	for (int i = 0; i < k; i++) {
		lock1.lock();
		cout << "Thread " << j << " is printing   " << i * i - 1000 * i + 6500 << endl;
		lock1.unlock();
	}
	
}

void f2(int k, int j) {
	
	for (int i = 0; i < k; i++) {
		lock1.lock();
		cout << "Thread " << j << " is printing   " << i + 1<< endl;
		lock1.unlock();
	}
}


void print_block (int n, char c) {
	// critical section (exclusive access to std::cout signaled by locking mtx):
  	mtx.lock();
  	for (int i=0; i<n; ++i) { 
		  cout << c; 
	}
  	cout << '\n';
  	mtx.unlock();
}

int main() {

	thread t1(f2, 50, 1);
	thread t2(f2, 52, 2);
	t1.join();
	t2.join();

	thread p1(print_block,80,'*');
	thread p2(print_block,80,'$');
	p1.join();
	p2.join();

	/*
	// thread will run at the same time and output will not be expected
	t1.join();
	t2.join();
	p1.join();
	p2.join();
	*/

	cin.get();
	cin.get();
	return 0;
}