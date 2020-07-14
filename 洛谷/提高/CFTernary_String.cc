/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-17 17:27:40 PM
 * File Name     : CFTernary_String.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 2e5 + 5;
int t;
char A[N];
std::map<char, int> mp;

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%s", A + 1);
    mp.clear();
    // 滑动窗口
    int i = 1, j = 1, ans = 1e9, len = std::strlen(A + 1);
    for (; j <= std::strlen(A + 1); ++j) {
      if (mp.find(A[j]) != mp.end()) ++mp[A[j]];
      else mp[A[j]] = 1;
      while (mp.size() == 3) {
        ans = std::min(ans, j - i + 1);
        --mp[A[i]];
        if (mp[A[i]] == 0) mp.erase(A[i]);
        ++i;
      }
    }
    if (ans >= 1e9) printf("%d\n", 0);
    else printf("%d\n", ans);
  }
  return 0;
}
