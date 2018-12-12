#include <iostream>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <thread>
using namespace std;

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void print_id (int id) {
  std::unique_lock<std::mutex> lck(mtx);
  while (!ready) {
	  cout << "first : " << id << endl; 
	  cv.wait(lck);
  }
  // ...
  std::cout << "thread " << id << '\n';
}

void go1() {
  std::unique_lock<std::mutex> lck(mtx);
  ready = false;
  cv.notify_all();
}
void go2() {
  std::unique_lock<std::mutex> lck(mtx);
  ready = true;
  cv.notify_all();
}

int main ()
{
  std::thread threads[10];
  // spawn 10 threads:
  for (int i=0; i<10; ++i)
    threads[i] = std::thread(print_id,i);

  std::cout << "10 threads ready to race...\n";
  go2();                       // go!

  for (auto& th : threads) th.join();

  return 0;
}