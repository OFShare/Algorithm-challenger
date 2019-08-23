//
// created by OFShare on 2019-08-23
//

#include <bits/stdc++.h>

const int INF = 1e9;
const int maxn = 1e3 + 5;
int n;
int A[maxn];
// dp[i]：前i个元素，最优分成几组
int dp[maxn];

int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;++i){
        scanf("%d", &A[i]);
    }
    std::fill(dp, dp+n, -INF);
    // 初始化
    dp[0] = 0;
    for(int i=1;i<=n;++i){
        int sum = 0;
        for(int k=i;k>=1;--k){
            sum += A[k];
            if(sum >= 0)
                dp[i] = std::max(dp[i], dp[k-1] + 1);

        }
    }
    if(dp[n]>0)
        printf("%d\n",dp[n]);
    else
        printf("Impossible\n");
    return 0;
}
