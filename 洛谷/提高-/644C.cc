/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-24 22:17:42 PM
 * File Name     : 644C.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int t;
int main() {
  scanf("%d", &t);
  while (t--) {
    int n, x;
    std::vector<int> odd, even;
    std::set<int> st;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &x);
      if (x & 1) odd.push_back(x), st.insert(x);
      else even.push_back(x);
    }
    int len1 = odd.size(), len2 = even.size();
    if (len1 % 2 == 0) printf("YES\n");
    else {
      bool ok = false;
      for (int i = 0; i < len2; ++i) {
        if (st.count(even[i] + 1) || st.count(even[i] - 1)) {
          ok = true;
          break;
        }
      }
      if (ok) printf("YES\n");
      else printf("NO\n");
    }
  }
  return 0;
}
