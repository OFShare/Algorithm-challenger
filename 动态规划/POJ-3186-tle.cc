/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-06 13:52:29 PM
 * File Name     : POJ-3186.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 2e3 + 5;
int n, A[N];

struct node {
  int i, j, k;
  node(int i, int j, int k): i(i), j(j), k(k) {}
  bool operator<(const node &rhs) const {
    std::vector<int> vec1;
    std::vector<int> vec2;
    vec1.push_back(i); vec1.push_back(j); vec1.push_back(k);
    vec2.push_back(rhs.i); vec2.push_back(rhs.j); vec2.push_back(rhs.k);
    return vec1 < vec2; 
  }
};
std::map<node, int> mp;
// 区间i ~ j, 下标为k时, 能获得的最大价值之和
int dfs(int i, int j, int k) {
  if (i == j) 
    return A[i] * k;
  // 记忆化
  if (mp.find(node(i, j, k)) != mp.end())
    return mp[node(i, j, k)];
  int ret1 = dfs(i + 1, j, k + 1) + k * A[i];
  int ret2 = dfs(i, j - 1, k + 1) + k * A[j];
  int ret = std::max(ret1, ret2);
  mp[node(i, j, k)] = ret;
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) 
    scanf("%d", &A[i]);
  int ret = dfs(1, n, 1);
  printf("%d\n", ret);
  return 0;
}
