/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-21 17:05:18 PM
 * File Name     : P1319.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int MOD = 2;
int n, number;
int cnt = 0;

std::vector<int> vec;
int main() {
  debug();
  scanf("%d", &n);
  while (scanf("%d", &number) != EOF) {
    if (cnt++ % MOD == 0) {
      for (int i = 0; i < number; ++i)
        vec.push_back(0);
    } else {
      for (int i = 0; i < number; ++i)
        vec.push_back(1);
    }
  }
  for (int i = 0; i < vec.size(); ++i) {
    if (i && i % n == 0)
      printf("\n");
    printf("%d", vec[i]);
  }
  return 0;
}
