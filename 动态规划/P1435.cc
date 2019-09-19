//
// Created by OFShare on 2019-09-17
//

#include <bits/stdc++.h>

const int maxn = 1e3 + 5;
char A[maxn];
// dp[i][j]: i~j之间(含i, j)变成回文词最少的插入数
int dp[maxn][maxn];

int dfs(int i, int j) {
    if(dp[i][j] != -1)
        return dp[i][j];
    // 递归边界
    if(i == j || i > j)
        return 0;
    if(A[i] == A[j])
        return dp[i][j] = dfs(i + 1, j - 1);
    else
        return dp[i][j] = std::min(dfs(i + 1, j), dfs(i, j - 1)) + 1;
}

int main() {
    scanf("%s", A + 1);
    std::memset(dp, -1, sizeof dp);
    printf("%d", dfs(1, strlen(A + 1)));
    return 0;
}
