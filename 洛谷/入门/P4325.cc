/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-10 21:12:47 PM
 * File Name     : P4325.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

std::set<int> st;
int main() {
  for (int i = 1; i <= 10; ++i) {
    int x;
    scanf("%d", &x);
    st.insert(x % 42);
  }
  printf("%d\n", (int)st.size());
  return 0;
}
