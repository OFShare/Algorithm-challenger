/*
 * Created by OFShare on 2019-10-20
 *
 */

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

const int maxn = 6e3 + 5;
int n;
int A[maxn];

// sons[i]: 记录结点i的儿子结点有那些
std::vector<int> sons[maxn];
// fa[i]: 记录结点i的父亲结点
int fa[maxn];
int dp[maxn][2];

// 以结点rt为根的子树, 选择/不选rt时, 能获得的最大独立点集(即题目所说的guests' conviviality ratings)
int dfs(int rt, bool is_choose) {
    // 记忆化
    if (dp[rt][is_choose] != -1)
        return dp[rt][is_choose];
    // 递归的边界
    if (sons[rt].size() == 0) {
        if (is_choose)
            return A[rt];
        else
            return 0;
    }
    // 选择结点rt, 那么它的儿子结点都不能选
    if (is_choose) {
        int sum = A[rt];
        for (int i = 0; i < sons[rt].size(); ++i) {
            int son = sons[rt][i];
            sum += dfs(son, 0);
        }
        return dp[rt][is_choose] = sum;
    }
    // 不选结点rt, 那么它的儿子结点都可以选或者不选
    else {
        int sum = 0;
        for (int i = 0; i < sons[rt].size(); ++i) {
            int son = sons[rt][i];
            sum += std::max(dfs(son, 0), dfs(son, 1));
        }
        return dp[rt][is_choose] = sum;
    }
}

int main() {
    while (scanf("%d", &n) != EOF && n) {
        // 初始化
        for (int i = 1; i <= n; ++i) {
            sons[i].clear();
            fa[i] = -1;
            dp[i][0] = -1;
            dp[i][1] = -1;
        }

        for (int i = 1; i <= n; ++i) {
            scanf("%d", &A[i]);
        }
        for (int i = 1; i <= n - 1; ++i) {
            int son_, fa_;
            scanf("%d %d", &son_, &fa_);
            sons[fa_].push_back(son_);
            fa[son_] = fa_;
        }
        // 找到树的根
        int root;
        for (int i = 1; i <= n; ++i) {
            if (fa[i] == -1) {
                root = i;
                break;
            }
        }
        printf("%d\n", std::max(dfs(root, 0), dfs(root, 1)));
    }
    return 0;
}
