/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-29 23:14:36 PM
 * File Name     : Aizu-0189.cc
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
const int N = 50 + 5;
int n, dis[N][N];

void floyd(int min_s, int max_s) {
  for (int k = min_s; k <= max_s; ++k) {
    for (int i = min_s; i <= max_s; ++i) {
      for (int j = min_s; j <= max_s; ++j) {
        if (dis[i][k] <= INF && dis[k][j] <= INF)
          dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
}
int main() {
  while (scanf("%d", &n) != EOF && n) {
    int min_s = INF, max_s = 0;
    std::memset(dis, 0x3f3f3f, sizeof dis);

    for (int i = 1; i <= n; ++i) {
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      dis[a][b] = c;
      dis[b][a] = c;
      min_s = std::min(min_s, std::min(a, b));
      max_s = std::max(max_s, std::max(a, b));
    }
    for (int i = min_s; i <= max_s; ++i)
      dis[i][i] = 0;

    floyd(min_s, max_s);
    int min_time = INF, min_id;
    std::vector<int> vec(max_s + 5);
    for (int i = min_s; i <= max_s; ++i) {
      int tmp = 0;
      for (int j = min_s; j <= max_s; ++j) {
        if (i != j) 
          tmp += dis[i][j];
      }
      vec[i] = tmp;
      min_time = std::min(min_time, tmp);
    }
    for (int i = min_s; i <= max_s; ++i) {
      if (vec[i] == min_time) {
        min_id = i;
        break;
      }
    }
    printf("%d %d\n", min_id, min_time);
  }
  return 0;
}
