/**
 * Oversubscription is creating more threads than actual caliber of
 * physical hardware below.
 * Having too many threads running at same time is not efficient as
 * there will be too many context switches
 */

#include <iostream>
#include <thread>

int main() {
  std::cout << "This machine can efficiently run multithreaded program with "
            << std::thread::hardware_concurrency()
            << " number of threads"
            << std::endl;

  return 0;
}

