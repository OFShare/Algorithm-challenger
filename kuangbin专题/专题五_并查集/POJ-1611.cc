/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-10 20:48:34 PM
 * File Name     : POJ-1611.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 3e4 + 5;
int fa[N], count[N];
int find_union(int x) {
  return x == fa[x]? x: fa[x] = find_union(fa[x]);
}
int n, m;
int main() {
  while (scanf("%d %d", &n, &m) && n + m) {
    // 并查集初始化
    for (int i = 0; i <= n - 1; ++i) 
      fa[i] = i, count[i] = 1;

    for (int i = 1; i <= m; ++i) {
      int k;
      scanf("%d", &k);
      // 前面的已经在一个联通块里面了, 所以当前的x只需要和前一个pre进行合并即可
      int pre = -1;
      for (int j = 1; j <= k; ++j) {
        int x;
        scanf("%d", &x);
        if (pre == -1) pre = x;
        else {
          int rt1 = find_union(pre);
          int rt2 = find_union(x);
          if (rt1 != rt2)
            fa[rt1] = rt2, count[rt2] += count[rt1], pre = x;
        }
      }
    }
    printf("%d\n", count[find_union(0)]);
  }
  return 0;
}
