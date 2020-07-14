/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-13 22:53:26 PM
 * File Name     : cpp22.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

std::mutex mtx1, mtx2;

int task() {
  std::cout << "before" << std::endl;
  std::lock(mtx1, mtx2);
  std::lock(mtx1, mtx2);
  std::cout << "after" << std::endl;
  return -1;
}

int main() {
  std::thread t(task);
  t.join();
  return 0;
}
