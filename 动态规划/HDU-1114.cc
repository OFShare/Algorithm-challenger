//
// created by OFShare on 2019-08-24
//

#include <bits/stdc++.h>

const int INF = 1e9;
const int maxn = 1e4 + 5;
int T,E,F,n;
// dp[i][j]：前i个物品，恰好装进背包容量为j时，所能获得的最小价值
int dp[maxn/20][maxn];

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d", &E, &F, &n);
        // 初始化
        std::fill(dp[0], dp[0]+maxn-2, INF);
        dp[0][0] = 0;

        for(int i=1;i<=n;++i){
            int p,w;
            scanf("%d %d", &p, &w);
            for(int j=0;j<=F-E;++j){
                // 不选
                dp[i][j] = dp[i-1][j];
                // 选
                if(j-w >= 0)
                    dp[i][j] = std::min(dp[i][j], dp[i][j-w] + p);
            }
        }
        if(dp[n][F-E] >= INF)
            printf("This is impossible.\n");
        else
            printf("The minimum amount of money in the piggy-bank is %d.\n", dp[n][F-E]);
    }
    return 0;
}

