//
// created by OFShare on 2019-08-05
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

const int maxn = 50 + 10;
const int maxm = 200 + 10;
int n,T;

// t[i][j] 表示站台i到站台j需要的时间。
// t[i][j] 显然等于 t[j][i]
int t[maxn][maxn];

// has_train[i][j][0] 表示在第i站，j分钟时，是否有向左开动的车
// has_train[i][j][1] 表示在第i站，j分钟时，是否有向右开动的车
int has_train[maxn][maxm][2];

int dp[maxn][maxm];
int kase;

int main(){
#ifdef OFShare
    std::freopen("datain.txt", "r", stdin);
    std::freopen("dataout.txt", "w", stdout);
#endif
    while(scanf("%d",&n)&&n){
        scanf("%d",&T);
        for(int i=1;i<=n-1;++i){
            int tmp;
            scanf("%d",&tmp);
            t[i][i+1] = tmp;
            t[i+1][i] = tmp;
        }
        memset(has_train,0,sizeof has_train);
        memset(dp,0x3f3f3f,sizeof dp);
        // 有K辆车从车站1出发
        int K;
        scanf("%d",&K);
        for(int i=1;i<=K;++i){
            int tmp;
            scanf("%d",&tmp);
            int time_ = tmp;
            for(int j=1;j<=n;++j){
                has_train[j][time_][1] = 1;
                time_ += t[j][j+1];
            }
        }
        // 有K辆车从车站n出发
        scanf("%d",&K);
        for(int i=1;i<=K;++i){
            int tmp;
            scanf("%d",&tmp);
            int time_ = tmp;
            for(int j=n;j>=1;--j){
                has_train[j][time_][0] = 1;
                time_ += t[j][j-1];
            }
        }

        dp[n][T] = 0;
        // dp主过程
        //for(int i=n;i>=1;--i){
            //for(int j=T;j>=0;--j){
        for(int j=T;j>=0;--j){
            for(int i=n;i>=1;--i){
                // 不乘车
                if(j-1>=0)
                    //dp[i][j] = std::min(dp[i][j], dp[i][j+1]+1);
                    dp[i][j-1] = std::min(dp[i][j-1], dp[i][j]+1);
                // 乘车
                {
                    // 人在起点，看右方是否有车开过来
                    if(i==1){
                        if(j-t[i][i+1]>=0 && has_train[i+1][j-t[i][i+1]][0])
                            dp[i+1][j-t[i][i+1]] = std::min(dp[i+1][j-t[i][i+1]], dp[i][j]);
                    }
                    // 人在终点，看左方是否有车开过来
                    else if(i==n){
                        if(j-t[i][i-1]>=0 && has_train[i-1][j-t[i][i-1]][1])
                            dp[i-1][j-t[i][i-1]] = std::min(dp[i-1][j-t[i][i-1]], dp[i][j]);

                    }
                    else if(i>1 && i<n){
                        // 人在i站台,看右边是否有车开过来
                        if(j-t[i][i+1]>=0 && has_train[i+1][j-t[i][i+1]][0] )
                            dp[i+1][j-t[i][i+1]] = std::min(dp[i+1][j-t[i][i+1]], dp[i][j]);
                        // 人在i站台,看左边是否有车开过来
                        if(j-t[i][i-1]>=0 && has_train[i-1][j-t[i][i-1]][1] )
                            dp[i-1][j-t[i][i-1]] = std::min(dp[i-1][j-t[i][i-1]], dp[i][j]);
                    }

                }
            }
        }
        if(dp[1][0] >= 1e9)
            printf("Case Number %d: impossible\n",++kase );
        else
            printf("Case Number %d: %d\n",++kase, dp[1][0] );
    }
    return 0;
}
