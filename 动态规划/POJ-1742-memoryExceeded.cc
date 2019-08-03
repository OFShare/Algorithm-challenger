//
// created by OFShare on 2019-08-03
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

const int maxn = 1e2+10;
const int maxm = 1e5+10;
int n,m;
int A[maxn],A_cnt[maxn];
int dp[maxn][maxm];

int main(){
    while(scanf("%d %d",&n,&m)&&(n+m)){
        for(int i=1;i<=n;++i){
            scanf("%d",&A[i]);
        }
        for(int i=1;i<=n;++i){
            scanf("%d",&A_cnt[i]);
        }
        // dp[0][0] =0
        // dp[0][1]，dp[0][2]，. . .，dp[0][m]都不能组成，所以赋值为-1
        std::fill(dp[0],dp[0]+m+1,-1);
        dp[0][0] = 0;
        for(int i=1;i<=n;++i){
            for(int j=0;j<=m;++j){
                // 前i-1种可以组成j，那么第i种，一个不用选，剩下就是本身有的个数
                if(dp[i-1][j]>=0)
                    dp[i][j] = A_cnt[i];
                // 第i种选一个
                else if((j-A[i]>=0)&&dp[i][j-A[i]]>=1)
                    dp[i][j] = dp[i][j-A[i]] - 1;
                // 其他情况,即前i种不能组成j赋为-1
                else
                    dp[i][j] = -1;
            }
        }
        int ans = 0;
        for(int j=1;j<=m;++j){
            if(dp[n][j]>=0)
                ++ans;
        }
        printf("%d\n",ans);
    }
    return 0;
}
