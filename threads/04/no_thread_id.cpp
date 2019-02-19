/**
 * Program demonstrate scenarios where thread does not have id
 * A thread is not joinable if
 *  1. Thread is no task assigned (thread not initialized)
 *  2. Thread is terminated
 *  3. Thread has been moved
 *  4. Thread is detached
 */

#include <iostream>
#include <thread>

using namespace std;

void func() {
}

void sleepy_func(void) {
  int count = 0;
  while (count < 3) {
    cout << "Thread t4 is sleeping for a while\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    cout << "t4 woke up\n";
    count = count + 1;
  }
}

void counting_sheep(void) {
  int count = 0;
  while (count < 10) {
    cout << "Thread t5 is sleeping on count = " << count << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    cout << "t5 woke up\n";
    count = count + 1;
  }
}

int main() {
  thread t1;
  // t1 is not initalised 
  if (t1.get_id() == thread::id{}) {
    cout << "Thread t1 has no id as it is not initialized\n";
  }

  thread t2 {func};
  t2.join();
  // t2 has been terminated
  if (t2.get_id() == thread::id{}) {
    cout << "Thread t2 has no id as it is terminated\n";
  }

  // t3 is moved
  thread t3 {sleepy_func};
  thread t4 = move(t3);
  if (t3.get_id() == thread::id{}) {
    cout << "Thread t3 has no id as it is moved\n";
  }
  t4.join();

  // t5 is detached
  thread t5 {counting_sheep};
  t5.detach();
  if (t5.get_id() == thread::id{}) {
    cout << "Thread t5 has no id as it is detached\n";
  }

  return 0;
}
