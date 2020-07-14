/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-30 18:20:54 PM
 * File Name     : acw172.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 5e2 + 5;
int n, m;
char mp[N][N];

// 上下左右
const int dir[3][4][3] = {
  {{-2, 0, 2}, {1, 0, 2}, {0, -2, 1}, {0, 1, 1}}, // lie = 0 
  {{-1, 0, 1}, {1, 0, 1}, {0, -1, 0}, {0, 2, 0}}, // lie = 1
  {{-1, 0, 0}, {2, 0, 0}, {0, -1, 2}, {0, 1, 2}}, // lie = 2
};
// 状态判重
bool vis[N][N][3];
struct State {
  // lie: 0立着, 1横着, 2竖着
  // x, y左上角的坐标
  int x, y, lie;
  int dis;
}Start, End;

bool valid(int newx, int newy) {
  return newx >= 1 && newx <= n && newy >= 1 && newy <= m;
}
bool valid(int newx, int newy, int lie) {
  if (lie == 0) {
    if (valid(newx, newy) && (mp[newx][newy] == '.' || mp[newx][newy] == 'X' || mp[newx][newy] == 'O')) return true;
    return false;
  } else if (lie == 1) {
    if (valid(newx, newy)) {
      if (mp[newx][newy] == '#' || mp[newx][newy + 1] == '#') return false;
      return true;
    } else {
      return false;
    }
  } else if (lie == 2) {
    if (valid(newx, newy)) {
      if (mp[newx][newy] == '#' || mp[newx + 1][newy] == '#') return false;
      return true;
    } else {
      return false;
    }
  }
}
int bfs() {
  std::queue<State> que;
  que.push(Start);
  vis[Start.x][Start.y][Start.lie] = true;

  while (!que.empty()) {
    int x = que.front().x, y = que.front().y, lie = que.front().lie, dis = que.front().dis;
    // std::cout << "newx: " << x << " newy: " << y << " lie: " << lie << std::endl;
    que.pop();
    //找到了 
    if (x == End.x && y == End.y && lie == End.lie) return dis;

    for (int i = 0; i < 4; ++i) {
      int dx = dir[lie][i][0], dy = dir[lie][i][1], dlie = dir[lie][i][2];
      int newx = x + dx, newy = y + dy;
      if (!valid(newx, newy, dlie)) continue;
      if (vis[newx][newy][dlie]) continue;
      que.push({newx, newy, dlie, dis + 1});
      vis[newx][newy][dlie] = true;
    }
  }
  return -1;
}
int main() {
  while (scanf("%d %d", &n, &m) && n + m) {
    for (int i = 1 ; i <= n; ++i) {
      scanf("%s", mp[i] + 1);
    }
    std::memset(vis, 0, sizeof vis);
    Start.dis = 0;
    bool found = false;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (mp[i][j] == 'X' && !found) {
          if (j + 1 <= m && mp[i][j + 1] == 'X') Start.x = i, Start.y = j, Start.lie = 1;
          else if (i + 1 <= n && mp[i + 1][j] == 'X') Start.x = i, Start.y = j, Start.lie = 2;
          else Start.x = i, Start.y = j, Start.lie = 0;
          found = true;
        }
        if (mp[i][j] == 'O') {
          End.x = i, End.y = j, End.lie = 0;
        }
      }
    }
    int ret = bfs();
    if (ret == -1) printf("Impossible\n");
    else printf("%d\n", ret);
  }
  return 0;
}
