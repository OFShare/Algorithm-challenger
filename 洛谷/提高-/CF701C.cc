/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-24 18:28:04 PM
 * File Name     : CF701C.cc
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
int n;
char A[N];

std::set<char> st;
std::map<char, int> mp;

int main() {
  scanf("%d %s", &n, A + 1);
  for (int i = 1; i <= n; ++i) {
    st.insert(A[i]);
  }
  int len = st.size(), L = 1, R = 0, ans = n;

  for (int i = 1; i <= n; ++i) {
    ++mp[A[i]];
    ++R;
    while (L <= R && mp.size() == len) {
      ans = std::min(ans, R - L + 1);
      mp[A[L]]--;
      if (mp[A[L]] == 0) mp.erase(A[L]);
      ++L;
    }
  }
  printf("%d\n", ans);
  return 0;
}
