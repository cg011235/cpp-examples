/**
 * Scope of thread is limited to life of main()
 */

#include <iostream>
#include <thread>
#include <ctime>

using namespace std::chrono;

void heartbeat() {
  while (true) {
    auto x = high_resolution_clock::now();
    milliseconds ms = duration_cast<milliseconds>(x.time_since_epoch());
    seconds s = duration_cast<seconds>(ms);
    std::time_t t = s.count();
    std::cout << std::ctime(&t) << std::endl;
  }
}

int main() {
  try {
    std::thread t {heartbeat};
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  } catch (const std::exception& e) {
    std::cout << "Excpetion:" << e.what() << std::endl;
  } catch (...) {
    std::cout << "Caught default exception\n";
  }

  return 0;
}
