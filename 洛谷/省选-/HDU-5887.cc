/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-03 22:29:40 PM
 * File Name     : HDU-5887.cc
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
ll n, T, ans;
struct Node {
  ll time, score;
  // 按time排序, 按性价比排序会tle
  bool operator<(const Node &rhs) const {
    // return score * 1.0 / time;
    return time > rhs.time;
  }
}A[N];

// 搜到第i个物品, 前i - 1个物品的重量是weight, 价值是value, 还剩下的价值为left
void dfs(int i, ll weight, ll value, ll left) {
  // 剪枝
  if (weight > T) return ;
  if (value + left <= ans) return ;
  // 优化
  if (value > ans) ans = value;

  // 递归的边界
  if (i == n + 1) {
    ans = std::max(ans, value);
    return ;
  }

  // 选第i个
  dfs(i + 1, weight + A[i].time, value + A[i].score, left - A[i].score);
  // 不选
  dfs(i + 1, weight, value, left - A[i].score);
}
int main() {
  while (scanf("%lld %lld", &n, &T) != EOF) {
    ll s = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%lld %lld", &A[i].time, &A[i].score);
      s += A[i].score;
    }
    std::sort(A + 1, A + 1 + n);
    ans = 0;
    dfs(1, 0, 0, s);
    printf("%lld\n", ans);
  }
  return 0;
}
