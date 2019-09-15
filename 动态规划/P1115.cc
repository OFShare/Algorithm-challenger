//
// Created by OFShare on 2019-09-15
//

#include <bits/stdc++.h>

int n;
const int maxn = 2e5 + 5;
// dp[i]: 前i个元素，且以第i个元素结尾的最大的连续子段和
long long dp[maxn];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        long long tmp;
        scanf("%lld", &tmp);
        // 第i个元素单独构成一段
        dp[i] = tmp;
        // 和前面的组合成一段
        dp[i] = std::max(dp[i], dp[i - 1] + tmp);
    }
    long long ans = -1e13;
    for(int i = 1; i <= n; ++i) {
        ans = std::max(ans, dp[i]);
    }
    printf("%lld\n", ans);
    return 0;
}
