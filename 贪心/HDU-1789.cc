/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-14 12:12:27 PM
 * File Name     : HDU-1789.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e4 + 5;
int t, n;
struct node {
  int reduced_score, deadline;
  bool operator<(const node &rhs) const {
    return reduced_score > rhs.reduced_score;
  }
}A[N];
bool vis[N];

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) 
      scanf("%d", &A[i].deadline);
    for (int i = 1; i <= n; ++i) 
      scanf("%d", &A[i].reduced_score);
  
    std::memset(vis, 0, sizeof vis);
    int ans = 0;
    // 优先处理reduced_score大的, 从它的截止日期往前面推
    std::sort(A + 1, A + 1 + n);
    for (int i = 1; i <= n; ++i) {
      bool settled = false;
      for (int j = A[i].deadline; j >= 1; --j) {
        if (vis[j] == false) {
          vis[j] = true;
          settled = true;
          break;
        }
      }
      // 没有多余的可以完成作业的日期
      if (settled == false)
        ans += A[i].reduced_score;
    }
    printf("%d\n", ans);
  }
  return 0;
}
