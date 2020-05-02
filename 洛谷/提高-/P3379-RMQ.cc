/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-30 19:58:07 PM
 * File Name     : P3379-RMQ.cc
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

const int N = 500000 * 2 + 5;
int n, m, root, cnt, id[N], depth[N], node[N / 2];
std::vector<int> sons[N / 2];

// id[x]维护下标为x时, 对应的结点
// depth[x]维护下标为x时, 对应结点的深度
// node[x]维护结点为x时, 最后访问到的下标
// 这里的下标都是指dfs欧拉序时的编号(即代码里的cnt变量)
// dfs递归维护id, depth, node这些数组
void dfs(int rt, int pre) {
  ++cnt;
  id[cnt] = rt;
  depth[cnt] = depth[node[pre]] + 1;
  node[rt] = cnt;
  for (int i = 0; i < sons[rt].size(); ++i) {
    int v = sons[rt][i];
    if (v != pre) {
      dfs(v, rt);
      // 回溯后也得更新当前结点(即结点rt)
      ++cnt;
      id[cnt] = rt;
      depth[cnt] = depth[node[pre]] + 1;
      node[rt] = cnt;
    }
  }
}
// 对depth数组维护的ST表
// dp[i][j]表示从下标i向右走区间长度为2 ^ j时, 深度最小值的下标
int dp[N][30];
int dfs2(int i, int j) {
  // 递归的边界
  if (j == 0) {
    return dp[i][j] = i;
  }
  // 记忆化
  if (dp[i][j] != -1) return dp[i][j];

  int ret;
  int ret1 = dfs2(i, j - 1);
  int ret2 = dfs2(i + (1 << j - 1), j - 1);
  if (depth[ret1] <= depth[ret2]) ret = ret1;
  else ret = ret2;
  return dp[i][j] = ret;
}
// RMQ, ST表
void init_st() {
  std::memset(dp, -1, sizeof dp);
  for (int i = 1; i <= cnt; ++i) {
    int upper = std::log2(cnt - i + 1);
    for (int j = 0; j <= upper; ++j)
      dfs2(i, j);
  }
}
// 返回[L, R]区间内最小深度值, 所对应下标的结点
int query(int L, int R) {
  int k = std::log2(R - L + 1);
  // 这里返回的是下标
  int ret1 = dp[L][k], ret2 = dp[R - (1 << k) + 1][k];
  if (depth[ret1] <= depth[ret2]) return id[ret1];
  else return id[ret2];
}
int main() {
  n = read(); m = read(); root = read();
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    u = read(), v = read();
    sons[u].push_back(v);
    sons[v].push_back(u);
  }
  dfs(root, 0);
  // for (int i = 1; i <= cnt; ++i) {
  //   std::cout << "id: " << id[i] << std::endl;
  // }
  // for (int i = 1; i <= cnt; ++i) {
  //   std::cout << "depth: " << depth[i] << std::endl;
  // }
  // for (int i = 1; i <= cnt; ++i) {
  //   std::cout << "node: " << node[id[i]] << std::endl;
  // }
  init_st();
  for (int i = 1; i <= m; ++i) {
    int u, v;
    u = read(), v = read();
    int L = std::min(node[u], node[v]), R = std::max(node[u], node[v]);
    write(query(L, R)); putchar('\n');
  }
  return 0;
}
