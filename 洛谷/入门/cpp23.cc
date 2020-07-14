/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-14 16:50:51 PM
 * File Name     : cpp23.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
#ifdef Acui
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
}

// count down taking a second for each value:
int countdown (int from, int to) {
  for (int i=from; i!=to; --i) {
    std::cout << i << '\n';
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  std::cout << "Finished!\n";
  return from - to;
}

int main () {
  std::packaged_task<int(int,int)> task(countdown); // 设置 packaged_task
  std::future<int> ret = task.get_future(); // 获得与 packaged_task 共享状态相关联的 future 对象.

  // std::thread th(std::move(task), 10, 0);   //创建一个新线程完成计数任务.
  std::thread th(std::move(task), 10, 0);   //创建一个新线程完成计数任务.

  int value = ret.get();                    // 等待任务完成并获取结果.

  std::cout << "The countdown lasted for " << value << " seconds.\n";

  th.join();
  return 0;
}
