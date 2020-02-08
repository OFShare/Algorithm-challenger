/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-06 14:58:48 PM
 * File Name     : HDU-1078.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <string>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e2 + 5;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int n, m;
int mp[N][N];

bool valid(int x, int y, int score) {
  if (x < 1 || x > n || y < 1 || y > n) return false;
  if (mp[x][y] <= score) return false;
  return true;
}
// 从(x, y)一直走, 直到不能走时, 所能获得的最大得分
int dp[N][N];
int dfs(int x, int y) {
  if (dp[x][y] != -1)
    return dp[x][y];
  int ret = 0;
  for (int i = 0; i < 4; ++i) {
    // 最多走m步
    for (int k = 1; k <= m; ++k) {
      int newx = x + dx[i] * k, newy = y + dy[i] * k;
      if (valid(newx, newy, mp[x][y])) ret = std::max(ret, dfs(newx, newy));
      if (newx < 1 || newx > n || newy < 1 || newy > n) break;
    }
  }
  return dp[x][y] = ret + mp[x][y];
}
int main() {
  while (scanf("%d %d", &n, &m) && n + m != -2) {
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j) 
        scanf("%d", &mp[i][j]);
    std::memset(dp, -1, sizeof dp);
    int ret = dfs(1, 1);
    printf("%d\n", ret);
  }
  return 0;
}
