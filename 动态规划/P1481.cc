//
// Created by OFShare on 2019-09-15
//

#include <bits/stdc++.h>

const int maxn = 2e3 + 5;
int n;
std::string A[maxn];
// dp[i]:前i个元素，且以第i个元素结尾的最长词链
int dp[maxn];

bool is_ok(int i, int j) {
    if(A[j].size() <= A[i].size()) {
        for(int k = 0; k < A[j].size(); ++k) {
            if(A[j][k] != A[i][k])
                return false;
        }
        return true;
    }
    return false;
}

int main() {
    std::cin >> n;
    for(int i = 1; i <= n; ++i) {
        std::cin >> A[i];
    }
    for(int i = 1; i <= n; ++i) {
        dp[i] = 1;
        for(int j = 1; j <= i - 1; ++j) {
            if(is_ok(i, j))
                dp[i] = std::max(dp[i], dp[j] + 1);
        }
    }
    int ans = -1;
    for(int i = 1; i <= n; ++i) {
        ans = std::max(ans, dp[i]);
    }
    std::cout << ans << std::endl;
    return 0;
}
