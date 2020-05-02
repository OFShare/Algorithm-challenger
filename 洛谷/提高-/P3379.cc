/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-29 17:51:58 PM
 * File Name     : P3379.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

// 快读
inline int read() {
  int x = 0,f = 1; char ch = getchar();
  while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
  while (isdigit(ch)) {x = x * 10 + ch - 48; ch = getchar();}
  return x * f;
}
// 快输
void write (int x) {
  if (x<0) {putchar('-'); x = -x;}
  int y = 10, len = 1;
  while (y <= x) {y *= 10; len++;}
  while (len--) {y /= 10; putchar(x / y + 48); x %= y;}
}

const int N = 5e5 + 5;
int n, m, root, fa[N][50], depth[N];
std::vector<int> sons[N];

// root表示当前子树根结点, pre表示它的父亲结点
// 该函数递归完成depth和fa数组的更新 
// depth[u]维护的是结点u的深度, 整棵树的根结点初始为1
// fa[u][i]维护的是结点u向上走2 ^ i步后所到的结点, 如果走出去了fa[u][i]就是-1, 因为i >= 0, 所以u结点至少走一步, 所以对于走0步(即不动)需要特判一下
void dfs(int root, int pre) {
  depth[root] = depth[pre] + 1; 

  fa[root][0] = pre;
  // depth[root]- (1 << i) >= 1表示最多走到深度为1的树的根结点
  for (int i = 1; depth[root]- (1 << i) >= 1; ++i) {
    fa[root][i] = fa[fa[root][i - 1]][i - 1];
  }
  // 到这里root结点的depth和fa数组就都已经更新好了, 接下去递归更新它的儿子结点
  for (int i = 0; i < sons[root].size(); ++i) {
    int v = sons[root][i];
    if (v != pre) 
      dfs(v, root);
  }
}
// 返回当前结点u向上走d步后的结点
int Up(int u, int d) {
  if (d == 0) return u;
  // 将d用二进制拆分
  for (int i = 0; i < 30; ++i) {
    if ((1 << i) & d) {
      u = fa[u][i];
    }
  }
  return u;
}
// 返回结点u和结点v的最近公共祖先
int LCA(int u, int v) {
  if (depth[u] > depth[v]) std::swap(u, v);
  v = Up(v, depth[v] - depth[u]);
  if (u == v) return u;
  // 现在u和v在同一深度上(即同一层), upper是算出最多可以跳的范围的上界(从depth[u] - 2 ^ k >= 1推导而来)
  // k是从upper从大到小枚举, 如果从小到大, 最开始跳的很小, 后面跳的很大, 但是到后面如果需要一步很小的跳时, 就直接跳出去了, 所以不能从小到大
  // upper直接等于30也是可以的, 因为这样相当于向上跳2 ^ 30次方, 肯定u和v都跳出去了, 但是它们还是都相等, 所以不影响(我们是不等才往上跳)
  int upper = std::log2(depth[u] - 1);
  upper = 30;
  for (int k = upper; k >= 0; --k) {
    // 加不加下面这句都是可行的, 因为就算跳出去, 那么它们都等于-1(fa[u][k] == fa[v][k]), 不影响
    // if (fa[u][k] == -1) continue;
    if (fa[u][k] != fa[v][k]) {
      u = fa[u][k];
      v = fa[v][k];
    }
  }
  return fa[u][0];
}
int main() {
  n = read(); m = read(); root = read();
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    u = read(); v = read();
    sons[u].push_back(v);
    sons[v].push_back(u);
  }
  std::memset(fa, -1, sizeof fa);
  dfs(root, 0);

  for (int i = 1; i <= m; ++i) {
    int u, v;
    u = read(); v = read();
    write(LCA(u, v)); putchar('\n');
  }
  return 0;
}
