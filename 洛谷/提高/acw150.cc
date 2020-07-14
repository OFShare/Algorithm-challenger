/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-08 11:28:53 AM
 * File Name     : acw150.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e5 + 5;
char A[N];
int dp[N], ans;

// dp[i]表示以第i个元素结尾的连续合法字符串的最长的长度
// 像这种'连续的', 转移大多和上一个有关
int main() {
  scanf("%s", A + 1);
  for (int i = 1; i <= std::strlen(A + 1); ++i) {
    dp[i] = 0;
    if (A[i] == '(' || A[i] == '[' || A[i] == '{') dp[i] = 0;
    else {
      int k = i - 1 - dp[i - 1];
      if ((A[i] == ')' && A[k] == '(') || (A[i] == ']' && A[k] == '[') || (A[i] == '}' && A[k] == '{'))
        dp[i] = dp[k - 1] + dp[i - 1] + 2;
    }
    ans = std::max(ans, dp[i]);
  }
  printf("%d\n", ans);
  return 0;
}
