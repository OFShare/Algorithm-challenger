/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-28 12:28:57 PM
 * File Name     : P1154.c
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 5e3 + 5;
int n, A[N];

bool valid(int k) {
  std::set<int> st;
  for (int i = 1; i <= n; ++i) {
    if (st.count(A[i] % k) != 0) return false;
    st.insert(A[i] % k);
  }
  return st.size() == n;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &A[i]);
  }
  // 枚举可能的ｋ, 至少有n个
  for (int k = n; ; ++k) {
    if (valid(k)) {
      printf("%d\n", k);
      break;
    }
  }
  return 0;
}
