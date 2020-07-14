/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-25 18:41:14 PM
 * File Name     : acw170.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e2 + 5;
int n, path[N];

// 目前搜到pos位置(考虑pos位置填什么数), 最大深度限制为dep, 能否搜到答案
bool dfs(int pos, const int &dep) {
  // 递归的边界
  if (pos - 1 == dep) return path[pos - 1] == n;

  // 考虑pos位置填什么数, 从大到小 
  // vis数组记录pos位置填不要填重复的数
  bool vis[N] = {0};
  for (int i = pos - 1; i >= 1; --i) {
    for (int j = i; j >= 1; --j) {
      int number = path[i] + path[j];
      if (number <= n && number > path[pos - 1] && !vis[number]) {
        path[pos] = number;
        vis[number] = true;
        if (dfs(pos + 1, dep)) return true;
      }
    }
  }
  return false;
}
int main() {
  while (scanf("%d", &n) && n) {
    int dep = 1;
    for (; ; ++dep) {
      path[1] = 1;
      if (dfs(2, dep)) break;
    }
    for (int i = 1; i <= dep; ++i) {
      if (i == 1) printf("%d", path[i]);
      else printf(" %d", path[i]);
    }
    printf("\n");
  }
  return 0;
}
