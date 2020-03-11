/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-10 19:58:27 PM
 * File Name     : P2689.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int x11, y11, x22, y22, T;
int main() {
  scanf("%d %d %d %d %d", &x11, &y11, &x22, &y22, &T);
  int step = 0;
  for (int i = 1; i <= T; ++i) {
    if (x11 == x22 && y11 == y22) {
      printf("%d\n", step);
      return 0;
    }
    char tmp[5];
    scanf("%s", tmp + 1);
    // 风吹向East
    if (tmp[1] == 'E' && y22 > y11) ++step, ++y11;
    else if (tmp[1] == 'W' && y11 > y22) ++step, --y11;
    else if (tmp[1] == 'N' && x22 > x11) ++step, ++x11;
    else if (tmp[1] == 'S' && x11 > x22) ++step, --x11;
  }
  printf("-1\n");
  return 0;
}
