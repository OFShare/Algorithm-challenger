//
// Created by OFShare on 2019-09-16
//

#include <bits/stdc++.h>

const int maxn = 3e3 + 5;
int n, m;
int A[maxn];
// dp[i]: 前i个同学最少需要的机房数
int dp[maxn];
// sum[i]: 记录前i个数的'差分前缀和'
int sum[maxn];

int main() {
    scanf("%d %d",&n, &m);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &A[i]);
        if(A[i] == 1) sum[i] = sum[i - 1] + 1;
        if(A[i] == 2) sum[i] = sum[i - 1] + -1;
    }
    for(int i = 1; i <= n; ++i) {
        // 初始化
        dp[i] = 1e9;
        for(int j = 0; j < i; ++j) {
            if((i - (j + 1) + 1) == std::abs(sum[i] - sum[j]) || std::abs(sum[i] - sum[j]) <= m) {
                dp[i] = std::min(dp[i], dp[j] + 1);
            }
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}
