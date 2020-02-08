/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-08 12:12:11 PM
 * File Name     : POJ-1661.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int MAXN = 1e3 + 5;
int t, N, X, Y, MAX;
struct node {
  int L, R, H;
  bool operator<(const node &rhs) const {
    return H < rhs.H;
  }
}A[MAXN];

// dp[i][0]: 按高度从小到大排序后, 第i块平台从左端点出发到地面的最短时间
// dp[i][1]: 按高度从小到大排序后, 第i块平台从右端点出发到地面的最短时间
int dp[MAXN][2];

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d %d", &N, &X, &Y, &MAX);
    for (int i = 1; i <= N; ++i)
      scanf("%d %d %d", &A[i].L, &A[i].R, &A[i].H);

    // 把下落的点也看做一个平台
    A[N + 1].L = X, A[N + 1].R = X, A[N + 1].H = Y;
    std::memset(dp, 0x3f3f3f, sizeof dp);
    std::sort(A + 1, A + 1 + N + 1);
    for (int i = 1; i <= N + 1; ++i) {
      // 判断第i块平台下面是否有平台
      bool has_left = false, has_right = false;
      // j的遍历逆序的, 因为要先落到最接近i的下面的一块平台
      for (int j = i - 1; j >= 1; --j) {
        if (has_left == false && A[j].L <= A[i].L && A[i].L <= A[j].R && A[i].H - A[j].H <= MAX) {
          // dp[i][0]可以由dp[j][0], dp[j][1]转移过来
          dp[i][0] = std::min(dp[i][0], dp[j][0] + A[i].L - A[j].L + A[i].H - A[j].H);
          dp[i][0] = std::min(dp[i][0], dp[j][1] + A[j].R - A[i].L + A[i].H - A[j].H);
          has_left = true;
        }
        if (has_right == false && A[j].L <= A[i].R && A[i].R <= A[j].R && A[i].H - A[j].H <= MAX) {
          // dp[i][1]可以由dp[j][0], dp[j][1]转移过来
          dp[i][1] = std::min(dp[i][1], dp[j][0] + A[i].R - A[j].L + A[i].H - A[j].H);
          dp[i][1] = std::min(dp[i][1], dp[j][1] + A[j].R - A[i].R + A[i].H - A[j].H);
          has_right = true;
        }
      }
      // 第i块平台下面左边没有平台时
      if (!has_left) {
        if (A[i].H <= MAX)
          dp[i][0] = A[i].H;
      }
      // 第i块平台下面右边没有平台时
      if (!has_right) {
        if (A[i].H <= MAX)
          dp[i][1] = A[i].H;
      }
    }
    printf("%d\n", std::min(dp[N + 1][0], dp[N + 1][1]));
  }
  return 0;
}
