/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-04 11:57:47 AM
 * File Name     : CF485C.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

ll n, ans_one, ans, l, r;

void work() {
  std::bitset<64> upper(r);
  // 枚举公共前缀, 后面变为0, 接着后面的都变为1
  for (int i = 0; i <= 63; ++i) {
    if (i - 1 == 0) {
      ans_one = upper.count();
      ans = upper.to_ullong();
      continue;
    }
    if (i - 1 >= 0 && upper[i - 1] == 1) {
      std::bitset<64> tmp = upper;
      tmp[i - 1] = 0;
      for (int j = i - 2; j >= 0; --j) tmp[j] = 1;
      // 尝试更新答案
      if (tmp.to_ullong() >= l) {
        if (tmp.count() > ans_one) ans_one = tmp.count(), ans = tmp.to_ullong();
        else if (tmp.count() == ans_one && tmp.to_ullong() < ans) ans_one = tmp.count(), ans = tmp.to_ullong();
      }
    }
  }
}
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld %lld", &l, &r);
    work();
    printf("%lld\n", ans);
  }
  return 0;
}
