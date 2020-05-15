/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-05-03 13:13:18 PM
 * File Name     : HDU-5887.cc
 */

#include <bits/stdc++.h>

#define ll long long
void debug() {
#ifdef Acui
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
}

// 快读
inline int read() {
  int x = 0,f = 1; char ch = getchar();
  while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
  while (isdigit(ch)) {x = x * 10 + ch - 48; ch = getchar();}
  return x * f;
}
// 快输
void write (int x) {
  if (x<0) {putchar('-'); x = -x;}
  int y = 10, len = 1;
  while (y <= x) {y *= 10; len++;}
  while (len--) {y /= 10; putchar(x / y + 48); x %= y;}
}

const int N = 1e2 + 5;
int n, T, tim[N], scores[N];

struct Node {
  int tim, sco;
}A[N];

int main() {
  while (scanf("%d %d", &n, &T) != EOF) {
    for (int i = 1; i <= n; ++i) {
      // scanf("%d %d", &tim[i], &scores[i]);
      tim[i] = read(), scores[i] = read();
    }
    if (n == 1) {
      if (tim[1] <= T) printf("%d\n", scores[1]), exit(0);
      else printf("0\n"), exit(0);
    }
    if (n == 2) {
      int tmp_score = 0;
      if (tim[1] <= T) tmp_score = std::max(tmp_score, scores[1]);
      if (tim[2] <= T) tmp_score = std::max(tmp_score, scores[2]);
      if (tim[1] + tim[2] <= T) tmp_score = std::max(tmp_score, scores[1] + scores[2]);
      printf("%d\n", tmp_score), exit(0);
    }
    // 枚举3个值, 然后按单位时间的价值从大到小贪心
    for (int i = 1; i <= n; ++i) {
      A[i].tim = tim[i];
      A[i].sco = scores[i];
    }
    std::sort(A + 1, A + 1 + n, [](const Node &lhs, const Node &rhs) {
        return lhs.sco * 1.0 / lhs.tim > rhs.sco * 1.0 / rhs.tim; 
    });
    int ans = 0;
    // for (int i = 1; i <= n; ++i) {
    //   for (int j = 1; j <= n; ++j) {
    //     if (i == j) continue;
    //     for (int k = 1; k <= n; ++k) {
    //       if (i == j || i == k || j == k) continue;
    //       int tmp_score = 0;
    //       if (i != j && i != k && j != k) {
    //         if (A[i].tim <= T) tmp_score += A[i].sco, T -= A[i].tim;
    //         if (A[j].tim <= T) tmp_score += A[j].sco, T -= A[j].tim;
    //         if (A[k].tim <= T) tmp_score += A[k].sco, T -= A[k].tim;
    //         for (int it = 1; it <= n; ++it) {
    //           if (it != i && it != j && it != k) {
    //             if (A[it].tim <= T) tmp_score += A[it].sco, T -= A[it].tim;
    //           }
    //         }
    //         ans = std::max(ans, tmp_score);
    //       }
    //     }
    //   }
    // }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (i == j) continue;
        int tmp_score = 0;
        if (A[i].tim <= T) tmp_score += A[i].sco, T -= A[i].tim;
        if (A[j].tim <= T) tmp_score += A[j].sco, T -= A[j].tim;
        for (int it = 1; it <= n; ++it) {
          if (it != i && it != j) {
            if (A[it].tim <= T) tmp_score += A[it].sco, T -= A[it].tim;
          }
          ans = std::max(ans, tmp_score);
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
