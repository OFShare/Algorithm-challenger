/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-26 20:15:13 PM
 * File Name     : CF787B.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e4 + 5;
int n, m, k, A[N];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &k);
    
    std::set<int> st;
    for (int j = 1; j <= k; ++j) {
      scanf("%d", &A[j]);
      assert(std::abs(A[j]) >= 1);
      if (A[j] > 0) st.insert(A[j]);
    }
    bool cancel = true;
    for (int j = 1; j <= k; ++j) {
      if (A[j] < 0) {
        if (st.count(-1 * A[j]) >= 1) cancel = false;
      }
    }
    if (cancel) printf("YES\n"), exit(0); 
  }
  printf("NO\n");
  return 0;
}
