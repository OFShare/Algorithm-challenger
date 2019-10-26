/*
 * Created by OFShare on 2019-10-26
 *
 */

#include <bits/stdc++.h>

const int maxn = 1e4 + 5;
int n;
struct node {
    int v, w;
};
std::vector<node> G[maxn];

// 以结点rt为根的子树, 从根到叶子的最长距离, 以及第二最长距离
// dp[rt][0]: 向下最长距离, dp[rt][1]: 向下次长距离(假设向下最长距离的儿子结点为son, 要求不经过它), dp[rt][3]: 向上走的最长距离
int dp[maxn][3];
void dfs_down(int rt, int fa) {
    std::vector<int> tmp;
    for (int i = 0; i < G[rt].size(); ++i) {
        int son = G[rt][i].v, w = G[rt][i].w;
        if (son != fa) {
            dfs_down(son, rt);
            tmp.push_back(dp[son][0] + w);
        }
    }
    std::sort(tmp.begin(), tmp.end());
    int len = tmp.size();
    // 叶子结点, 递归边界
    if (len == 0) {
        dp[rt][0] = 0;
        dp[rt][1] = 0;
    }
    if (len >= 1)
        dp[rt][0] = tmp[len - 1];
    if (len >= 2)
        dp[rt][1] = tmp[len - 2];
}

// 用结点rt的信息去更新dp[son][2]
void dfs_up(int rt, int fa) {
    for (int i = 0; i < G[rt].size(); ++i) {
        int son = G[rt][i].v, w = G[rt][i].w;
        if (son != fa) {
            // 如果结点rt向下的最长距离经过结点son, 则用结点rt向下的次短距离更新dp[son][2]
            if (dp[rt][0] - w == dp[son][0])
                dp[son][2] = std::max(dp[rt][1] + w, dp[rt][2] + w);
            else
                dp[son][2] = std::max(dp[rt][0] + w, dp[rt][2] + w);
            // 递归更新
            dfs_up(son, rt);
        }
    }
}
int main() {
    while (scanf("%d", &n) != EOF) {
        // 初始化
        std::memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; ++i) {
            G[i].clear();
        }
        for (int i = 2; i <= n; ++i) {
            int u = i, v, w;
            scanf("%d %d", &v, &w);
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
        dfs_down(1, 0);
        dfs_up(1, 0);
        for (int i = 1; i <= n; ++i) {
            printf("%d\n", std::max(dp[i][0], dp[i][2]));
        }
    }
    return 0;
}
