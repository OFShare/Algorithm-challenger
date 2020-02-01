/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-01 13:56:35 PM
 * File Name     : POJ-2251.cc
 */

#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <cmath>

const int N = 30 + 3;
const int dx[] = {1, 0, -1, 0, 0, 0};
const int dy[] = {0, 1, 0, -1, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};

struct point {
  int x, y, z;
  int step;
};

int L, R, C;

// mp: (x, y, z)
char mp[N][N][N];
// vis表示访问过, 或已经进入队列里了
bool vis[N][N][N];

int s_x, s_y, s_z;
int e_x, e_y, e_z;

bool valid(int x, int y, int z) {
  if (x < 1 || x > R || y < 1 || y > C || z < 1 || z > L) 
    return false;
  if (vis[x][y][z])
    return false;
  if (mp[x][y][z] == '#')
    return false;
  return true;
}

int bfs(point s) {
  std::memset(vis, 0, sizeof vis);
  // std::priority_queue<point, std::vector<point>, std::greater<point> > que;
  std::queue<point> que;
  que.push(s);

  while (!que.empty()) {
    point p = que.front();
    que.pop();
    int x = p.x, y = p.y, z = p.z, step = p.step;
  
    // 找到
    if (x == e_x && y == e_y && z == e_z)
      return step;
    vis[x][y][z] = true;
    for (int i = 0; i < 6; ++i) {
      int newx = x + dx[i], newy = y + dy[i], newz = z + dz[i];
      if (valid(newx, newy, newz)) {
        que.push(point{newx, newy, newz, step + 1});
        vis[newx][newy][newz] = true;
      }
    }

  }
  return -1;
}

int main() {
  while (std::cin >> L >> R >> C && L + R + C != 0) {
    for (int k = 1; k <= L; ++k) {
      for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
          std::cin >> mp[i][j][k];
          if (mp[i][j][k] == 'S')
            s_x = i, s_y = j, s_z = k;
          if (mp[i][j][k] == 'E')
            e_x = i, e_y = j, e_z = k;
        }
      }
    }
    // printf("S: %d, %d, %d\n", s_x, s_y, s_z); 
    // printf("E: %d, %d, %d\n", e_x, e_y, e_z); 
    int ret = bfs(point{s_x, s_y, s_z, 0});
    if (ret == -1) std::cout << "Trapped!" << std::endl;
    else std::cout << "Escaped in " << ret << " minute(s)." << std::endl;
  }
}
