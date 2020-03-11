/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-10 17:03:17 PM
 * File Name     : P3741.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int N = 1e2 + 5;
int n;
char A[N];
bool vis[N];

int main() {
  scanf("%d %s", &n, A + 1);
  int ans = 0;
  for (int i = 1; i <= strlen(A + 1); ++i) {
    if (i == 1) continue;
    else {
      if (A[i] == 'K' && A[i - 1] == 'V' && vis[i] == false && vis[i - 1] == false)
        ++ans, vis[i] = true, vis[i - 1] = true;
    }
  }
  for (int i = 1; i <= strlen(A + 1); ++i) {
    if (i == 1) continue;
    else {
      if (A[i] == A[i - 1] && vis[i] == false && vis[i - 1] == false) {
        ++ans;
        break;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
