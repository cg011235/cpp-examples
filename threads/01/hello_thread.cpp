/**
 *  Demonstrate the C++ way of threads
 */

#include <iostream>
#include <thread>  // Header for threads

void greeter() {
  std::cout << "Hello, threads!\n";
}

int main() {
  std::thread ht(greeter);  // Theread execution starts here
  ht.join();  // Oh main() wait till the thread ht finishes

  return 0;
}
