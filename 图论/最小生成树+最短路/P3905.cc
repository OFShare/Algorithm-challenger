//
// Created by OFShare on 2019-09-26
//

#include <bits/stdc++.h>

const int maxn = 5e2 + 5;
int n, m, d, start_, end_;
// dis[i][j]: 节点i到节点j的最短路
int dis[maxn][maxn];
// A[i][j]: 记录节点i到节点j边的权值
int A[maxn][maxn];

int main() {
    scanf("%d %d", &n, &m);
    // 初始化
    std::memset(dis, 0x3f3f3f, sizeof dis);
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
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    scanf("%d %d", &start_, &end_);
    printf("%d\n", dis[start_][end_]);
    return 0;
}
