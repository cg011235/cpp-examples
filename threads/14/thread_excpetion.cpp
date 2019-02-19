/**
 * exception with threads
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <cstdlib>

std::mutex mu;

void start_engine(int max) {
  try {
    for (int count = 0; count < max; count++) {
      std::cout << "starting the engine in " << count << std::endl;
      std::this_thread::sleep_for(std::chrono::seconds(1));
    }
  } catch (...) {
    std::lock_guard<std::mutex> lock(mu);
    std::cout << "starting the engine" << std::endl;
  }
}

void start_car() {
  std::lock_guard<std::mutex> lock(mu);
  int max = rand() % 10;
  start_engine(max);
}

int main() {
  try {
    std::thread th{start_car};  // Thread starts here
    th.join();  // Thread th joined by main here
  } catch (...) {
    std::cout << "Caught exception";
    throw;
  }
  return 0;
}
