//
// Created by OFShare on 2019-09-17
//

#include <bits/stdc++.h>

const int maxn = 2e4 + 5;
int n, m;
// dp[i][j]: 前i个物品装进容量不超过j的背包时，能获得的最大价值
long long dp[maxn][2005];
// 记录dp更新到第几层了, 即第几个物品
int currentStage = 0;

long long func(long long A, long long B, long long x) {
    return A * x * x - B * x;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        int type;
        scanf("%d", &type);
        if(type == 1) {
            int A, B;
            scanf("%d %d", &A, &B);
            ++currentStage;
            for(int j = 0; j <= m; ++j) {
                // 不装
                dp[currentStage][j] = std::max(dp[currentStage][j], dp[currentStage - 1][j]);
                // 枚举甲物品的体积
                for(int k = 0; k <= j; ++k) {
                    if(j - k >= 0)
                        dp[currentStage][j] = std::max(dp[currentStage][j], dp[currentStage - 1][j - k] + func(A, B, k) );
                }
            }
        } else if(type == 2) {
            int A, B, C;
            scanf("%d %d %d", &A, &B, &C);
            // 多重背包, 拆分物品的思想
            std::vector<std::pair<int, int> > tmp;
            int k = 1;
            while(C >= k) {
                tmp.push_back({A * k, B * k});
                C -= k;
                k *= 2;
            }
            tmp.push_back({A * C, B * C});
            for(int k = 0; k < tmp.size(); ++k) {
                ++currentStage;
                for(int j = 0; j <= m; ++j) {
                    // 不装
                    dp[currentStage][j] = std::max(dp[currentStage][j], dp[currentStage - 1][j]);
                    // 装
                    if(j - tmp[k].second >= 0)
                        dp[currentStage][j] = std::max(dp[currentStage][j], dp[currentStage - 1][j - tmp[k].second] + tmp[k].first);
                }
            }
        } else if(type == 3) {
            int A, B;
            scanf("%d %d", &A, &B);
            // 完全背包
            ++currentStage;
            for(int j = 0; j <= m; ++j) {
                // 不装
                dp[currentStage][j] = std::max(dp[currentStage][j], dp[currentStage - 1][j]);
                // 装
                if(j - B >= 0)
                    dp[currentStage][j] = std::max(dp[currentStage][j], dp[currentStage][j - B] + A);
            }
        }
    }
    printf("%lld\n", dp[currentStage][m]);
    return 0;
}
