//
// Created by OFShare on 2019-09-15
//

#include <bits/stdc++.h>

const int maxn = 1e3 + 5;
int n, A[maxn][maxn];
// sum_col[i][j]: 记录第i列前j个元素的前缀和
int sum_col[maxn][maxn];
// dp[i]: 前i个元素，且以第i个元素结尾的最大的连续子段和
int dp[maxn];

int max_segment(const std::vector<int> &vec) {
    assert(vec.size() == n + 1);
    int max_sum = -1e9;
    for(int i = 1; i <= n; ++i) {
        dp[i] = vec[i];
        dp[i] = std::max(dp[i], dp[i - 1] + vec[i]);
        max_sum = std::max(max_sum, dp[i]);
    }
    return max_sum;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            scanf("%d", &A[i][j]);
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            sum_col[i][j] = sum_col[i][j - 1] + A[j][i];
        }
    }

    // 枚举上下界
    int ans = -1e9;
    for(int i = 1; i <= n; ++i) {
        for(int j = i; j <= n; ++j) {
            std::vector<int> vec;
            vec.push_back(0);
            for(int k = 1; k <= n; ++k) {
                vec.push_back(sum_col[k][j] - sum_col[k][i - 1]);
            }
            ans = std::max(ans, max_segment(vec));
        }
    }
    printf("%d", ans);
    return 0;
}
