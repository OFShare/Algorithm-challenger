/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-06-10 22:31:59 PM
 * File Name     : CF910C.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e3 + 5;
int n;
char s[N][N];
int A[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s[i] + 1);
  }
  // 枚举
  for (int i = 0; i < 10; ++i) {
    A[i] = i;
  }
  int ans = 1e9;
  do {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
      int number = 0, len = std::strlen(s[i] + 1);
      bool zero = true;
      for (int j = 1; j <= len; ++j) {
        if (zero && A[s[i][j] - 'a'] == 0) {
          number = 1e9; 
          break;
        }
        zero = false;
        number = number * 10 + A[s[i][j] - 'a'];
      }
      sum += number; 
      if (number >= 1e9) break;
    }
    ans = std::min(ans, sum);
  } while (std::next_permutation(A + 0, A + 0 + 10));
  printf("%d\n", ans);
  return 0;
}
