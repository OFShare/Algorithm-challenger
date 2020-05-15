/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-09 22:17:30 PM
 * File Name     : P1462.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 5e4 + 5;
int n, m, b, f[N];

int head[N];

struct Node {
  int v, w, next;
}edge[N * 2];

int cnt = 0;
void addEdge(int u, int v, int w) {
  ++cnt;
  edge[cnt].v = v;
  edge[cnt].w = w;
  edge[cnt].next = head[u];
  head[u] = cnt;
}

int dis[N], vis[N];
int Dijkstra(int value) {
  std::memset(dis, 0x3f3f3f, sizeof dis);
  std::memset(vis, 0, sizeof vis);
  dis[1] = 0;
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > que;
  que.push({dis[1], 1});
  if (f[1] > value) return -1;

  while (!que.empty()) {
    auto p = que.top(); que.pop();
    int u = p.second, d = p.first;
    // 找到了最小值
    if (vis[n]) break;
    if (vis[u]) continue;
    vis[u] = true;
    for (int i = head[u]; i != -1; i = edge[i].next) {
      int v = edge[i].v, w = edge[i].w;
      // 尝试更新, 点权不能超过value
      if (f[v] <= value && d + w < dis[v]) {
        dis[v] = d + w;
        que.push({dis[v], v});
      }
    }
  }
  if (dis[n] <= b) return 1;
  else return -1;
}
int main() {
  std::memset(head, -1, sizeof head);

  scanf("%d %d %d", &n, &m, &b);
  int L = 2e9, R = -2e9;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &f[i]);
    L = std::min(L, f[i]);
    R = std::max(R, f[i]);
  }
  for (int i = 1; i <= m; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    addEdge(u, v, w);
    addEdge(v, u, w);
  }
  if (Dijkstra(R) == -1) printf("AFK\n");
  // 整数域二分, 注意是[L, R]
  else {
    for (int i = 0; i < 50; ++i) {
      int mid = L + (R - L) / 2;
      if (Dijkstra(mid) == -1) L = mid + 1;
      else R = mid;
    }
    assert(L == R);
    printf("%d\n", L);
  }
  return 0;
}
