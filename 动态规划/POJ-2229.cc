//
// created by OFShare on 2019-07-29
//

#include <iostream>
#include <cstdio>
#include <cmath>

const int mod = 1e9;
const int maxn = 1e6 + 10;
int n;
int dp[maxn*2];

int main(){
    scanf("%d",&n);
    dp[1] = 1;
    for(int i=1;i<=n;++i){
        dp[i+1] = (dp[i+1] + dp[i]) % mod;
        dp[2*i] = (dp[2*i] + dp[i]) % mod;
    }
    printf("%d",dp[n]);
    return 0;
}
