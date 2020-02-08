/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-07 11:38:50 AM
 * File Name     : POJ-1015.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int INF = 1e9;
const int N = 2e2 + 5;
int n, m, prosecution[N], defence[N];

// dp[i][j][k]: 前i个人里选j个候选人, 总的辩控差为k的时候, 辩控总和最大值为dp[i][j][k]. 最后对ｋ取绝对值
// 因为k可能为负数, 即dp[i][j][-400] ~ dp[i][j][400], 而数组的下标是不能取负数的(或许可以用map解决, 但偏移量这种技巧更好写)
// 所以我们加上一个偏移量base, 映射到dp[i][j][0] ~ dp[i][j][800]
// 状态转移很清晰, 规模是N*M*K, 是一个三维循环.

// dp[i][j][k]: 前i个人里选j个候选人, 总的辩控差绝对值为k的时候, 辩控总和最大值为dp[i][j][k].
// 这样定义的状态是错误的, 总的辩控差绝对值为k, 在更新dp[i][j][k]的时候, dp[i - 1][j - 1][k - x], k - x一定大于0, 因为是数组下标
// 而k - x 可以是小于0的, 如-1 + 3 = 2, 而不是 1 + 3 = 4．
int dp[N][22][805], base = 400;

// 从后面递归打印路径
std::vector<int> path;
int p_sum, d_sum;
void print(int i, int j, int k) {
  if (i == 0)
    return ;
  // 不选第i位
  if (dp[i][j][k] == dp[i - 1][j][k]) print(i - 1, j, k);
  // 选第i位
  else p_sum += prosecution[i], d_sum += defence[i], path.push_back(i), print(i - 1, j - 1, k - (prosecution[i] - defence[i]));
}
void func(int kase) {
  // 初始化
  std::memset(dp, -0x3f3f3f, sizeof dp);
  dp[0][0][base] = 0;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= std::min(i, m); ++j) {
      for (int k = 0; k <= 802; ++k) {
        // 不选第i位
        if (i - 1 >= 0)
          dp[i][j][k] = dp[i - 1][j][k];
        // 选第i位
        if (i - 1 >= 0 && j - 1 >= 0 && k - (prosecution[i] - defence[i]) >= 0 && k - (prosecution[i] - defence[i]) <= 800)
          dp[i][j][k] = std::max(dp[i][j][k], dp[i - 1][j - 1][k - (prosecution[i] - defence[i])] + prosecution[i] + defence[i]);
      }
    }
  }

  //找出绝对值之差最小的, 但p + d最大的一个    
  int k = 0; 
  while (dp[n][m][base - k] < 0 && dp[n][m][base + k] < 0) k++;
  if (dp[n][m][base - k] > dp[n][m][base + k]) k = base - k; 
  else k = base + k;

  path.clear(), p_sum = 0, d_sum = 0;
  print(n, m, k);
  printf("Jury #%d\n", kase); 
  printf("Best jury has value %d for prosecution and value %d for defence:\n", p_sum, d_sum);
  std::sort(path.begin(), path.end());
  for (int i = 0 ; i < path.size(); i++) {
    printf(" %d", path[i]);
  }
  printf("\n\n");
}
int main() {
  int kase = 0;
  while (scanf("%d %d", &n, &m) && n + m) {
    for (int i = 1; i <= n; ++i) 
      scanf("%d %d", &prosecution[i], &defence[i]);
    func(++kase); 
  }
  return 0;
}
