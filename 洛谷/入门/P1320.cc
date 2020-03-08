/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-21 17:12:43 PM
 * File Name     : P1320.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int MOD = 2;
const int N = 2e2 + 5;
char A[N][N];
int cnt = 0;

int main() {
  debug();
  int i = 1;
  while (scanf("%s", A[i] + 1) != EOF) 
    ++i;
  int n = i - 1;

  std::vector<int> vec;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      vec.push_back(A[i][j] - '0');
    }
  }
  
  std::vector<int> ans;
  int k = 0;
  while (k < vec.size()) {
    if (cnt++ % MOD == 0) {
      int zeros = 0;
      while (k < vec.size() && vec[k] == 0)
        ++k, ++zeros;
      ans.push_back(zeros);
    } else {
      int ones = 0;
      while (k < vec.size() && vec[k] == 1) 
        ++k, ++ones;
      ans.push_back(ones);
    }
  }

  printf("%d ", n);
  for (int i = 0; i < ans.size(); ++i) {
    printf("%d ", ans[i]);
  }
  return 0;
}
