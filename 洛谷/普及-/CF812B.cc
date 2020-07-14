/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-26 14:32:29 PM
 * File Name     : CF812B.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 15 + 5;
char A[17][105];
int n, m, left[N], right[N], dp[N][2];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", A[i]);
  }
 
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (A[i][j] == '1') ++cnt;
    }
  }
  // 特判
  if (cnt == 0) printf("0\n"), exit(0);

  std::memset(left, -1, sizeof left);
  std::memset(right, -1, sizeof right);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (A[i][j] == '1') {
        left[i] = j;
        break;
      }
    }
    for (int j = m; j >= 1; --j) {
      if (A[i][j] == '1') {
        right[i] = j;
        break;
      }
    }
  }
  // 考虑在第i层左边以及右边的情况
  // i 由第下一层(即i + 1层)转移过来
  for (int i = n; i >= 1; --i) {
    if (i == n) {
      if (right[i] == -1) dp[i][0] = 0;
      else dp[i][0] = right[i] * 2;
      dp[i][1] = m + 1;
    } else {
      if (right[i] == -1) dp[i][0] = dp[i + 1][0] + 1;
      else dp[i][0] = std::min(dp[i + 1][0] + 1 + right[i] * 2, dp[i + 1][1] + 1 + m + 1);

      if (left[i] == -1) dp[i][1] = dp[i + 1][1] + 1;
      else dp[i][1] = std::min(dp[i + 1][1] + 1 + (m + 1 - left[i]) * 2, dp[i + 1][0] + 1 + m + 1);
    }
  }
  // for (int i = n; i >= 1; --i) {
  //   std::cout << "dp[i][0]: " << dp[i][0] << std::endl;
  //   std::cout << "dp[i][1]: " << dp[i][1] << std::endl;
  // }
  // 找到最上面一层的1
  int idx = -1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (A[i][j] == '1') {
        idx = i;
        break;
      }
    }
    if (idx != -1) break;
  }
  if (idx == n) printf("%d\n", right[idx]);
  else printf("%d\n", std::min(dp[idx + 1][0] + 1 + right[idx], dp[idx + 1][1] + 1 + (m + 1 - left[idx])));
  return 0;
}
