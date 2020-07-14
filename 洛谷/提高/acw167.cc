/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-24 13:38:47 PM
 * File Name     : acw167.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 64 + 5;
int n, stick[N];
bool vis[N];

// 拼接到第cnt根, 且当前长度为cap, 已经使用了一些木棒vis(true为使用), 现在可以从start开始选木棒, 能否搜到答案
bool dfs(int cnt, int cap, int start, const int &count, const int &len) {
  // 递归的边界
  if (cnt == count + 1 && cap == 0) return true;

  // 剪枝
  if (cnt >= count + 1) return false;

  int pre = -1;
  // 尝试选一根
  for (int i = start; i <= n; ++i) {
    // 剪枝
    if (stick[i] == pre) continue;
    if (vis[i]) continue;
    vis[i] = true;
    if (cap + stick[i] <= len) {
      if (cap + stick[i] == len && dfs(cnt + 1, 0, 1, count, len)) return true;
      if (cap + stick[i] < len && dfs(cnt, cap + stick[i], i + 1, count, len)) return true;
    }
    vis[i] = false;
    pre = stick[i];
    // 剪枝
    if (cap == 0 || cap + stick[i] == len) break;
  }
  return false;
}
int main() {
  while (scanf("%d", &n) && n) {
    std::memset(vis, 0, sizeof vis);
    int len = 0, sum = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &stick[i]);
      len = std::max(len, stick[i]);
      sum += stick[i];
    }
    std::sort(stick + 1, stick + 1 + n, std::greater<int>());
    for (; ; ++len) {
      if (sum % len == 0 && dfs(1, 0, 1, sum / len, len)) break;
    }
    printf("%d\n", len);
  }
  return 0;
}
