/**
 * Demonstrate concept of producer-consumer
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <mutex>
#include <random>
#include <thread>
#include <chrono>
#include <sstream>

class qdata {
public:
  std::string get_data();
  void set_data(std::string data);
private:
  bool is_empty(void) {return data.empty();}
  bool is_full(void) {return data.size() == 100;}
  std::vector<std::string> data;  // data from port
  std::mutex qdata_lock;  // lock to protect data
};

std::string qdata::get_data() {
  if (this->is_empty()) return {};
  std::lock_guard<std::mutex> lock(qdata_lock);
  std::string str = data.front();
  data.erase(data.begin());
  return str;
}

void qdata::set_data(std::string str) {
  if (! this->is_full()) {
    std::lock_guard<std::mutex> lock(qdata_lock);
    data.push_back(str);
  }
}

qdata q;

void producer(bool* listen) {
  std::ifstream ifs;
  ifs.open("/dev/urandom", std::ios::in | std::ios::binary);
  if (ifs.is_open()) {
    while (*(listen) == true) {
      uint16_t bytes_to_read = rand() % 100;
      char *memblock = new char [bytes_to_read];
      ifs.seekg(0, std::ios::beg);
      ifs.read(memblock, bytes_to_read);
      q.set_data(memblock);
      delete[] memblock;
      std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 100));
    }
  }
  ifs.close();
}

void consumer(bool* listen) {
  while (*(listen) == true) {
    std::stringstream str;
    str << std::this_thread::get_id() << ": " << q.get_data() << std::endl;
    std::cout << str.str();
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}

int main() {
  bool pl = true;
  bool cl1 = true;
  bool cl2 = true;
  std::thread prod1{producer, &pl};
  std::thread cons1{consumer, &cl1};
  std::thread cons2{consumer, &cl2};
  
  std::this_thread::sleep_for(std::chrono::seconds(10));
  cl2 = false;
  std::this_thread::sleep_for(std::chrono::seconds(10));
  cl1 = false;
  pl = false;

  prod1.join();
  cons1.join();
  cons2.join();
  return 0;
}