/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-19 17:52:09 PM
 * File Name     : CF909A.cc
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
char s1[N], s2[N];

int main() {
  scanf("%s %s", s1 + 1, s2 + 1);
  int len1 = std::strlen(s1 + 1);
  int i = 1;
  std::string ans;
  ans.push_back(s1[i++]);
  while (i <= len1) {
    if (s1[i] < s2[1]) ans.push_back(s1[i++]);
    else break;
  }
  ans.push_back(s2[1]);
  printf("%s", ans.c_str());
  return 0;
}
