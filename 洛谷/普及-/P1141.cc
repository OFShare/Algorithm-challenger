/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-14 18:24:51 PM
 * File Name     : P1141.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int N = 1e3 + 5;
int n, m;
char A[N][N];

// 从(x, y)坐标能走到的最多的格子数, 对走到的点标记
int vis[N][N];
int dp[N][N];
int dfs(int x, int y, int union_number) {
  if (dp[x][y] != -1) return dp[x][y];
  vis[x][y] = union_number;
  int ret = 1;
  for (int i = 0; i < 4; ++i) {
    int newx = x + dx[i], newy = y + dy[i];
    if (newx >= 1 && newx <= n && newy >= 1 && newy <= n && vis[newx][newy] == 0 && A[newx][newy] == '1' - A[x][y] + '0') {
      ret += dfs(newx, newy, union_number);
    }
  }
  return dp[x][y] = ret;
}

// 将一个联通块的都赋值为value
void dfs2(int x, int y, int union_number, int value) {
  dp[x][y] = value;
  for (int i = 0; i < 4; ++i) {
    int newx = x + dx[i], newy = y + dy[i];
    if (newx >= 1 && newx <= n && newy >= 1 && newy <= n && vis[newx][newy] == union_number && dp[newx][newy] != value) {
      dfs2(newx, newy, union_number, value);
    }
  }
}
void init() {
  int union_number = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (vis[i][j] == 0) {
        int ret = dfs(i, j, ++union_number);
        dfs2(i, j, union_number, ret);
      }
    }
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i)
    scanf("%s", A[i] + 1);
  std::memset(vis, 0, sizeof vis);
  std::memset(dp, -1, sizeof dp);
  init();

  for (int i = 1; i <= m; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d\n", dp[x][y]);
  }
  return 0;
}
