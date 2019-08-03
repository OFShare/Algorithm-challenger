//
// created by OFShare on 2019-08-03
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

const int mod = 1e6;
const int maxn = 1e3+10;
const int maxm = 1e5+10;
int T,A,S,B;
int A_cnt[maxn];
int dp[maxn][maxm];

int main(){
    scanf("%d %d %d %d",&T,&A,&S,&B);
    for(int i=1;i<=A;++i){
        int type_;
        scanf("%d",&type_);
        A_cnt[type_]++;
    }
    // 初始化
    dp[0][0] = 1;
    for(int i=1;i<=T;++i){
        for(int j=0;j<=B;++j){
            if(j == 0){
                dp[i][j] = 1;
                continue;
            }
            if(j-1>=0&&A_cnt[i]<=j)
                dp[i][j] = (dp[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-A_cnt[i]-1] + mod) % mod;
            else if(j-1>=0)
                dp[i][j] = (dp[i][j] + dp[i-1][j] + dp[i][j-1]) % mod;
        }
    }
    int ans = 0;
    for(int i=S;i<=B;++i){
        ans = (ans+ dp[T][i]) % mod;
    }
    printf("%d\n",ans);
    return 0;
}
