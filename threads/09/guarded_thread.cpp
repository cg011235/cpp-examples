/**
 * More safer threads for bad coders.
 * If program spaws thread and does not join by itself, at the end of main()
 * it invokes destructor of all the objects created in main().
 * Here, we make use of this sequence to see if the thread is joinable() and
 * if so then do call join(). Ensuring thread gets executed properly.
 */

#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>

using namespace std::chrono;

struct guarded_thread : std::thread {
  using std::thread::thread;
  ~guarded_thread() {
    std::cout << "Destructor of thread called\n";
    if (joinable()) {
        join();
    }
  }
};

void tick() {
  int i = 0;
  while (i < 10) {
    auto x = high_resolution_clock::now();
    milliseconds ms = duration_cast<milliseconds>(x.time_since_epoch());
    seconds s = duration_cast<seconds>(ms);
    std::time_t t = s.count();
    std::cout << std::ctime(&t) << std::endl;
    i = i + 1;
  }
}

int main() {
  guarded_thread th {tick};

  std::cout << "Returning from main()\n";
  return 0;
}
