/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-18 11:31:47 AM
 * File Name     : P1504.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e2 + 5;
int n;
bool dp[N * N];
std::set<int> height[N];

int main() {
  scanf("%d", &n);
  for (int k = 1; k <= n; ++k) {
    // 对每个城堡跑一遍01背包, 找出可以堆叠的所有高度
    // dp[i][j]前i个物品能否堆叠为高度为j
    int volume = N * N - 5;
    std::fill(dp, dp + volume + 1, false);
    dp[0] = true;
    int x;
    while (scanf("%d", &x)) {
      if (x == -1) break;
      for (int j = volume; j >= x; --j) {
        dp[j] |= dp[j - x];
      }
    }
    for (int j = 0; j <= volume; ++j) {
      if (dp[j]) height[k].insert(j);
    }
  }
  // 枚举高度
  for (auto it = height[1].rbegin(); it != height[1].rend(); ++it) {
    int hei = *it;
    bool found = true;
    for (int i = 2; i <= n; ++i) {
      if (height[i].count(hei) == 0) {
        found = false;
        break;
      }
    }
    if (found) printf("%d\n", hei), exit(0);
  }
  return 0;
}
