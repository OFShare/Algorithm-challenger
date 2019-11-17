/*
 * Created by OFShare on 2019-10-24
 *
 */

#include <bits/stdc++.h>

const int INF = 1e9;
const int maxn = 1e4 + 5;
std::vector<int> G[maxn];
bool vis[maxn];

int n;
std::vector<int> sons[maxn];

void build_tree(int rt) {
    vis[rt] = true;
    for (int i = 0; i < G[rt].size(); ++i) {
        int son = G[rt][i];
        if (!vis[son]) {
            sons[rt].push_back(son);
            build_tree(son);
        }
    }
}

/*
 * dfs(u, fa): 记录dp[u][0], dp[u][1], dp[u][2]三者的状态
 * dp[u][0]: 以结点u为根的子树, 当u为服务器时, 最少的服务器数量. 此时u的儿子结点和父亲结点可以是服务器也可以是client
 * dp[u][1]: 以结点u为根的子树, 当u不是服务器时, 它的父亲(如果有)是服务器时, 最少的服务器数量. 此时u的儿子结点都不能是服务器
 * dp[u][2]: 以结点u为根的子树, 当u不是服务器时, 它的父亲(如果有)也不是服务器时, 最少的服务器数量. 此时u的儿子结点有且只有一个是服务器.
 */
int dp[maxn][3];
void dfs(int rt, int fa) {
    dp[rt][0] = 1;
    dp[rt][1] = 0;
    dp[rt][2] = INF;
    int sum = 0;
    for (int i = 0; i < sons[rt].size(); ++i) {
        int son = sons[rt][i];
        if (son != fa) {
            dfs(son, rt);
            sum += dp[son][2];
        }
    }
    for (int i = 0; i < sons[rt].size(); ++i) {
        int son = sons[rt][i];
        if (son != fa) {
            dp[rt][0] += std::min(dp[son][0], dp[son][1]);
            dp[rt][1] += dp[son][2];
            // 枚举其中有且只有一个是服务器
            dp[rt][2] = std::min(dp[rt][2], sum - dp[son][2] + dp[son][0]);
        }
    }
}

int main() {
#ifdef Acui
    freopen("datain.txt", "r", stdin);
    freopen("dataout.txt", "w", stdout);
#endif
    while (scanf("%d", &n) && n != -1) {
        // 初始化
        for (int i = 1; i <= n; ++i) {
            G[i].clear();
            sons[i].clear();
            vis[i] = false;
        }
        for (int i = 1; i < n; ++i) {
            int a, b;
            scanf("%d %d", &a, &b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        int root = 1;
        build_tree(root);
        dfs(root, 0);
        int ans = std::min(dp[root][0], dp[root][2]);
        printf("%d\n", ans);
        int tmp;
        scanf("%d", &tmp);
        if (tmp == -1)
            break;
    }
    return 0;
}
