/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-14 16:09:12 PM
 * File Name     : P1044.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 18 + 5;
int n;
// 操作数序列有cnt1个元素, 中转站有cnt2个元素, 这种状态下能获得的操作数
// 我们并不关心具体的元素值, 只需要元素的个数即可
int dp[N][N];
int dfs(int cnt1, int cnt2) {
  if (dp[cnt1][cnt2] != -1) return dp[cnt1][cnt2];
  if (cnt1 == 0) return 1;
  int ret = 0;
  if (cnt1 >= 1) {
    ret += dfs(cnt1 - 1, cnt2 + 1);
  }
  if (cnt2 >= 1) {
    ret += dfs(cnt1, cnt2 - 1);
  }
  return dp[cnt1][cnt2] = ret;
}
int main() {
  scanf("%d", &n);
  std::memset(dp, -1, sizeof dp);
  int ret = dfs(n, 0);
  printf("%d\n", ret);
  return 0;
}
