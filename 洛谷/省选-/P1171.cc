/*
 * Author        : OFShare
 * E-mail        : OFShare@outlook.com
 * Created Time  : 2020-03-21 21:01:02 PM
 * File Name     : P1171.cc
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
const int N = 20;
int n, dis[N][N];
int read() {
  int f=1,x=0;
  char ss=getchar();
  while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
  while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
  return f*x;
}

// 经过Ｓ集合里的点, 走到了u这个点(即当前结点在u)
int dp[1 << N][N];
int dfs(int S, int u) {
  if (dp[S][u] != -1) return dp[S][u];
  // 递归的边界
  if (S == (1 << n) - 1 && u == 0) {
    return dp[S][u] = 0;
  }
  // 状态剪枝
  if ((S & (1 << 0)) == 1 && u != 0) return dp[S][u] = INF;
  int ret = INF;
  for (int v = 0; v < n; ++v) {
    if (u != v && (S & (1 << v)) == 0) {
      ret = std::min(ret, dfs(S | (1 << v), v) + dis[u][v]);
    }
  }
  return dp[S][u] = ret;
}
int main() {
  // scanf("%d", &n);
  n = read();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int x;
      // scanf("%d", &x);
      x = read();
      dis[i][j] = x;
    }
  }
  std::memset(dp, -1, sizeof dp);
  int ret = dfs(0, 0);
  printf("%d\n", ret);
  return 0;
}
