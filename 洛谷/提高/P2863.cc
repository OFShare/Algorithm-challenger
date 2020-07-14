/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-30 23:37:38 PM
 * File Name     : P2863.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e4 + 5;
int n, m, cnt, top, color_num, dfn[N], low[N], stack[N], vis[N], color[N];
std::vector<int> sons[N];

// tarjan入门文章: https://www.luogu.com.cn/blog/styx-ferryman/chu-tan-tarjan-suan-fa-qiu-qiang-lian-tong-fen-liang-post
// 找出结点u所在的强连通分量
void tarjan(int u) {
  dfn[u] = low[u] = ++cnt;
  stack[++top] = u;
  vis[u] = true;
  for (int i = 0; i < sons[u].size(); ++i) {
    int v = sons[u][i];
    if (dfn[v] == 0) tarjan(v);
    low[u] = std::min(low[u], low[v]);
  }
  // 到这里以u为根的子树就都遍历完了
  // 当一个节点的dfn值和low值相等时，这个节点是一个强联通分量的“根”, 此时栈里面结点u及栈后面的元素它们一起构成一个强连通分量
  if (dfn[u] == low[u]) {
    ++color_num;
    while (dfn[stack[top]] != low[stack[top]]) {
      color[stack[top]] = color_num;
      vis[stack[top--]] = false;
    }
    color[stack[top]] = color_num;
    vis[stack[top--]] = false;
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    sons[u].push_back(v);
  }
  for (int i = 1; i <= n; ++i) {
    if (color[i] == 0) {
      tarjan(i);
    }
  }
  assert(top == 0);
  for (int i = 1; i <= n; ++i) {
    assert(vis[i] == false);
  }
  std::map<int, int> mp;
  for (int i = 1; i <= n; ++i) {
    mp[color[i]]++;
  }
  int ans = 0;
  for (auto &ch: mp) {
    if (ch.second > 1) ++ans;
  }
  printf("%d\n", ans);
  return 0;
}
