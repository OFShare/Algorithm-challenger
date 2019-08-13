//
// created by OFShare on 2019-08-09
//
// https://www.luogu.org/problem/P2663

#include <bits/stdc++.h>

const int maxn = 1e2+10;
int n;
// 定义dp[i][j][k]为前i个数中，选取j个数，能否组成和为k
int dp[2][maxn][maxn*maxn/10];

int main(){
    scanf("%d",&n);
    int sum = 0;
    // 初始化
    dp[0&1][0][0] = 1;
    for(int i=1;i<=n;++i){
        int tmp;
        scanf("%d",&tmp);
        sum += tmp;
        for(int j=0;j<=i;++j){
            for(int k=0;k<=maxn*maxn-10;++k){
                // 不选
                if(i-1>=0)
                    dp[i&1][j][k] |= dp[(i-1)&1][j][k];
                // 选
                if(i-1>=0 && j-1>=0 && k-tmp>=0)
                    dp[i&1][j][k] |= dp[(i-1)&1][j-1][k-tmp];
            }
        }
    }
    int ans =0;
    for(int k=sum/2;k>=0;--k){
        if(dp[n&1][n/2][k]){
            ans = k;
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}
