/**
 * Demonstrate threads are passed by val 
 */

#include <iostream>
#include <thread>

// This function take msg by value 
void printer(std::string msg) {
  for (int i = 0; i < 5; i++) {
    std::cout << msg << (i + 1) << " days" << std::endl;
  }
  msg = "I did warned you 5 times";
}

// This function take msg by refrence
void mutating_printer(std::string& msg) {
  for (int i = 0; i < 5; i++) {
    std::cout << msg << (i + 1) << " days" << std::endl;
  }
  msg = "I did warned you 5 times";
}

int main() {
  std::string msg = "Your phone bill is due from ";
  std::thread t1(printer, msg);  // pass by val 
  t1.join();
  std::cout << "now the msg is: " << msg << std::endl;
  // Following line will not work as we pass refrence using regular &obj
  // std::thread t2(mutating_printer, &msg);
  // We need to use the std::ref() to extract the refrence to msg
  std::thread t3(mutating_printer, std::ref(msg));  // pass by ref
  t3.join();
  std::cout << "now the msg is: " << msg << std::endl;

  return 0;
}