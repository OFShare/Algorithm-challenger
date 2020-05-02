/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-19 20:02:20 PM
 * File Name     : P1194.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 500 * 500 + 5;
int A, B, cnt = 0, fa[505];

struct Node {
  int x, y, w;
  bool operator<(const Node &rhs) const {
    return w < rhs.w;
  }
}edges[N];

int find_union(int x) {
  return x == fa[x]? x: fa[x] = find_union(fa[x]);
}
int main() {
  scanf("%d %d", &A, &B);
  for (int i = 1; i <= B; ++i) {
    for (int j = 1; j <= B; ++j) {
      int w;
      scanf("%d", &w);
      if (i < j) {
        ++cnt;
        edges[cnt].x = i;
        edges[cnt].y = j;
        if (w == 0) edges[cnt].w = A;
        else edges[cnt].w = std::min(A, w);
      }
    }
  }
  
  for (int i = 0; i < 505; ++i) {
    fa[i] = i;
  }
  std::sort(edges + 1, edges + 1 + cnt);
  int ans = A;
  for (int i = 1; i <= cnt; ++i) {
    int x = edges[i].x, y = edges[i].y, w = edges[i].w;
    int fx = find_union(x), fy = find_union(y);
    if (fx != fy) {
      ans += w;
      fa[fx] = fy;
    }
  }
  printf("%d\n", ans);
}
