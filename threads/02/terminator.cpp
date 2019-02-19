/**
 * Thread terminates the program
 */

#include <iostream>
#include <thread>

void messanger(void) {
  std::cout << "Message from thread" << std::endl;
  for (int i = 0; i < 150; ++i) {
    std::cout << i << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}

/**
 * Since the thread exists before main the program
 * terminates.
 */
int main() {
  std::thread t1(messanger);

  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout << "The main() is about to exit, but the messanger thread is still running"
            << std::endl;

  return 0;
}
