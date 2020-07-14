/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-14 15:23:07 PM
 * File Name     : ZOJ-3261.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <map>
#include <cstring>
#include <string>
#include <vector>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 5e4 * 2 + 5;
int n, m, q;
struct edge {
  int start, end;
  bool is_destroy;
}A[N];
// (a --> b)这条边对应A数组的那一个下标
std::map<std::pair<int, int>, int> mp;

struct query {
  char op[10];
  int start, end;
}Q[N];

int fa[N], value[N];
int find_union(int x) {
  return x == fa[x]? x: fa[x] = find_union(fa[x]);
}
int main() {
  int kase = 0;
  while (scanf("%d", &n) != EOF) {
    mp.clear();
    for (int i = 0; i < n; ++i) 
      scanf("%d", &value[i]);
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
      int a, b;
      scanf("%d %d", &a, &b);
      if (a > b) std::swap(a, b);
      A[i].start = a, A[i].end = b, A[i].is_destroy = false;
      mp[{a, b}] = i;
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; ++i) {
      scanf("%s", Q[i].op);
      if (Q[i].op[0] == 'q') scanf("%d", &Q[i].start);
      else {
        scanf("%d %d", &Q[i].start, &Q[i].end);
        if (Q[i].start > Q[i].end) std::swap(Q[i].start, Q[i].end);
        int index = mp[{Q[i].start, Q[i].end}];
        A[index].is_destroy = true;
      }
    }

    // 前面是对输入的处理
    // 下面开始并查集建图, 然后倒着询问
    for (int i = 0; i < n; ++i)
      fa[i] = i;
    for (int i = 1; i <= m; ++i) {
      if (A[i].is_destroy == false) {
        int rt1 = find_union(A[i].start);
        int rt2 = find_union(A[i].end);
        if (rt1 == rt2) continue;
        // 值小的结点连向值大的结点, 值相等的编号大的连向编号小的, 即值大编号小的的当作根
        if (value[rt1] > value[rt2]) std::swap(rt1, rt2);
        if (value[rt1] == value[rt2] && rt1 < rt2) std::swap(rt1, rt2);
        fa[rt1] = rt2;  
      }
    }
    std::vector<int> ans;
    // 第i条询问时, 恢复第i - 1条时图的状态
    for (int i = q; i >= 1; --i) {
      if (Q[i].op[0] == 'q') {
        int rt = find_union(Q[i].start);
        if (value[rt] > value[Q[i].start]) ans.push_back(rt);
        else ans.push_back(-1);
      } else {
        int rt1 = find_union(Q[i].start); 
        int rt2 = find_union(Q[i].end); 
        if (rt1 == rt2) continue;
        if (value[rt1] > value[rt2]) std::swap(rt1, rt2);
        if (value[rt1] == value[rt2] && rt1 < rt2) std::swap(rt1, rt2);
        fa[rt1] = rt2;  
      }
    }
    if (kase++ > 0)
      printf("\n");
    for (int i = ans.size() - 1; i >= 0; --i) {
      printf("%d\n", ans[i]);
    }
  }
  return 0;
}
