/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-04 23:37:25 PM
 * File Name     : P1123.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 10;
// vis[x][y] = 0表示没访问过
// vis[x][y] = 1表示被访问过
// vis[x][y] = 2表示被选择过
int T, n, m, A[N][N], vis[N][N];
const int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

// 但(x, y)这个坐标被选择后, 它的八领域就都不能选
bool valid(int x, int y) {
  for (int i = 0; i < 8; ++i) {
    int newx = x + dx[i], newy = y + dy[i];
    if (newx >= 1 && newx <= n && newy >= 1 && newy <= m) {
      if (vis[newx][newy]) return false;
    }
  }
  return true;
}
void dfs(int x, int y, int sum) {
  vis[x][y] = 1;
  for (int i = 0; i < 8; ++i) {
    int newx = x + dx[i], newy = y + dy[i];
    // 不选(newx, newy)
    if (newx >= 1 && newx <= n && newy >= 1 && newy <= m && vis[newx][newy] == 0) {
      dfs(newx, newy, sum);
    }
    // 选(newx, newy)
    if (newx >= 1 && newx <= n && newy >= 1 && newy <= m && && vis[newx][newy] == 0 && valid(newx, newy)) {
      dfs(newx, newy, sum + A[newx][newy]);
    }
  }
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        scanf("%d", &A[i][j]);
      }
    }
    std::memset(vis, 0, sizeof vis);
    dfs(1, 1, 0);
  }
  return 0;
}
