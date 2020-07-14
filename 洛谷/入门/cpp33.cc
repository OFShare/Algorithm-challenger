/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-23 10:47:59 AM
 * File Name     : cpp33.cc
 */

#include <bits/stdc++.h>

std::condition_variable cond;
std::mutex print_mutex;
int flag = 0;

void print_thread(int num)
{
  for (int i = 0; i < 10; i++)
  {
    std::unique_lock<std::mutex> lk(print_mutex);
    cond.wait(lk, [&]() { return num == flag; });
    std::cout << char('A' + num);
    flag = (flag + 1) % 3;
    cond.notify_all();
  }
}

int main() {
  std::thread t1(print_thread, 1);
  std::thread t2(print_thread, 2);
  print_thread(0);
  t1.join();
  t2.join();
  return 0;
}
