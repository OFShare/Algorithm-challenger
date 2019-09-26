//
// Created by OFShare on 2019-09-26
//

#include <bits/stdc++.h>

const int maxn = 1e2 + 5;
// dp[k][i][j]: 在只使用1, 2, 3, ..., k结点的情况下, 从结点i走到结点j最短的路径.
int dp[maxn][maxn][maxn];
int A[maxn][maxn], dis[maxn][maxn];

int dfs(int k, int i, int j) {
    if (dp[k][i][j] != -1)
        return dp[k][i][j];
    // 递归边界
    if (k == 0)
        return dp[k][i][j] = dis[i][j];
    // 不经过k这个点
    int ans = dfs(k - 1, i, j);
    // 经过k这个点, 先走到k, 在从k走到j
    ans = std::min(ans, dfs(k - 1, i, k) + dfs(k - 1, k, j));
    return dp[k][i][j] = ans;
}

int main() {
    int n, m, d, start_, end_;
    scanf("%d %d", &n, &m);
    std::memset(dis, 0x3f3f3f, sizeof dis);
    std::memset(dp, -1, sizeof dp);
    for (int i = 1; i <= n; ++i) {
        dis[i][i] = 0;
    }
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        A[u][v] = w;
        A[v][u] = w;
        dis[u][v] = 0;
        dis[v][u] = 0;
    }
    scanf("%d", &d);
    for (int i = 1; i <= d; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        dis[u][v] = A[u][v];
        dis[v][u] = A[v][u];
    }
    scanf("%d %d", &start_, &end_);
    printf("%d\n", dfs(n, start_, end_));
    return 0;
}
