/*
Detaches the thread represented by the object from the calling thread, allowing them to execute independently from each other.

Both threads continue without blocking nor synchronizing in any way. Note that when either one ends execution, its resources are released.

After a call to this function, the thread object becomes non-joinable and can be destroyed safely.

*/


#include <iostream>       // std::cout
#include <thread>         // std::thread, std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
 
void pause_thread(int n) 
{
  std::this_thread::sleep_for (std::chrono::seconds(n));
  std::cout << "pause of " << n << " seconds ended\n";
}
 
int main() 
{
  std::cout << "Spawning and detaching 3 threads...\n";
  std::thread (pause_thread,1).detach();
  std::thread (pause_thread,2).detach();
  std::thread (pause_thread,3).detach();
  std::cout << "Done spawning threads.\n";

  std::cout << "(the main thread will now pause for 5 seconds)\n";
  // give the detached threads time to finish (but not guaranteed!):
  pause_thread(5);
  return 0;
}


//output
/*
Spawning and detaching 3 threads...
Done spawning threads.
(the main thread will now pause for 5 seconds)
pause of 1 seconds ended
pause of 2 seconds ended
pause of 3 seconds ended
pause of 5 seconds ended
*/