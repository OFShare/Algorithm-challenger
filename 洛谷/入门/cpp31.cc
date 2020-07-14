/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-21 00:17:04 AM
 * File Name     : cpp31.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
#ifdef Acui
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
}

std::atomic<int> counter = {0};
int main() {
  std::vector<std::thread> vt;
  for (int i = 0; i < 100; ++i) {
    vt.emplace_back([](){
        counter.fetch_add(1, std::memory_order_relaxed);
    });
  }

  for (auto& t : vt) {
    t.join();
  }
  std::cout << "current counter:" << counter << std::endl;
  return 0;
}
