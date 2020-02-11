/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-11 11:07:20 AM
 * File Name     : HDU-3038.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 2e5 + 5;
int fa[N],v[N];
// 更新x到根节点的v数组, 以及改变它的父节点为根(即路径压缩)
// 这里解释一下v数组的含义: 大多数人会这样认为, v[x]表示x到根结点的路径长度, 这其实是错误的说法.(在路径压缩后是正确的)
// 准确的说应该是: v[x]表示x到它的父亲结点的路径长度
// 因为路径被压缩, 即x直接连到子树的根节点上去, 所以x的父亲结点就是根节点了
// 因为路径被压缩, 所以当从x结点向上更新时, 这一路上去的所有结点都直接和根节点连接.

// 总结一句话就是: 假设结点x的父亲结点是y, v[x]始终维护的是x指向y这条有向边的权值(即v[x]表示x到它的父亲结点(y)的路径长度)
// 因为并查集是一个联通块, 在这个联通块里任意两点的关系都可以求出来, 本题任意两点的关系是[x, y)的和
int find_union(int x) {
  if (fa[x] == x) return x;
  int rt = find_union(fa[x]);
  v[x] += v[fa[x]];
  return fa[x] = rt;
}
int n, m;
int main() {
  while (scanf("%d %d", &n, &m) != EOF) {
    int ans = 0;
    // 带权并查集初始化
    for (int i = 1; i <= n + 1; ++i) 
      fa[i] = i, v[i] = 0;

    for (int i = 1; i <= m; ++i) {
      int x, y, s;
      scanf("%d %d %d", &x, &y, &s);
      // 原来输入表示[x, y]的和为s, 现在我们将y加一, 表示的是
      // [x, y)的和为s. 为什么选择左闭右开区间呢? 一个简单的原因是
      // 如果我们[3, 3]的和为10, 那么在图上就是3结点和自己连, 形成了自环, 非常不好处理
      // 如果改成[3, 4)的和为10, 那么在图上就是3结点连接4结点, 非常好处理.
      y += 1;
      
      int rt1 = find_union(x);
      int rt2 = find_union(y);
      if (rt1 != rt2) {
        fa[rt1] = rt2;
        // 更新rt1的v数组
        v[rt1] = -v[x] + s + v[y];
      } else {
        if (s != v[x] - v[y]) ans++; 
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
