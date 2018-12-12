#include <iostream>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <thread>
using namespace std;

mutex m1;
condition_variable cv1, cv2;
vector<int> vec;


//unique_lock is defined as local variables which will be removed once the the variables are out of scope
//and at the same time the destructor will unlock it.
void get1(int i) { //each get funciton works on 10 numbers in the vec and then clear the vec if the
	//vec contains 10 numbers
	int run = 4;
	while (run > 0) {
		int k = 0;
		unique_lock<mutex> ulock1(m1);
		//locking mechanism requires constantly checking the lock status, which is very cpu intense.
		cout << "get " << i << "  before wait" << endl;
		while (vec.size() < 10) cv1.wait(ulock1); //The moment a thread is in sleep, it will at the
		//same time release the lock (i.e., unlock it).
		//sleep mode will not require checking lock status and is more cpu efficient.
		for (int j = 0; j < 10; j++) {
			k += vec[j] * vec[j];
		}
		cout << " result = " << k << "  by get " << i << endl;
		vec.clear();
		run--;
		cv2.notify_one();
	}
}

void put(int i) {//each put funciton add a value to the vec if the vec is not full
	int run = 9;
	while (run > 0) {
		unique_lock<mutex> ulock1(m1);
		cout << " put  " << i << " before wait" << endl;
		while (vec.size() == 10) cv2.wait(ulock1);
		int j = rand() % 100 * i;
		vec.push_back(j);
		cout << "put " << i << "  just added value " << j << "  to vec" << endl;
		run--;
		if (vec.size() == 10) cv1.notify_one(); //The moment the notificaiton is sent, this put thread also releases lock
		//to the waken thread
	}
	if (vec.size() != 10) cv2.notify_one();
	//Without this line, the programm will encounter DEADLOCK!!!
}


int main() {

	thread get_thread[2];
	thread put_thread[10];
	for (int i = 0; i < 2; i++) {
		get_thread[i] = thread(get1, i);
	}
	for (int i = 0; i < 10; i++) {
		put_thread[i] = thread(put, i);
	}
	for (int i = 0; i < 2; i++) {
		get_thread[i].join();
	}
	for (int i = 0; i < 10; i++) {
		put_thread[i].join();
	}

	cout << endl;
	cout << "Finish !!!" << endl;
	cout << vec.size() << endl;
	
	getchar();
	getchar();
	return 0;
}