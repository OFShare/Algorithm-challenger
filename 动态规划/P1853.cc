//
// Created by OFShare on 2019-09-18
//

#include <bits/stdc++.h>

const int maxn = 10 + 2;
const int maxm = 1e7 + 5;
int s, n, d;

struct node {
    int a, b;
}A[maxn];
// dp[i][j]: 前i种债券, 装进不超过j的资产时，能获得的最大价值(即利息)
int dp[2][maxm];

int main() {
    scanf("%d %d %d", &s, &n, &d);
    for(int i = 1; i <= d; ++i) {
        scanf("%d %d", &A[i].a, &A[i].b);
    }
    int max_money = s;
    // 每年都跑一次背包
    for(int k = 1; k <= n; ++k) {
        // 每次都要初始化
        std::memset(dp, 0, sizeof dp);
        for(int i = 1; i <= d; ++i) {
            for(int j = 0; j <= max_money; ++j) {
                // 不选
                dp[i & 1][j] = 0;
                dp[i & 1][j] = std::max(dp[i & 1][j], dp[(i -1) & 1][j]);
                // 选
                if (j - A[i].a >= 0)
                    dp[i & 1][j] = std::max(dp[i & 1][j], dp[i & 1][j - A[i].a] + A[i].b);
            }
        }
        max_money += dp[d & 1][max_money];
    }
    printf("%d", max_money);
    return 0;
}
