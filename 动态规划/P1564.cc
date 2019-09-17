//
// Created by OFShare on 2019-09-16
//

#include <bits/stdc++.h>

const int maxn = 3e3 + 5;
int n, m;
int A[maxn];
// dp[i]: 前i个同学最少需要的机房数
int dp[maxn];

// 判断j + 1 ~ i 是否可以放进一个机房里，条件是题目所说的
// 要么全是膜拜的一位神牛，或者膜拜人数差不超过m
bool is_ok(int i, int j) {
    int cnt1 = 0, cnt2 = 0;
    bool is_consecutive = true;
    for(int k = j + 1; k <= i; ++k) {
        if(A[k] == 1) ++cnt1;
        if(A[k] == 2) ++cnt2;
        if(k + 1 <= i && A[k] != A[k + 1]) is_consecutive = false;
    }
    if(std::abs(cnt1 - cnt2) <= m || is_consecutive)
        return true;
    else
        return false;
}

int main() {
    scanf("%d %d",&n, &m);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &A[i]);
    }
    for(int i = 1; i <= n; ++i) {
        // 初始化
        dp[i] = 1e9;
        for(int j = 0; j < i; ++j) {
            if(is_ok(i, j)) {
                dp[i] = std::min(dp[i], dp[j] + 1);
            }
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}
