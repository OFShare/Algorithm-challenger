/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-27 14:20:36 PM
 * File Name     : P2657.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

ll A, B, dp[200][10][2][2];
// 从左往右搜, 现在在第i位, 且第i位为数字x时, 符合题目条件的个数. is_limit判断下一位(即i + 1位)是否有限制, is_leading_zero判断前面是否都是一堆0(即前导零)
ll dfs(int i, int x, bool is_limit, bool is_leading_zero, std::vector<int> &origin) {
  // 递归的边界
  if (i == origin.size() - 1) {
    if (is_leading_zero) {
      assert(x == 0);
      return 0;
    }
    return 1; 
  }
  // 记忆化
  if (dp[i][x][is_limit][is_leading_zero] != -1) return dp[i][x][is_limit][is_leading_zero];

  ll ret = 0;
  int upper = (is_limit? origin[i + 1]: 9);
  for (int k = 0; k <= upper; ++k) {
    if (is_leading_zero) {
      assert(x == 0);
      if (k == 0) ret += dfs(i + 1, k, false, true, origin);
      else {
        if (is_limit == false) ret += dfs(i + 1, k, is_limit, false, origin);
        else ret += dfs(i + 1, k, !(k < upper), false, origin);
      }
      continue;
    }
    if (std::abs(x - k) < 2) continue;
    if (is_limit == false) ret += dfs(i + 1, k, is_limit, false, origin);
    else ret += dfs(i + 1, k, !(k < upper), false, origin);
  }
  return dp[i][x][is_limit][is_leading_zero] = ret;
}
// 分解x
std::vector<int> decompose(ll x) {
  std::vector<int> tmp;
  while (x) {
    tmp.push_back(x % 10);
    x /= 10;
  }
  tmp.push_back(-1);
  std::reverse(tmp.begin(), tmp.end());
  return tmp;
}
// 计算[0, x]区间内符合条件的个数
ll count(ll x) {
  // 特判
  if (x == 0) return 0;

  std::memset(dp, -1, sizeof dp);
  std::vector<int> tmp = decompose(x);
  ll ret = 0;
  for (int k = 0; k <= tmp[1]; ++k) {
    if (k == 0) ret += dfs(1, k, false, true, tmp);
    else if (k == tmp[1]) ret += dfs(1, k, true, false, tmp);
    else ret += dfs(1, k, false, false, tmp);
  }
  return ret;
}
int main() {
  // std::cout << "count: " << count(10) << std::endl;
  scanf("%lld %lld", &A, &B);
  
  printf("%lld\n", count(B) - count(A - 1));
  return 0;
}
