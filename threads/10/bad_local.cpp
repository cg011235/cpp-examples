/**
 * Program demonstrate locals are safe as long as
 * thre is no pointer shared between threads
 */

#include <iostream>
#include <thread>

using namespace std;

int counter(int *index) {
  *(index) = *(index) + 1;
  return *(index);
}

void print_counter(int *index) {
  cout << "Count is :" << counter(index) << endl;
}

int g_index = 0;

int main() {
  int i = 10;

  cout << "local count is :" << i << endl;
  thread t1 {print_counter, &g_index};
  thread t2 {print_counter, &g_index};
  thread t3 {print_counter, &g_index};
  thread t4 {print_counter, &i};  // Accidental case

  cout << "local count is :" << i << " before main() joins" << endl;
  t1.join();
  t2.join();
  t3.join();
  t4.join();
  cout << "local count is :" << i << " at the end" << endl;

  return 0;
}

/*
 * Typical output:
 * local count is :10
 * Count is :1
 * Count is :2
 * Count is :3
 * local count is :10 before main() joins
 * Count is :11
 * local count is :11 at the end
 */
