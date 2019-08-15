//
// created by OFShare on 2019-08-15
//

#include <bits/stdc++.h>

int T;
int n,t;
const int maxm = 1e5 + 5;
const int INF = 1e9;
// dp[i][j]: 前i个元素，恰好装进容量为j时，所能获得的最多元素个数
int dp[3][maxm];

int main(){
#ifdef OFShare
    std::freopen("datain.txt", "r", stdin);
    std::freopen("dataout.txt", "w", stdout);
#endif
    scanf("%d",&T);
    int kase = 0;
    while(T--){
        scanf("%d %d",&n,&t);
        t -= 1;
        for(int i=0;i<3;++i){
            for(int j=0;j<=t;++j){
                dp[i][j] = -INF;
            }
        }
        dp[0][0] = 0;
        for(int i=1;i<=n;++i){
            int tmp;
            scanf("%d",&tmp);
            for(int j=0;j<=t;++j){
                dp[i&1][j] = dp[(i-1)&1][j];
                if(j-tmp>=0)
                    dp[i&1][j] = std::max(dp[i&1][j], dp[(i-1)&1][j-tmp] + 1);
            }
        }
        int mx_element = 0, time = 0;
        // 当所有都不能选择时，就只能选择678这一首歌曲
        for(int j=t;j>=0;--j){
            if(dp[n&1][j] > mx_element)
                mx_element = dp[n&1][j],
                time = j;
        }
        printf("Case %d: %d %d\n", ++kase, mx_element+1, time+678);
    }
    return 0;
}
