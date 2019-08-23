//
// created by OFShare on 2019-08-24
//

#include <bits/stdc++.h>

const int maxn = 4e2 + 5;
int volume, weight, n;
int dp[maxn/8][maxn][maxn];

int main(){
    scanf("%d %d %d", &volume, &weight, &n);
    for(int i=1;i<=n;++i){
        int v,w,calorie;
        scanf("%d %d %d", &v, &w, &calorie);
        for(int j=0;j<=volume;++j){
            for(int k=0;k<=weight;++k){
                // 不选
                dp[i][j][k] = dp[i-1][j][k];
                // 选
                if(j-v >= 0 && k-w >= 0)
                    dp[i][j][k] = std::max(dp[i][j][k], dp[i-1][j-v][k-w] + calorie);
            }
        }
    }
    printf("%d\n", dp[n][volume][weight]);
    return 0;
}
