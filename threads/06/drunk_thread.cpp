/**
 * Drunk threads program, it does not know what it is talking.
 *
 * The 'std::cout' is global shared object represents standard output
 * stream. Since cout is accessed by all th threads and thre is no protection
 * the messages are printed at random order of thread execution.
 */

#include <iostream>
#include <thread>

using namespace std;

void print_msg(void) {
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
