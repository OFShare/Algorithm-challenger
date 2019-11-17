/*
 * Created by OFShare on 2019-11-15
 *
 */

#include <bits/stdc++.h>

const int INF = 1e9;
const int maxn = 10 + 5;
const int maxm = 1e3 + 5;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int h, w, n;
char mp[maxm][maxm];
// 1 -> (x1, y1)
// 2 -> (x2, y2)
// ...
std::pair<int,int> A[maxn];
int dis[maxm][maxm];

// 从start -> end需要走的最少的步数
int bfs(std::pair<int, int> start, std::pair<int, int> end) {
  std::memset(dis, 0x3f3f3f, sizeof dis);
  std::queue< std::pair<int, int> > que;
  que.push({start.first, start.second});
  dis[start.first][start.second] = 0;

  while (!que.empty()) {
    int x = que.front().first;
    int y = que.front().second;
    que.pop();

    // 找到了
    if (x == end.first && y == end.second)
      return dis[x][y];
    for (int i = 0; i < 4; ++i) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx >= 0 && yy >= 0 && mp[xx][yy] == '.' && dis[xx][yy] >= INF) {
        que.push({xx, yy});
        dis[xx][yy] = dis[x][y] + 1;
      }
    }
  }
}

int main() {
  scanf("%d %d %d", &h, &w, &n);
  // 起点
  int s_x, s_y;
  for (int i = 1; i <= h; ++i) {
    scanf("%s", mp[i] + 1);
  }
  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j) {
      if (mp[i][j] == 'S') {
        s_x = i;
        s_y = j;
        // 变成'.', 方便处理
        mp[i][j] = '.';
      } else if (mp[i][j] >= '1' && mp[i][j] <= '9') {
        A[mp[i][j] - '0'].first = i;
        A[mp[i][j] - '0'].second = j;
        // 变成'.', 方便处理
        mp[i][j] = '.';
      }
    }
  }
  A[0].first = s_x;
  A[0].second = s_y;
  int ans = 0;

  for (int i = 1; i <= n; ++i) {
    ans += bfs(A[i - 1], A[i]);
  }
  printf("%d\n", ans);
  return 0;
}
