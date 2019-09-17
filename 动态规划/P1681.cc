//
// Created by OFShare on 2019-09-16
//

#include <bits/stdc++.h>

const int maxn = 2e3 + 5;
int n, m;
// dp[i][j][0]: 当在右下角坐标为(i, j)时，坐标(i, j)的值为0时能构成的最大交错正方形的边长
// dp[i][j][1]: 当在右下角坐标为(i, j)时，坐标(i, j)的值为1时能构成的最大交错正方形的边长
int dp[maxn][maxn][2];
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
            if(A[i][j] == 0) {
                dp[i][j][0] = 1;
                dp[i][j][1] = 0;
                if(i - 1 >= 1 && j - 1 >= 1)
                    dp[i][j][0] = std::min(dp[i - 1][j][1], std::min(dp[i][j - 1][1], dp[i -1][j -1][0])) + 1;
            } else if(A[i][j] == 1) {
                dp[i][j][0] = 0;
                dp[i][j][1] = 1;
                if(i - 1 >= 1 && j - 1 >= 1)
                    dp[i][j][1] = std::min(dp[i - 1][j][0], std::min(dp[i][j - 1][0], dp[i -1][j -1][1])) + 1;
            }
            ans = std::max(ans, dp[i][j][0]);
            ans = std::max(ans, dp[i][j][1]);
        }
    }
    printf("%d", ans);
    return 0;
}
