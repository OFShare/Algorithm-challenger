/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-14 00:16:07 AM
 * File Name     : POJ-1456.cc
 */

#include <cstdio>
#include <cstring>
#include <algorithm>

void debug() {
#ifdef Acui
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
}

const int N = 1e4 + 5;
struct node {
  int profit, deadline;
  bool operator<(const node &rhs) const {
    return profit > rhs.profit;
  }
}A[N];
int n;
bool vis[N];

int main() {
  while (scanf("%d", &n) != EOF) {
    std::memset(vis, 0, sizeof vis);
    for (int i = 1; i <= n; ++i) 
      scanf("%d %d", &A[i].profit, &A[i].deadline);

    int ans = 0;
    // 优先考虑利润大的, 从它的截止日益往前面推
    std::sort(A + 1, A + 1 + n);
    for (int i = 1; i <= n; ++i) {
      for (int j = A[i].deadline; j >= 1; --j) {
        if (vis[j] == false) {
          ans += A[i].profit, vis[j] = true;
          break;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
