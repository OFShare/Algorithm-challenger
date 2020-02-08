/*
 * Created by OFShare on 2019-12-14
 *
 */

#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>

const int maxn = 1e3 + 5;
int n, k;
std::string dp[maxn][maxn];

// 模拟高精度加法
// 123 + 23 = 353, 左边起第一位是个位, 第二位是十位, 依次类推
std::string operator+(std::string &lhs, std::string &rhs) {
  int len_lhs = lhs.size();
  int len_rhs = rhs.size();
  std::string ans;
  // res保存的是进位
  int res = 0;
  for (int i = 0; i <= std::max(len_lhs, len_rhs); ++i) {
    if (i >= std::max(len_lhs, len_rhs)) {
      if (res >= 1)
        ans += res + '0';
      continue;
    }
    if (i >= len_lhs) {
      int a = 0;
      int b = rhs[i] - '0';
      ans += (a + b + res) % 10 + '0';
      res = (a + b + res) / 10;
      continue;
    }
    if (i >= len_rhs) {
      int a = lhs[i] - '0';
      int b = 0;
      ans += (a + b + res) % 10 + '0';
      res = (a + b + res) / 10;
      continue;

    }
    int a = lhs[i] - '0';
    int b = rhs[i] - '0';
    ans += (a + b + res) % 10 + '0';
    res = (a + b + res) / 10;
  }
  return ans;
}

int main() {
  //std::string a("9999");
  //std::string b("22");
  //std::string tmp = a + b;
  //printf("%s\n", tmp.c_str());
  //return 0;

  scanf("%d %d", &n, &k);
  // 初始化
  for (int i = 0; i < maxn; ++i)
    std::fill(dp[i], dp[i] + maxn, "0");
  dp[0][0] = "1";

  for (int i = 1; i <= k; ++i) {
    for (int j = 0; j <= n; ++j) {
      // 不选
      dp[i][j] = dp[i - 1][j];
      // 加选一件
      if (j - i >= 0)
        dp[i][j] = dp[i][j] + dp[i][j - i];
    }
  }
  for (int i = dp[k][n].size() - 1; i >= 0; --i) {
    std::string str = dp[k][n];
    int a = str[i] - '0';
    printf("%d", a);
  }
  return 0;
}
