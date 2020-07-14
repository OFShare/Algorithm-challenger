/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-09 16:53:23 PM
 * File Name     : P1256.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 182 + 5;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int n, m;
int distance[N][N];
char mp[N][N];
bool vis[N][N];

struct Node {
  int x, y, dis;
};
// 从多源点1开始bfs搜寻求最短路
void bfs() {
  std::queue<Node> que;
  // 把源点1放进最初的队列里
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (mp[i][j] == '1') {
        que.push(Node{i, j, 0});
        vis[i][j] = true;
      }
    }
  }
  while (!que.empty()) {
    int x = que.front().x, y = que.front().y, dis = que.front().dis;
    que.pop();
    vis[x][y] = true;
    distance[x][y] = dis;
    for (int i = 0; i < 4; ++i) {
      int newx = x + dx[i], newy = y + dy[i];
      if (newx >= 1 && newx <= n && newy >= 1 && newy <= m && vis[newx][newy] == false) {
        vis[newx][newy] = true;
        que.push(Node{newx, newy, dis + 1});
      }
    }
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", mp[i] + 1);
  }
  bfs();
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      printf("%d ", distance[i][j]);
    }
    printf("\n");
  }
  return 0;
}
