//
// created by OFShare on 2019-08-24
//

#include <bits/stdc++.h>

const int maxn = 1e3 + 5;
int n,A[maxn];
// dp[i]：以第i个元素结尾的最大和
long long dp[maxn];

int main(){
    while(scanf("%d",&n) && n){
        for(int i=1;i<=n;++i){
            scanf("%d", &A[i]);
        }
        for(int i=1;i<=n;++i){
            // 初始化
            dp[i] = A[i];
            for(int j=1;j<i;++j){
                if(A[j] < A[i])
                    dp[i] = std::max(dp[i], dp[j] + A[i]);
            }
        }
        long long ans = 0;
        for(int i=1;i<=n;++i){
            ans = std::max(ans, dp[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
