/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-10 17:44:32 PM
 * File Name     : P1006.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 50 + 5;
const int dx[] = {1, 0};
const int dy[] = {0, 1};

int m, n, mp[N][N], dp[N][N][N][N];
bool vis[N][N];

struct Node {
  int x1, y1;
  int x2, y2;
  int value;
};
// 问题转化为两人同时从(1, 1)出发
// dp[x1][y1][x2][y2]表示从最开始的状态出发, 第一个人走到(x1, y1), 第二个人走到(x2, y2)时能获得的最大值(两个人同时走一步)
void bfs() {
  std::queue<Node> que;
  que.push(Node{1, 1, 1, 1, 0});
  while (!que.empty()) {
    int x1 = que.front().x1, y1 = que.front().y1;
    int x2 = que.front().x2, y2 = que.front().y2;
    int value = que.front().value;
    que.pop();
    dp[x1][y1][x2][y2] = std::max(dp[x1][y1][x2][y2], value);

    // 2 * 2
    for (int u = 0; u < 2; ++u) {
      for (int v = 0; v < 2; ++v) {
        int newx1 = x1 + dx[u], newy1 = y1 + dy[u];
        int newx2 = x2 + dx[v], newy2 = y2 + dy[v];
        if (newx1 >= 1 && newx1 <= m && newx2 >= 1 && newx2 <= m &&
            newy1 >= 1 && newy1 <= n && newy2 >= 1 && newy2 <= n) {
          if ((newx1 == m && newy1 == m && newx2 == m && newy2 == n) || !(newx1 == newx2 && newy1 == newy2))
            que.push(Node{newx1, newy1, newx2, newy2, value + mp[newx1][newy1] + mp[newx2][newy2]});
        }
      }
    }
  }
}
int main() {
  scanf("%d %d", &m, &n);
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%d", &mp[i][j]);
    }
  }
  std::memset(dp, -0x3f3f3f, sizeof dp);
  bfs();
  printf("%d\n", dp[m][n][m][n]);
  return 0;
}
