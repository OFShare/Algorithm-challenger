/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-13 20:30:56 PM
 * File Name     : P1157.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 21 + 5;
int n, r;
int vis[N];

void dfs(int step, std::vector<int> vec) {
  if (step == r) {
    for (int i = 0; i < vec.size(); ++i) {
      printf("%3d", vec[i]);
    }
    printf("\n");
    return ;
  }
  for (int i = 1; i <= n; ++i) {
    if (vis[i] == false) {
      if (vec.size() > 0 && vec[vec.size() - 1] > i) continue;
      vec.push_back(i);
      vis[i] = true;
      dfs(step + 1, vec);
      vis[i] = false;
      vec.pop_back();
    }
  }
}
int main() {
  scanf("%d %d", &n, &r);
  dfs(0, std::vector<int>{});
  return 0;
}
