//
// Created by OFShare on 2019-09-17
//

#include <bits/stdc++.h>

const int maxn = 1e2 + 5;
int n;
int A[maxn];
// dp[i][j]: 删除i~j, 能得到的操作最大价值
int dp[maxn][maxn];

int dfs(int i, int j) {
    if(dp[i][j] != -1)
        return dp[i][j];
    // 递归边界
    if(i > j)
        return 0;
    int ans = -1e9;
    // 枚举删除分割点
    // 删除i~k
    for(int k = i; k <= j; ++k) {
        // 只去掉一个数，操作价值为这个数的值
        if(k - i + 1 == 1)
            ans = std::max(ans, A[k] + dfs(k + 1, j));
        else
            ans = std::max(ans, std::abs(A[k] - A[i]) * (k - i +1) + dfs(k + 1, j));
    }
    // 删除k~j
    for(int k = j; k >= i; --k) {
        // 只去掉一个数，操作价值为这个数的值
        if(j - k + 1 == 1)
            ans = std::max(ans, A[k] + dfs(i, k - 1));
        else
            ans = std::max(ans, std::abs(A[j] - A[k]) * (j - k +1) + dfs(i, k - 1));
    }
    return dp[i][j] = ans;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &A[i]);
    }
    std::memset(dp, -1, sizeof dp);
    printf("%d\n", dfs(1, n));
    return 0;
}
