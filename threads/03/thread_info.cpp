/**
 * A thread is representation of task (function) mapped
 * to OS thread.
 */

#include <iostream>
#include <thread>

using namespace std;

void getThreadInfo(void) {
  /**
   * get_id
   * Returns id of given thread
   */
  auto x = this_thread::get_id();

  /**
   * A thread is not joinable if
   *  1. Thread is no task assigned (thread not initialized)
   *  2. Thread is terminated
   *  3. Thread has been moved
   *  4. Thread is detached
   */
  if (x == thread::id{}) {
    cout << "This thread is not joinable\n";
  } else {
    cout << "This thread has id:" << x << endl;
  }

  /**
   * hardware_concurrencry
   *
   * Returns number of threads that can be run simultaneously
   * with current hardware support.
   */
  cout << "Possible threads on this system:"
       << thread::hardware_concurrency()
       << endl;
}

int main() {
  // declare th to be of type thread and initialise it to run task
  thread th {getThreadInfo};

  /**
   * join
   * Tells main "Oo main(), plz wait till th finishes its execution"
   */
  th.join();

  return 0;
}
