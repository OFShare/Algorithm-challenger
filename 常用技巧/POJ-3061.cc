/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-08 16:30:11 PM
 * File Name     : POJ-3061.cc
 */

//#include <bits/stdc++.h>
#include <cstdio>
#include <string>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int INF = 1e9;
const int MAXN = 1e5 + 5;
int t, N, S, A[MAXN];

int main() {
  scanf("%d", &t);
  while (t--) {
    int ans = INF;
    scanf("%d %d", &N, &S);
    for (int i = 1; i <= N; ++i) 
      scanf("%d", &A[i]);
    int L = 1, R = 1, sum = A[1];
    while (L <= R && L <= N && R <= N) {
      if (sum >= S) ans = std::min(ans, R - L + 1), sum -= A[L], ++L;
      else ++R, sum += A[R];
    }
    if (ans >= INF) printf("0\n");
    else printf("%d\n", ans);
  }
  return 0;
}
