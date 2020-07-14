/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-09 16:26:55 PM
 * File Name     : P1683.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 20 + 5;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int w, h;
char mp[N][N];

// 返回从(x, y)出发能走的最多的砖块数
int dfs(int x, int y) {
  int ret = 1;
  mp[x][y] = '#';
  // 4个方向搜索
  for (int i = 0; i < 4; ++i) {
    int newx = x + dx[i], newy = y + dy[i];
    if (newx >= 1 && newx <= h && newy >= 1 && newy <= w && mp[newx][newy] == '.')
      ret += dfs(newx, newy);
  }
  return ret;
}
int main() {
  scanf("%d %d", &w, &h);
  for (int i = 1; i <= h; ++i) {
    scanf("%s", mp[i] + 1);
  }
  int x, y;
  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j) {
      if (mp[i][j] == '@') {
        x = i, y= j;
      }
    }
  }
  printf("%d\n", dfs(x, y));
  return 0;
}
