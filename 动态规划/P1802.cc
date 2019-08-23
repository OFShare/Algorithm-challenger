//
// created by OFShare on 2019-08-23
//

// https://www.luogu.org/problem/P1802
#include <bits/stdc++.h>

const int maxn = 1e3 + 5;
int n,x;
// dp[i][j]：前i个人，使用不超过j瓶药，所能获得的最大经验
long long dp[maxn][maxn];

int main(){
#ifdef OFShare
    std::freopen("datain.txt", "r", stdin);
    std::freopen("dataout.txt", "w", stdout);
#endif
    scanf("%d %d", &n,&x);
    for(int i=1;i<=n;++i){
        int lose, win, use;
        scanf("%d %d %d", &lose, &win, &use);
        for(int j=0;j<=x;++j){
            // 不和第i个人打
            dp[i][j] = dp[i-1][j];
            // 打:打的过，和打不过
            if(j-use>=0)
                dp[i][j] = std::max(dp[i][j], dp[i-1][j-use] + win);
            dp[i][j] = std::max(dp[i][j], dp[i-1][j] + lose);
        }
    }
    printf("%lld\n", dp[n][x] * 5);
    return 0;
}

