/*
 * Created by OFShare on 2019-11-15
 *
 */

#include <cstdio>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstring>

const int INF = 1e9;
const int maxn = 300 + 5;

const int dx[] = {1, 0, -1, 0, 0};
const int dy[] = {0, 1, 0, -1, 0};
int m;
int ms[maxn][maxn];
int dis[maxn][maxn];

struct node {
  int x, y;
};

int bfs() {
  std::memset(dis, -1, sizeof dis);
  // 起点是安全的
  if (ms[0][0] >= INF)
    return 0;

  std::queue<node> que;
  que.push({0, 0});
  dis[0][0] = 0;

  while (!que.empty()) {
    node point = que.front(); que.pop();
    // 找到一个安全的地方
    if (ms[point.x][point.y] >= INF)
      return dis[point.x][point.y];
    for (int i = 0; i < 4; ++i) {
      int newx = point.x + dx[i], newy = point.y + dy[i];
      if (newx >= 0 && newy >= 0 && dis[newx][newy] == -1 && dis[point.x][point.y] + 1 < ms[newx][newy]) {
        que.push({newx, newy});
        dis[newx][newy] = dis[point.x][point.y] + 1;
      }
    }
  }

  return -1;
}

int main() {
  scanf("%d", &m);
  std::memset(ms, 0x3f3f3f, sizeof ms);
  // 预处理, 每个坐标最早被摧毁的时间
  for (int i =1; i <= m; ++i) {
    int x, y, t;
    scanf("%d %d %d", &x, &y, &t);
    for (int i = 0; i < 5; ++i) {
      int newx = x + dx[i], newy = y + dy[i];
      if (newx >= 0 && newy >= 0)
        ms[newx][newy] = std::min(ms[newx][newy], t);
    }
  }
  printf("%d\n", bfs());
  return 0;
}
