/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-09 16:35:27 PM
 * File Name     : P2372.cc
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
const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
int m, n, x, y, ans = 0;
bool vis[N][N];
char mp[N][N];

// 从(x, y)开始统计周长(对答案的贡献)
void dfs(int x, int y) {
  vis[x][y] = true;
  if (y - 1 < 1 || (y - 1 >= 1 && mp[x][y - 1] == '.')) ans += 1;
  if (x - 1 < 1 || (x - 1 >= 1 && mp[x - 1][y] == '.')) ans += 1;
  if (y + 1 > n || (y + 1 <= n && mp[x][y + 1] == '.')) ans += 1;
  if (x + 1 > m || (x + 1 <= m && mp[x + 1][y] == '.')) ans += 1;
  for (int i = 0; i < 8; ++i) {
    int newx = x + dx[i], newy = y + dy[i];
    if (newx >= 1 && newx <= m && newy >= 1 && newy <= n && mp[newx][newy] == 'X' && vis[newx][newy] == false)
      dfs(newx, newy);
  }
}
int main() {
  scanf("%d %d %d %d", &m, &n, &x, &y);
  for (int i = 1; i <= m; ++i) {
    scanf("%s", mp[i] + 1);
  }
  dfs(x, y);
  printf("%d\n", ans);
  return 0;
}
