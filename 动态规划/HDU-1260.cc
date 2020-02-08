/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-07 00:07:59 AM
 * File Name     : HDU-1260.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int MAXN = 2e3 + 5;
int N, K, One[MAXN], Two[MAXN];
// dp[i]: 前i个人, 以第i个人结尾时, 最短需要的时间.
// 从前往后决策
// 你可能会疑惑第i个人为什么只会和他前面的人结合, 而不会和他后面的人结合, 这样不是漏掉了这种情况吗(也可以这样考虑, 我们是从前往后dp的, 
// 在更新第i个人的时候, 是看不到第i + 1的)
// 其实没有哟, 我们往前看, 在状态转移时, 第i - 1个人是和第i个人结合的, 如果我们把第i - 1个人看成第i个人, 那么他
// 其实是和后面的人结合的, 只不过我们在更新到第i - 1个人的时候, 他是和前面的人结合, 而在更新到第i个人时, 才体现出第i - 1个人
// 是考虑了和后面的人结合这种情况的
// 所以我们的dp方程考虑了所有的情况, 是正确的.

// 简单的一句话总结, 在更新dp[i]时, 考虑的是第i个人单独购买, 或者考虑第i - 1个人和后面的结合. 这样第1个人一直到第倒数第二个人, 每个人
// 都考虑了和前面的人结合,以及和后面的人结合的情况.
int dp[MAXN];
int main() {
  scanf("%d", &N);
  while (N--) {
    scanf("%d", &K);
    for (int i = 1; i <= K; ++i) 
      scanf("%d", &One[i]);
    for (int i = 2; i <= K; ++i)
      scanf("%d", &Two[i]);

    dp[0] = 0;
    for (int i = 1; i <= K; ++i) {
      dp[i] = dp[i - 1] + One[i];
      if (i - 1 >= 0 && i - 2 >= 0)
        dp[i] = std::min(dp[i - 1] + One[i], dp[i - 2] + Two[i]);
    }
    // 时间的转换
    int h = 8 + dp[K] / 3600;
    int m = (dp[K] % 3600) / 60;
    int s = (dp[K] % 3600) % 60;
    printf("%02d:%02d:%02d ", h, m, s);
    if (h >= 12) printf("pm\n");
    else printf("am\n");
  }
  return 0;
}
