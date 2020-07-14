/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-07-03 17:57:02 PM
 * File Name     : HDU-3586.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e3 + 5;
const int INF = 1e6 + 5;
int n, m, dp[N];
std::vector<std::pair<int, int> > sons[N];

void dfs(int u, int pre, const int &mid) {
  dp[u] = 0;
  bool updated = false;
  for (int i = 0, len = sons[u].size(); i < len; ++i) {
    int v = sons[u][i].first, w = sons[u][i].second;
    if (v != pre) {
      dfs(v, u, mid);
      if (w > mid) dp[u] += dp[v];
      else dp[u] += std::min(w, dp[v]);
      updated = true;
    }
  }
  // 递归的边界
  if (!updated) dp[u] = INF;
}
int main() {
  while (scanf("%d %d", &n, &m) && n + m) {
    for (int i = 1; i <= n; ++i) sons[i].clear();
    int L = 1e9, R = 0; 
    for (int i = 1; i <= n - 1; ++i) {
      int u, v, c;
      scanf("%d %d %d", &u, &v, &c);
      sons[u].push_back({v, c});
      sons[v].push_back({u, c});
      L = std::min(L, c);
      R = std::max(R, c);
    }
    // 二分答案
    for (int i = 0; i < 50; ++i) {
      if (L > R || R - L == 1) break;
      int mid = L + (R - L) / 2;
      dfs(1, -1, mid);
      if (dp[1] <= m) R = mid;
      else L = mid + 1;
    }
    bool flag1 = true, flag2 = true;
    dfs(1, -1, L);
    if (dp[1] > m) flag1 = false;
    dfs(1, -1, R);
    if (dp[1] > m) flag2 = false;
    if (!flag1 && !flag2) {
      printf("%d\n", -1);
      continue;
    }
    if (flag1) printf("%d\n", L);
    else if (flag2) printf("%d\n", R);
  }
  return 0;
}
