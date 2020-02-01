/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-01 23:45:56 PM
 * File Name     : POJ-3278.cc
 */

#include <cstdio>
#include <queue>

const int MAXN = 2e5 + 5;
int N, K;
struct node {
  int x, step;
};
bool vis[MAXN];
bool valid(int x) {
  if (x < 0 || x >= MAXN || vis[x]) return false;
  return true;
}
int bfs(int s) {
  std::queue<node> que;
  que.push({s, 0});

  while (!que.empty()) {
    int x = que.front().x, step = que.front().step;
    que.pop();
  
    // 找到了
    if (x == K)
      return step;
    vis[x] = true;
    if (valid(x - 1))
      que.push({x - 1, step + 1}), vis[x - 1] = true;
    if (valid(x + 1))
      que.push({x + 1, step + 1}), vis[x + 1] = true;
    if (valid(x * 2))
      que.push({x * 2, step + 1}), vis[x * 2] = true;
  }
  return -1;
}
int main() {
  scanf("%d %d", &N, &K);
  int ret = bfs(N);
  printf("%d\n", ret);
  return 0;
}
