/*
 * Created by OFShare on 2019-10-23
 *
 */

#include <bits/stdc++.h>

const int maxn = 1e5 + 5;
int n;
int v, ans = 0;
std::vector<int> G[maxn];
bool vis[maxn];

/*
 * dfs(rt, len): 表示从源点出发, 走到结点rt时走过的距离为len.
 * 用dfs(rt, len)去更新相邻结点dfs(adjacent, len + 1), 有点类似dp的刷表法
 * 走到边界时并将最远能走到的结点保存到v, 相应的距离保存到ans
 */
void dfs(int rt, int len) {
    bool des_flag = true;
    vis[rt] = true;
    for (int i = 0; i < G[rt].size(); ++i) {
        int adjacent = G[rt][i];
        if (!vis[adjacent]) {
            dfs(adjacent, len + 1);
            des_flag = false;
        }
    }
    if (des_flag) {
        if (len > ans) {
            ans = len;
            v = rt;
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, 0);
    std::memset(vis, 0, sizeof vis);
    dfs(v, 0);
    printf("%d\n", ans);
    return 0;
}
