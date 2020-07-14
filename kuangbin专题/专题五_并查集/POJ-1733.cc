/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-12 00:26:46 AM
 * File Name     : POJ-1733.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e9 + 7;
int L, Q;
int fa[N];
int main() {
  scanf("%d %d", &L, &Q);
  for (int i = 1; i <= Q; ++i) {
    int x, y;
    char str[7];
    scanf("%d %d %s", &x, &y, str + 1);
    y += 1;
    
    bool e;
    if (str[1] == 'e') e = true;
    else e = false;
    int rt1 = find_union(x);
    int rt2 = find_union(y);
    if (rt1 != rt2) {
      fa[rt1] = rt2;
      b[rt1] = (-b[x] + e + b[y] + MOD) % MOD;
    } else {
      if (b[x] != (d + b[y] + MOD) % MOD) {
        printf("%d\n", i - 1);
        return 0;
      }
    }
  }
  printf("%d\n", Q);
  return 0;
}
