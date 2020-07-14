/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-11 20:36:58 PM
 * File Name     : UVA-437.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 30 + 5;
int n, ans;
std::map<std::pair<int, int>, int> mp;

struct Node {
  int x, y, z;
}A[N];

// DAG上的最长路, 从现在这个状态出发, 能搜索到的最大高度
int dfs(int row, int col, int hei) {
  // 记忆化
  if (mp.find({row, col}) != mp.end()) {
    return mp[{row, col}];
  }
  int ret = hei;
  // 枚举
  for (int i = 1; i <= n; ++i) {
    // 6种情况
    int x = A[i].x, y = A[i].y, z = A[i].z;
    std::vector<int> vec = {x, y, z};
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (i != j) {
          x = vec[i], y = vec[j], z = vec[3 - i - j];
          if (row > x && col > y) {
            ret = std::max(ret, dfs(x, y, z) + hei);
          }
        }
      }
    }
  }
  return mp[std::make_pair(row, col)] = ret;
}
int main() {
  int kase = 0;
  while (scanf("%d", &n) && n) {
    for (int i = 1; i <= n; ++i) {
      scanf("%d %d %d", &A[i].x, &A[i].y, &A[i].z);
    }
    ans = 0;
    mp.clear();
    // 枚举
    for (int i = 1; i <= n; ++i) {
      // 6种情况
      int x = A[i].x, y = A[i].y, z = A[i].z;
      std::vector<int> vec = {x, y, z};
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
          if (i != j) {
            x = vec[i], y = vec[j], z = vec[3 - i - j];
            ans = std::max(ans, dfs(x, y, z));
          }
        }
      }
    }
    printf("Case %d: maximum height = %d\n", ++kase, ans);
  }
  return 0;
}
