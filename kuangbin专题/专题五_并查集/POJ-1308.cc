/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-14 16:45:48 PM
 * File Name     : POJ-1308.cc
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

const int N = 1e4 + 5;
int a, b;
int fa[N];
int find_union(int x) {
  return x == fa[x]? x: fa[x] = find_union(fa[x]);
}
int main() {
  int kase = 0;
  bool unique = true;
  std::vector<int> vec;
  for (int i = 0; i <= N - 3; ++i)
    fa[i] = i;
  while (scanf("%d %d", &a, &b) && a >= 0 && b >= 0) {
    if (a == 0 && b == 0) {
      // 构成一颗树的话, 根结点只有一个
      int pre = -1;
      for (int i = 0; i < vec.size(); ++i) {
        if (pre == -1) pre = find_union(vec[i]);
        int cur = find_union(vec[i]);
        if (cur != pre) {
          unique = false;
          break;
        }
      }
      if (unique) printf("Case %d is a tree.\n", ++kase);
      else printf("Case %d is not a tree.\n", ++kase);
      // 重新初始化
      unique = true;
      for (int i = 0; i <= N - 3; ++i)
        fa[i] = i;
      vec.clear();
      continue;
    }
    vec.push_back(a);
    vec.push_back(b);
    if (unique == false) continue;
    int rt1 = find_union(a);
    int rt2 = find_union(b);
    if (rt1 == rt2) unique = false;
    else fa[rt1] = rt2;
  }
  return 0;
}
