/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-04-26 14:20:52 PM
 * File Name     : CF812A.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int A[5][5];

int main() {
  for (int i = 0; i <= 3; ++i) {
    for (int j = 0; j <= 3; ++j) {
      scanf("%d", &A[i][j]);
    }
  }
  // 枚举判断, 当有行人的时候
  for (int i = 0; i <= 3; ++i) {
    if (A[i][3] == 1) {
      int left_id = (i - 1 + 4) % 4;
      int mid_id = (i + 2) % 4;
      int right_id = (i + 1) % 4;
      if (A[left_id][2] == 1 || A[mid_id][1] == 1 || A[right_id][0] == 1 || A[i][0] == 1 || A[i][1] == 1 || A[i][2] == 1) printf("YES\n"), exit(0);
    }
  }
  printf("NO\n");
  return 0;
}
