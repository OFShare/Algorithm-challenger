//
// created by OFShare on 2019-08-07
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

const int maxn = 1e3+10;
const int INF = 1e9;
int n;
int dp[maxn];

int main(){
    scanf("%d",&n);
    std::fill(dp+1,dp+1+n+2,INF);
    for(int i=1;i<=n;++i){
        int tmp;
        scanf("%d",&tmp);
        int pos = std::lower_bound(dp+1,dp+1+n,tmp) - dp;
        dp[pos] = tmp;
    }
    int number = std::lower_bound(dp+1,dp+1+n,INF) - dp - 1;
    printf("%d\n",number);
    return 0;
}

