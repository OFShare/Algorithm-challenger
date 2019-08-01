//
// created by OFShare on 2019-07-29
//

#include <iostream>
#include <cstdio>
#include <cmath>

const int maxn = 1000 + 10;
const int INF = -1e9;
int t,w;
int dp[maxn][maxn/20];

int main(){
    scanf("%d %d",&t,&w);
    for(int i=1;i<=t;++i){
        int treeNumber;
        scanf("%d",&treeNumber);
        treeNumber -= 1;
        for(int j=0;j<=w;++j){
            // 不动
            {
                if(treeNumber==j%2)
                    dp[i][j] = std::max(dp[i][j],dp[i-1][j] + 1);
                else
                    dp[i][j] = std::max(dp[i][j],dp[i-1][j]);
            }
            // 移动
            {
                if(treeNumber==j%2)
                    dp[i][j+1] = std::max(dp[i][j+1],dp[i-1][j]);
                else
                    dp[i][j+1] = std::max(dp[i][j+1],dp[i-1][j] + 1);
            }
        }
    }
    int ans = 0;
    for(int j=0;j<=w;++j){
        ans = std::max(ans,dp[t][j]);
    }
    printf("%d\n",ans);
    return 0;
}
