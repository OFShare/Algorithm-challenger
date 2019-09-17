//
// Created by OFShare on 2019-09-16
//

#include <bits/stdc++.h>

const int maxn = 1e3 + 5;
int n, m;
// dp[i][j]: 当在右下角坐标为(i, j)时，不包含0时能构成的最大正方形的边长
int dp[maxn][maxn];
int A[maxn][maxn];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            scanf("%d", &A[i][j]);
        }
    }
    int ans = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            // 初始化
            dp[i][j] = 1;
            if(A[i][j] == 0) {
                dp[i][j] = 0;
                continue;
            }
            if(i - 1 >= 1 && j - 1 >= 1)
                dp[i][j] = std::min(dp[i - 1][j -1], std::min(dp[i][j - 1], dp[i - 1][j])) + 1;
            ans = std::max(ans, dp[i][j]);
        }
    }
    printf("%d", ans);
    return 0;
}
