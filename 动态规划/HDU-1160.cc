/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-06 21:29:13 PM
 * File Name     : HDU-1160.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e3 + 5;
struct node {
  int weight, speed, index;
  bool operator<(const node &rhs) const {
    return speed > rhs.speed;
  }
}A[N];
// dp[i]: 以第i个元素结尾时满足题目条件的最长的子序列
// pre[i]: 记录前驱, dp[i]最优时是由哪里转移过来的
int dp[N], pre[N];

// 递归打印
void print(int i) {
  if (i == pre[i]) {
    printf("%d\n", A[i].index);
    return ;
  }
  print(pre[i]);
  printf("%d\n", A[i].index);
}
int main() {
  debug();
  int weight, speed, index = 0;
  while (scanf("%d %d", &weight, &speed) != EOF) {
    ++index;
    A[index].weight = weight;
    A[index].speed = speed;
    A[index].index = index;
  }
  int ans = 0, ans_index;
  std::sort(A + 1, A + 1 + index);
  for (int i = 1; i <= index; ++i) {
    dp[i] = 1, pre[i] = i;
    for (int j = 1; j < i; ++j) {
      if (A[j].weight < A[i].weight && A[j].speed > A[i].speed) {
        if (dp[j] + 1 > dp[i])
          dp[i] = dp[j] + 1, pre[i] = j;
      }
    }
    if (dp[i] > ans)
      ans = dp[i], ans_index = i;
  }
  printf("%d\n", ans);
  print(ans_index);
  return 0;
}
