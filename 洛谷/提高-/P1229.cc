/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-28 12:51:19 PM
 * File Name     : P1229.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e6;
char strA[N], strB[N];

int main() {
  scanf("%s %s", strA + 1, strB + 1);
  int ans = 1;
  for (int i = 1; i <= std::strlen(strA + 1); ++i) {
    for (int j = 1; j <= std::strlen(strB + 1); ++j) {
      if (i + 1 <= std::strlen(strA + 1) && j - 1 >= 1 && strA[i] == strB[j] && strA[i + 1] == strB[j - 1]) 
        ans *= 2;
    }
  }
  printf("%d\n", ans); 
  return 0;
}
