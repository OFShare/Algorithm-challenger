//
// Created by OFShare on 2019-10-14
//

#include <bits/stdc++.h>

const int maxn = 2500 + 5;
int n, m;
int A[maxn][maxn];

// dp[i][j]: 右下角(或者左下角)坐标为(i, j)的最大答案(即猫猫一口下去可以吃掉的鱼的数量)的长度
int dp[maxn][maxn];
// up[i][j]: 坐标为(i, j)向上都为0的最大的长度
int up[maxn][maxn];
// left_right[i][j]: 向左(或者向右)都为0的最大长度
int left_right[maxn][maxn];

int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        // 第一遍考虑右下角的最大对角线长度
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                scanf("%d", &A[i][j]);
                if (A[i][j] == 1) {
                    // 初始化, 因为A[i][j] 等于1, 所以up[i][j], left[i][j]都为0
                    up[i][j] = left_right[i][j] = 0;
                    dp[i][j] = 1;

                    // 更新dp[i][j]
                    if (i - 1 >= 1 && j - 1 >= 1) {
                        int len = std::min(dp[i - 1][j - 1], up[i - 1][j]);
                        len = std::min(len, left_right[i][j - 1]);
                        dp[i][j] = len + 1;
                    }
                } else {
                    // 初始化
                    dp[i][j] = 0;
                    up[i][j] = left_right[i][j] = 1;

                    // 更新up[i][j]
                    if (i - 1 >= 1)
                        up[i][j] = up[i - 1][j] + 1;
                    // 更新left[i][j]
                    if (j - 1 >= 1)
                        left_right[i][j] = left_right[i][j - 1] + 1;
                }

                // 维护答案
                ans = std::max(ans, dp[i][j]);
            }
        }
        // 第二遍考虑左下角的最大对角线长度
        for (int i = 1; i <= n; ++i) {
            for (int j = m; j >= 1; --j) {
                if (A[i][j] == 1) {
                    // 初始化
                    dp[i][j] = 1;
                    left_right[i][j] = 0;
                    if (i - 1 >= 1 && j + 1 <= m)
                        dp[i][j] = std::min(dp[i - 1][j + 1], std::min(up[i - 1][j], left_right[i][j + 1])) + 1;
                } else {
                    // 初始化
                    left_right[i][j] = 1;
                    dp[i][j] = 0;
                    if (j + 1 <= m)
                        left_right[i][j] = left_right[i][j + 1] + 1;
                }
                // 维护答案
                ans = std::max(ans, dp[i][j]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
