/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-08 23:16:26 PM
 * File Name     : cpp11.cc
 */

#include <bits/stdc++.h>
#include <thread>

#define ll long long
void debug() {
#ifdef Acui
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
}

int main() {
  std::thread t([](){
      std::cout << "hello world, concurrency" << std::endl;
  });
  t.join();
  std::cout << "another" << std::endl;
  // t.join();
  std::thread t2;
  t2.join();
  return 0;
}
