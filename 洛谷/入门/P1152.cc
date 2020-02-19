/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-19 15:35:07 PM
 * File Name     : P1152.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e3 + 5;
int n, A[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &A[i]);
  std::set<int> st;
  for (int i = 1; i <= n - 1; ++i)
    st.insert(std::abs(A[i + 1] - A[i]));
  if (st.size() == n - 1)
    printf("Jolly\n");
  else 
    printf("Not jolly\n");
  return 0;
}
