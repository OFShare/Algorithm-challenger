/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-23 16:33:43 PM
 * File Name     : CF792B.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int n, k;
int main() {
  scanf("%d %d", &n, &k);
  // 用链表模拟
  std::list<int> li;
  for (int i = 1; i <= n; ++i) {
    li.push_back(i);
  }
  int leader = 0;
  for (int i = 1; i <= k; ++i) {
    int x;
    scanf("%d", &x);
    int step = x % li.size();
    leader = (leader + step) % li.size();
    auto pos = li.begin();
    std::advance(pos, leader);
    printf("%d ", *pos);
    auto it = li.erase(pos);
    leader = std::distance(li.begin(), it);
  }
  return 0;
}
