//
// created by OFShare on 2019-08-24
//

#include <bits/stdc++.h>

const int INF = 1e9;
const int maxn = 1e5 + 5;
int n;

// dp[i][j]：前i个时刻，在j位置时，所能接到的最多馅饼数
int dp[maxn][10+5];
// sum[i][j]：在i时刻，j位置，掉下的馅饼数
int sum[maxn][10+5];

int main(){
    while(scanf("%d", &n) && n){
        // 初始化
        memset(sum, 0, sizeof sum);
        for(int i=0;i<maxn-2;++i){
            std::fill(dp[i], dp[i] + 11, -INF);
        }
        dp[0][5] = 0;

        int max_time = 0;
        for(int i=1;i<=n;++i){
            int x,t;
            scanf("%d %d", &x,&t);
            sum[t][x]++;
            max_time = std::max(max_time, t);
        }
        for(int i=1;i<=max_time;++i){
            for(int j=0;j<=10;++j){
                // 不动
                dp[i][j] = dp[i-1][j] + sum[i][j];
                // 从左边过来
                if(j-1>=0)
                    dp[i][j] = std::max(dp[i][j], dp[i-1][j-1] + sum[i][j]);
                // 从右边过来
                if(j+1<=10)
                    dp[i][j] = std::max(dp[i][j], dp[i-1][j+1] + sum[i][j]);
            }
        }
        int ans = 0;
        for(int j=0;j<=10;++j){
            ans = std::max(ans, dp[max_time][j]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
