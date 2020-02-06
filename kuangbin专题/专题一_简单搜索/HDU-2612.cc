/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-06 11:15:50 AM
 * File Name     : HDU-2612.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>
#include <map>
#include <cstring>
#include <queue>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 2e2 + 5;
const int INF = 1e9;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int n, m;
char mp[N][N];

int Y_x, Y_y;
int M_x, M_y;

bool vis[N][N];
std::map<std::pair<int, int>, int> Y_mp;
std::map<std::pair<int, int>, int> M_mp;
bool valid(int x, int y) {
  if (x < 1 || x > n || y < 1 || y > m) return false;
  if (vis[x][y] || mp[x][y] == '#') return false;
  return true; 
}
struct node {
  int x, y;
  int step;
};
void bfs(node s, bool is_Y) {
  std::queue<node> que;
  que.push(s);

  while (!que.empty()) {
    node p = que.front();
    que.pop();
    int x = p.x, y = p.y, step = p.step;
    vis[x][y] = true;
   
    // 找到了
    if (mp[x][y] == '@') {
      if (is_Y) Y_mp[{x, y}] = step;
      else M_mp[{x, y}] = step;
    }

    for (int i = 0; i < 4; ++i) {
      int newx = x + dx[i], newy = y + dy[i];
      if (valid(newx, newy)) {
        vis[newx][newy] = true;
        que.push({newx, newy, step + 11});
      }
    }
  }
}
int main() {
  while (scanf("%d %d", &n, &m) != EOF) {
    for (int i = 1; i <= n; ++i) 
      scanf("%s", mp[i] + 1);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (mp[i][j] == 'Y') 
          Y_x = i, Y_y = j;
        if (mp[i][j] == 'M') 
          M_x = i, M_y = j;
      }
    }
    Y_mp.clear();
    M_mp.clear();
    std::memset(vis, 0, sizeof vis);
    bfs({Y_x, Y_y, 0}, true);
    std::memset(vis, 0, sizeof vis);
    bfs({M_x, M_y, 0}, false);
    
    int ans = INF;
    std::map<std::pair<int, int>, int>::iterator ite = Y_mp.begin();
    for (; ite != Y_mp.end(); ++ite) {
      std::pair<int, int> p = ite -> first;
      int time_y = ite -> second;
      int time_m = INF;
      if (M_mp.find(p) != M_mp.end())
        time_m = M_mp.find(p) -> second;
      ans = std::min(ans, time_y + time_m);
    }
    printf("%d\n", ans);
  }
  return 0;
}
