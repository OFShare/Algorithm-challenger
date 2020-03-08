/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-21 16:32:33 PM
 * File Name     : P1317.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

int n, ans = 0;
int main() {
  scanf("%d", &n);
  // 扫一遍, 扫的过程维护一些变量即可, pre_down, pre_height
  bool pre_down = false;
  int pre_height = -1;
  for (int i = 1; i <= n; ++i) {
    int height;
    scanf("%d", &height);
    if (height > pre_height) {
      if (pre_down == true)
        ++ans;
      pre_down = false;
    } else
      pre_down = true;
    pre_height = height;
  } 
  printf("%d\n", ans);
  return 0;
}
