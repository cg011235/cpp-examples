/**
 * Demonstrate use of lambda function with thread
 * Lambda's are inline function which can be used for short snippets of code
 * that are not going to be reused and not worth naming.
 */
 
 #include <iostream>
 #include <thread>

 int main() {
  std::thread th (
    []() {
      std::cout << "Hello, from lambda" << std::endl;
    });
  std::cout << "Hello, from main()" << std::endl;

  th.join();

  return 0;
 }