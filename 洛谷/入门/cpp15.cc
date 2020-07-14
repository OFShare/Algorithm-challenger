/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-13 15:19:18 PM
 * File Name     : cpp15.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

void thread_task(int n) {
  std::this_thread::sleep_for(std::chrono::seconds(n));
  std::cout << "hello thread "
    << std::this_thread::get_id()
    << " paused " << n << " seconds" << std::endl;
}

int main(int argc, const char *argv[]) {
  std::thread threads[5];
  std::cout << "Spawning 5 threads...\n";
  for (int i = 0; i < 5; i++) {
    threads[i] = std::thread(thread_task, i + 1);
  }
  std::cout << "Done spawning threads! Now wait for them to join\n";
  for (auto& t: threads) {
    t.join();
  }
  std::cout << "All threads joined.\n";

  return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
