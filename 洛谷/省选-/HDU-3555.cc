/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-28 14:42:39 PM
 * File Name     : HDU-3555.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

ll t, n, dp[50][15][5];

ll mypow(ll x) {
  ll ret = 1;
  for (int i = 1; i <= x; ++i) {
    ret *= 10LL;
  }
  return ret;
}
// 计算从下标start开始构成的值
ll to_number(int start, std::vector<int> &origin) {
  ll ret = 0, len = origin.size() - 1;
  for (int i = start; i <= len; ++i) {
    // ret += origin[i] * std::pow(10LL, len - i);
    ret += origin[i] * mypow(len - i);
  }
  return ret + 1;
}

// 前i位, 当前在第i位, 且第i位填的是x, 下一位是否有限制时, 符合题目要求的个数
// 状态i由i+1这些状态转移过来(构成)
ll dfs(int i, int x, bool have_limit, std::vector<int> &origin) {
  // 递归的边界
  if (i == origin.size() - 1) {
    return 0;
  }
  // 记忆化
  if (dp[i][x][have_limit] != -1) return dp[i][x][have_limit];

  ll ret = 0;
  int upper = (have_limit? origin[i + 1]: 9);
  for (int k = 0; k <= upper; ++k) {
    bool limit = false;
    if (have_limit && k == origin[i + 1]) limit = true;
    if (x != 4) ret += dfs(i + 1, k, limit, origin);
    else {
      assert(x == 4);
      if (k == 9) {
        // if (have_limit == false) ret += std::pow(10LL, origin.size() - 1 - (i + 1));
        if (have_limit == false) ret += mypow(origin.size() - 1 - (i + 1));
        else ret += to_number(i + 2, origin);
      }
      else ret += dfs(i + 1, k, limit, origin); 
    }
  }
  return dp[i][x][have_limit] = ret;
}
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
ll count(ll x) {
  if (x == 0) return 0;

  std::memset(dp, -1, sizeof dp);
  std::vector<int> tmp = decompose(x);
  return dfs(0, 0, true, tmp);
}
int main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    printf("%lld\n", count(n));
  }
  return 0;
}
