#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex, std::lock, std::unique_lock
                          // std::adopt_lock, std::defer_lock
std::mutex foo,bar;

void task_a () {
  std::lock (foo,bar);         // simultaneous lock (prevents deadlock)
  std::lock (foo,bar);         // simultaneous lock (prevents deadlock)
  std::unique_lock<std::mutex> lck1 (foo,std::adopt_lock);
  std::unique_lock<std::mutex> lck2 (bar,std::adopt_lock);
  std::cout << "task a\n";
  // (unlocked automatically on destruction of lck1 and lck2)
}

void task_b () {
  // foo.lock(); bar.lock(); // replaced by:
  std::cout << "111" << std::endl;
  std::unique_lock<std::mutex> lck1, lck2;
  std::cout << "222" << std::endl;
  lck1 = std::unique_lock<std::mutex>(bar,std::defer_lock);
  std::cout << "333" << std::endl;
  lck2 = std::unique_lock<std::mutex>(foo,std::defer_lock);
  std::cout << "444" << std::endl;

  foo.unlock(); bar.unlock();
  std::lock (lck1,lck2);       // simultaneous lock (prevents deadlock)
  std::cout << "task b\n";
  // (unlocked automatically on destruction of lck1 and lck2)
}


int main ()
{
  std::thread th1 (task_a);
  std::thread th2 (task_b);

  th1.join();
  th2.join();

  return 0;
}
