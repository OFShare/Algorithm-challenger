//
// created by OFShare on 2019-08-07
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

const int maxn = 1e3+10;
int n;
int A[maxn],dp[maxn];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&A[i]);
    }
    // 初始化，以自己为结尾的话，至少长度为1
    std::fill(dp+1,dp+1+n,1);
    for(int i=1;i<=n;++i){
        for(int k=1;k<i;++k){
            if(A[k] < A[i])
                dp[i] = std::max(dp[i], dp[k] + 1);
        }
    }
    //auto it = std::max_element(dp+1,dp+1+n);
    int ans = 0;
    for(int i=1;i<=n;++i){
        ans = std::max(ans, dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}
