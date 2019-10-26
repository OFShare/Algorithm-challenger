/*
 * Created by OFShare on 2019-10-26
 *
 */

#include <bits/stdc++.h>

const int maxn = 1e4 + 5;
int n;
// 树的直径的两个端点
int end_point_u, end_point_v;
struct node {
    int v, w;
};
std::vector<node> G[maxn];
bool vis[maxn];

// 从源点走到结点rt需要的最长距离
int length = 0;
int middle_point;
int dis[maxn];
void dfs(int rt, int len) {
    vis[rt] = true;
    dis[rt] = std::max(dis[rt], len);

    bool update = false;
    for (int i = 0; i < G[rt].size(); ++i) {
        int v = G[rt][i].v, w = G[rt][i].w;
        if (!vis[v]) {
            update = true;
            dfs(v, len + w);
        }
    }
    // 叶子结点
    if (!update) {
        if (len > length) {
            length = len;
            middle_point = rt;
        }
        return ;
    }
}

int main() {
    while (scanf("%d", &n) != EOF) {
        // 初始化
        length = 0;
        for (int i = 1; i <= n; ++i) {
            G[i].clear();
            vis[i] = false;
            dis[i] = 0;
        }
        for (int i = 2;i <= n; ++i) {
            int u = i, v, w;
            scanf("%d %d", &v, &w);
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
        dfs(1, 0);
        end_point_u = middle_point;

        length = 0;
        std::memset(vis, 0, sizeof vis);
        dfs(end_point_u, 0);
        end_point_v = middle_point;
        // 找到了树的直径的两个端点, end_point_u, end_point_v
        std::memset(dis, 0, sizeof dis);
        std::memset(vis, 0, sizeof vis);
        dfs(end_point_u, 0);

        std::memset(vis, 0, sizeof vis);
        dfs(end_point_v, 0);
        for (int i = 1; i <= n; ++i) {
            printf("%d\n", dis[i]);
        }
    }
    return 0;
}
