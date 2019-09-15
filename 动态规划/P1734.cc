//
// Created by OFShare on 2019-09-15
//

#include <bits/stdc++.h>

const int maxn = 1e3 + 5;
int S;
// sum[i]记录i的约数的和
int sum[maxn];
// dp[i][j]: 前i个物品装进不超过背包容量为j的能获得的最大的价值
int dp[maxn][maxn];

void precess() {
    for(int i = 1; i <= maxn; ++i) {
        sum[i] = 0;
        for(int j = 1; j <= std::sqrt(i); ++j) {
            if(i % j == 0) {
                if(j != i)
                    sum[i] += j;
                if(i / j != i && i / j != j)
                    sum[i] += i / j;
            }
        }
    }
}

int main() {
    scanf("%d", &S);
    precess();
    for(int i = 1; i <= S; ++i) {
        for(int j = 0; j <= S; ++j) {
            // 不装第i个物品
            dp[i][j] = dp[i - 1][j];
            // 装第i个物品
            if(j - i >= 0)
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - i] + sum[i]);
        }
    }
    printf("%d", dp[S][S]);
    return 0;
}
