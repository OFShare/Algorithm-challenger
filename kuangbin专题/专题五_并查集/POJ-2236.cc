/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-10 19:59:45 PM
 * File Name     : POJ-2236.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <cmath>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e3 + 5;
int n, D;
struct point {
  int x, y;
}A[N];

int fa[N];
int find_union(int x) {
  return fa[x] == x? x: fa[x] = find_union(fa[x]);
}
int distance(int i, int j) {
  return (A[i].x - A[j].x) * (A[i].x - A[j].x) + (A[i].y - A[j].y) * (A[i].y - A[j].y);
}
// 维护那些点已经被修好了
std::vector<int> vec;
int main() {
  scanf("%d %d", &n, &D);
  for (int i = 1; i <= n; ++i)
    scanf("%d %d", &A[i].x, &A[i].y);
 
  // 并查集的初始化
  for (int i = 1; i <= n; ++i)
    fa[i] = i;
  char tmp[N];
  int a, b, x;
  while (scanf("%s", tmp + 1) != EOF) {
    bool testing = false;
    if (tmp[1] == 'S') scanf("%d %d", &a, &b), testing = true;
    else scanf("%d", &x);

    if (testing) {
      int rt1 = find_union(a);
      int rt2 = find_union(b);
      if (rt1 != rt2) printf("FAIL\n");
      else printf("SUCCESS\n");
    } else {
      // 修好的和修好的进行更新
      for (int i = 0; i < vec.size(); ++i) {
        if (distance(vec[i], x) <= D * D) {
          int rt1 = find_union(vec[i]);
          int rt2 = find_union(x);
          if (rt1 != rt2) {
            fa[rt1] = rt2;
          }
        }
      }
      // 加入
      vec.push_back(x);
    }
  }
  return 0;
}
