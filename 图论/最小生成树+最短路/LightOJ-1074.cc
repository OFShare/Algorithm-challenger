//
// Created by OFShare on 2019-10-04
//

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

const int maxn = 2e2 + 5;
const int INF = 1e9;
int t, n, m, q;
// dis[i][j]: 结点i到结点j的最小值
int dis[maxn][maxn];
// A[i]: 记录结点i的busyness值
int A[maxn];
// 在dfs时, 该结点是否访问过了
bool vis[maxn];
// 邻接表存图
std::vector<int> G[maxn];

void Floyd() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                // 更新
                if (dis[i][k] < INF && dis[k][j] < INF)
                    dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = true;
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        // 标记
        dis[1][v] = -1;
        dfs(v);
    }
}

int main() {
#ifdef OFShare
    freopen("datain.txt", "r", stdin);
    freopen("dataout.txt", "w", stdout);
#endif
    int kase = 0;
    scanf("%d", &t);
    while (t--) {
        // 初始化
        std::memset(dis, 0x3f3f3f, sizeof dis);
        std::memset(vis, 0, sizeof vis);
        for (int i = 0; i <= maxn - 2; ++i) {
            G[i].clear();
        }
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &A[i]);
        }
        scanf("%d", &m);
        for (int i = 1; i <= m; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            G[u].push_back(v);
            dis[u][v] = (A[v] - A[u]) * (A[v] - A[u]) * (A[v] - A[u]);
        }
        Floyd();
        // 判断是否有负环, 有负环的话, 就把能从该结点出发到达的点都标记, 如标记为dis[1][j] = -1;
        for (int i = 1; i <= n; ++i) {
            if (dis[i][i] < 0) {
                dfs(i);
            }
        }
        printf("Case %d:\n", ++kase);
        scanf("%d", &q);
        for (int i = 1; i <= q; ++i) {
            int des;
            scanf("%d", &des);
            if (dis[1][des] < 3 || dis[1][des] > INF)
                printf("?\n");
            else
                printf("%d\n", dis[1][des]);
        }
    }
    return 0;
}
