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
// dp[j]: 前i种债券, 装进不超过j的资产时，能获得的最大价值(即利息)。i被压缩掉了
int dp[maxm];

int main() {
    scanf("%d %d %d", &s, &n, &d);
    for(int i = 1; i <= d; ++i) {
        scanf("%d %d", &A[i].a, &A[i].b);
    }
    int max_money = s;
    // 每年都跑一次背包
    for(int k = 1; k <= n; ++k) {
        for(int i = 1; i <= d; ++i) {
            for(int j = 0; j <= max_money; ++j) {
                // 不选
                dp[j] = dp[j];
                // 选
                if (j - A[i].a >= 0)
                    dp[j] = std::max(dp[j], dp[j - A[i].a] + A[i].b);
            }
        }
        max_money += dp[max_money];
    }
    printf("%d", max_money);
    return 0;
}
