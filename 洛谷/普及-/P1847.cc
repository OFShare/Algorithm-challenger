/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-08 14:09:54 PM
 * File Name     : P1847.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int MAXN = 2e3 + 5;
ll M, N;
struct node {
  ll x1, y1;
  ll x2, y2;
}A[MAXN];

int main() {
  scanf("%lld %lld", &M, &N);
  for (int i = 1; i <= M; ++i) {
    scanf("%lld %lld %lld %lld", &A[i].x1, &A[i].y1, &A[i].x2, &A[i].y2);
  }
  for (int i = 1; i <= N; ++i) {
    ll x, y;
    scanf("%lld %lld", &x, &y);
    // 扫一遍
    ll cnt = 0, last_cnt;
    for (int j = 1; j <= M; ++j) {
      if (x >= A[j].x1 && x <= A[j].x2 && y >= A[j].y1 && y <= A[j].y2)
        ++cnt, last_cnt = j;
    }
    if (cnt == 0) printf("NO\n");
    else printf("YES %lld %lld\n", cnt, last_cnt);
  }
  return 0;
}
