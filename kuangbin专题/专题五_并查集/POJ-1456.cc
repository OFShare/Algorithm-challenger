/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-13 23:46:02 PM
 * File Name     : POJ-1456.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <algorithm>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e4 + 5;
struct node {
  int profit, deadline;
  bool operator<(const node &rhs) const {
    return profit > rhs.profit;
  }
}A[N];

// fa[i]: 表示i结点的父节点的编号.
// 在本题中, 并查集相等于一个单向链表, 举例来说, 9 -> 8 -> 7 -> 6
// 9的父亲结点是8, 8的父亲结点是7, ..., 然后本题用根节点表示这个日期可以卖东西
// 如果根结点是0, 表示这个联通块都不能卖东西了, 如3 -> 2 -> 1 -> 0
// 注意一点这个联通块一定是连续的, 不会出现类似4 -> 2 -> 1 -> 0, 中间少了3, 这是不可能的
// 因为我们代码里fa[rt] = rt - 1.
int fa[N];
int find_union(int x) {
  return fa[x] == x? x: fa[x] = find_union(fa[x]);
}
int n;
int main() {
  while (scanf("%d", &n) != EOF) {
    int max_deadline = 0;
    for (int i = 1; i <= n; ++i)
      scanf("%d %d", &A[i].profit, &A[i].deadline), max_deadline = std::max(max_deadline, A[i].deadline);
    // 并查集初始化
    for (int i = 0; i <= max_deadline; ++i) 
      fa[i] = i;

    int ans = 0;
    // 优先考虑利润大的, 然后它在那一天卖是从它的截止日期往前面推, 找到第一个可以卖的日期
    // 当然可以for循环一遍找, 但是我们也可以用并查集优化, 快速找到第一个可以卖的日期(或没有可以卖的日期了)
    std::sort(A + 1, A + 1 + n);
    for (int i = 1; i <= n; ++i) {
      int rt = find_union(A[i].deadline);
      if (rt > 0) 
        ans += A[i].profit, fa[rt] = rt - 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
