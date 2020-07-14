/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-15 14:44:16 PM
 * File Name     : U83355.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int INF = 1e9;
const int N = 5e5 + 5;;
char A[N];
int k, ans[N], T;

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%s %d", A + 1, &k);
    int keep = std::strlen(A + 1) - k;
    if (keep == 0) {
      printf("0\n");
      continue;
    }
    // 枚举每一位最小的可能的数
    int start = 1;
    for (int i = 1; i <= keep; ++i) {
      char min_mx = '9' + 5; 
      for (int j = start; j <= std::strlen(A + 1); ++j) {
        if (A[j] < min_mx && std::strlen(A + 1) - j + i >= keep) {
          min_mx = A[j];
          start = j + 1;
          // std::cout << "char: " << min_mx << std::endl;
        }
      }
      ans[i] = min_mx - '0';
    }
    // 去掉前导0, 但至少有一个0
    if (keep == 1 && ans[1] == 0) {
      printf("0\n");
      continue;
    }
    start = 1;
    while (ans[start] == 0) ++start;
    for (int i = start; i <= keep; ++i) {
      printf("%d", ans[i]);
    }
    printf("\n");
  }
  return 0;
}
