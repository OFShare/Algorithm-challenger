/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-04 22:51:30 PM
 * File Name     : CF483C.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e5 + 5;
int n, k, A[N];

int main() {
  scanf("%d %d", &n, &k);
  std::set<int> st;

  int tmp = n - k - 1;
  for (int i = 1; i <= n; ++i) {
    if (k == 0) {
      A[i] = tmp--;
      continue;
    }
    if (i == 1) st.insert(n), A[i] = n;
    else {
      int a = A[i - 1] + k;
      int b = A[i - 1] - k;
      if (a >= 1 && a <= n && st.count(a) == 0) st.insert(a), A[i] = a;
      else st.insert(b), A[i] = b;
      --k;
    }
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d ", A[i]);
  }
  return 0;
}
