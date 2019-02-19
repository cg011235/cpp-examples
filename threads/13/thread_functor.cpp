/**
 * Demonstrate use of functor with thread
 */
 
 #include <iostream>
 #include <thread>

class funct {
public:
  void operator()() {
    std::cout << "Hello, from functor" << std::endl;
  }
};
int main() {
  std::thread th((funct()));

  std::cout << "Hello, from main" << std::endl;
  th.join();
  
  return 0;
 }