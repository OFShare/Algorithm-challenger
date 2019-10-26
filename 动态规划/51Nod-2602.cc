/*
 * Created by OFShare on 2019-10-23
 *
 */

#include <bits/stdc++.h>

const int maxn = 1e5 + 5;
int n;
std::vector<int> G[maxn];
bool vis[maxn];

std::vector<int> sons[maxn];

// 递归建树
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

int ans = 0;
// dfs(i): 记录的是以结点rt为根的子树, 根到叶子最深的长度
int dp[maxn];
int dfs(int rt) {
    if (dp[rt] != -1)
        return dp[rt];
    if (sons[rt].size() == 0)
        return 0;
    std::vector<int> son_length;
    int length = 0;
    for (int i = 0; i < sons[rt].size(); ++i) {
        int son = sons[rt][i];
        length = std::max(length, dfs(son));
        son_length.push_back(dfs(son));
    }
    // 以结点rt为根的子树, 经过结点rt的最长路径,就是最长的两个儿子节点
    std::sort(son_length.begin(), son_length.end());
    if (son_length.size() == 1)
        ans = std::max(ans, length + 1);
    else if (son_length.size() >= 2) {
        int pos1 = son_length.size() - 1;
        int pos2 = pos1 - 1;
        ans = std::max(ans, son_length[pos1] + son_length[pos2] + 2);
    }
    return dp[rt] = length + 1;
}

int main() {
    std::memset(dp, -1, sizeof dp);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int root = 1;
    build_tree(root);
    dfs(root);
    printf("%d\n", ans);
    return 0;
}
