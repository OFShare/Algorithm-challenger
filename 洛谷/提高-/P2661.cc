/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-16 00:11:14 AM
 * File Name     : P2661.cc
 */

#include <bits/stdc++.h>
const int N = 2e5 + 5;
// fa[i]表示结点i的父亲结点, dis[i]表示结点i到它的父亲结点的路径长度
int n, fa[N], dis[N];

// 从结点x开始向上更新, 函数返回根结点, 路径压缩后, 也要保证fa, dis数组里保存的数和定义是一致的
// 即fa[i]始终维护结点i的父亲结点, dis[i]始终维护结点i到它的父亲结点的路径长度
int find_union(int x) {
  // 递归的边界
  if (fa[x] == x) {dis[x] = 0; return x;} 
  int pre = fa[x], root = find_union(fa[x]);
  fa[x] = root;
  // dis[x] = dis[pre] + 1;
  dis[x] += dis[pre];
  return root;
}
int main() {
  scanf("%d", &n);
  // 并查集初始化
  for (int i = 1; i <= n; ++i) fa[i] = i, dis[i] = 0;
  int ans = 1e9;
  for (int i = 1; i <= n; ++i) {
    int u = i, v;
    scanf("%d", &v);
    // u -> v
    int ua = find_union(u), va = find_union(v);
    // 找到一条环
    if (ua == va) {
      assert(fa[v] == u);
      ans = std::min(ans, dis[v] + 1);
    } else {
      assert(u == ua);
      fa[u] = v;
      dis[u] = 1;
    }
    // std::cout << "u: " << u << " v: " << v << " fa[u]: " << fa[u] << " dis[u]: " << dis[u] << std::endl;
  }
  printf("%d\n", ans);
  return 0;
}
