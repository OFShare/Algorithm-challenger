/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-02-24 16:56:48 PM
 * File Name     : P2670.cc
 */

#include <bits/stdc++.h>

void debug() {
  #ifdef Acui
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
}

const int dx[] = {-1, -1, 0, 1, 1, 1, 0 -1};
const int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
const int N = 1e2 + 5;
char A[N][N];
int ans[N][N];
int n, m;

int func(int x, int y) {
  int ret = 0;
  for (int i = 0; i < 8; ++i) {
    int newx = x + dx[i], newy = y + dy[i];
    if (newx >= 1 && newx <= n && newy >= 1 && newy <= m && A[newx][newy] == '*')
      ++ret;
  }
  return ret;
}
int main() {
  std::cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j)
      std::cin >> A[i][j];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (A[i][j] == '*')
        ans[i][j] = -1; 
      else 
        ans[i][j] = func(i, j);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j)
      if (ans[i][j] == -1) std::cout <<'*';
      else std::cout << ans[i][j];
      std::cout << std::endl;
  }
  return 0;
}
