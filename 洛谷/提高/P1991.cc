/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-19 21:03:12 PM
 * File Name     : P1991.cc
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
struct Node {
  int x, y;
  double w;
  bool operator<(const Node &rhs) const {
    return w < rhs.w;
  }
}edges[N];

int fa[N], S, P, cnt;
std::pair<int, int> A[N];

double distance(int i, int j) {
  return std::sqrt((A[i].first - A[j].first) * (A[i].first - A[j].first) + (A[i].second - A[j].second) * (A[i].second - A[j].second));
}

int find_union(int x) {
  return x == fa[x]? x: fa[x] = find_union(fa[x]);
}
int main() {
  scanf("%d %d", &S, &P);
  for (int i = 1; i <= P; ++i) {
    scanf("%d %d", &A[i].first, &A[i].second);
  }
  for (int i = 1; i <= P; ++i) {
    for (int j = 1; j <= P; ++j) {
      if (i != j) {
        ++cnt;
        edges[cnt].x = i;
        edges[cnt].y = j;
        edges[cnt].w = distance(i, j);
      }
    }
  }

  for (int i = 0; i < 505; ++i) {
    fa[i] = i;
  }
  std::sort(edges + 1, edges + 1 + cnt);
  int k = 0;
  for (int i = 1; i <= cnt; ++i) {
    int x = find_union(edges[i].x), y = find_union(edges[i].y);
    if (x != y) {
      fa[x] = y;
      ++k;
    }
    if (k == P - S) printf("%.2lf\n", edges[i].w), exit(0);
  }
  return 0;
}
