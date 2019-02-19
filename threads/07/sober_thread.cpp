/**
 * Sober threads program
 *
 * The 'std::cout' is global shared object represents standard output
 * stream. Since cout is accessed by all th threads and thre is no protection
 * the messages are printed at random order of thread execution.
 */

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::mutex mu;  // Mutual exclusion lock to protect std::cout

void print_msg(void) {
  std::lock_guard<std::mutex> lock(mu);
  cout << "Hello";
  cout << " from";
  cout << " thread: ";
  cout << this_thread::get_id();
  cout << endl;
}

int main() {
  thread t1 {print_msg};
  thread t2 {print_msg};
  thread t3 {print_msg};

  t1.join();
  t2.join();
  t3.join();

  return 0;
}

/**
 * Though we use the mutex, it will only protect cout from concurrent access
 * among t1, t2, t3. Some other process may still access stdout
 * So, the binding of lock has to be at cout object level.
 */
